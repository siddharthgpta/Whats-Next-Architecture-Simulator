#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <thread>
#include <cstdlib>
#include "Multiplier.hpp"

using namespace std;

const Memory ReRAM{1000, 1500};
const Memory SRAM{7000, 1500};

const int number_of_multiplications = 100;
bool started = false;
bool incomplete = true;

void print(ostream &os, vector<unsigned long long> &vec) {
    stringstream ss;
    for(auto x : vec) {
        ss << x << ", ";
    }
    ss.seekp(-2, ios_base::cur);
    ss << "\n\0";
    os << ss.str();
}

vector<unsigned int> generate_subword_vector(unsigned int x) {
    vector<unsigned int> subword{4};
    unsigned int mask = 0xff << (sizeof(unsigned int)-1)*8;
    for(size_t i = 0; i < sizeof(unsigned int); ++i) {
        subword.push_back(x & mask);
        mask = mask >> 8;
    }

    return subword;
}

void mult8_approx(const vector<vector<unsigned int>> &multipliers, const vector<unsigned int> &multiplicants, vector<unsigned long long> &result, bool &incomplete) {
    
}

int main(int argc, char *argv[]) {
    // get time ratio for simulation
    float time_ratio = atof(argv[1]);

    // random number generator
    random_device rd;
    mt19937_64 generator{rd()};
    uniform_int_distribution<unsigned int> distribution{1000, 1000000};

    // variables to store data
    vector<unsigned int> multipliers{number_of_multiplications};
    vector<unsigned int> multiplicants{number_of_multiplications};
    vector<vector<unsigned int>> vectorized_multipliers{number_of_multiplications};
    vector<unsigned long long> result(number_of_multiplications, 0);
    vector<unsigned long long> time_based_result(number_of_multiplications, 0);
    timeval time_taken;

    // generate random multipliers
    for(size_t i = 0; i < number_of_multiplications; ++i) {
        multipliers.push_back(distribution(generator));
    }

    // generate random multiplicants
    for(size_t i = 0; i < number_of_multiplications; ++i) {
        multiplicants.push_back(distribution(generator));
    }

    //vectorize multiplicants
    transform(multipliers.begin(), multipliers.end(), vectorized_multipliers.begin(), generate_subword_vector);

    // normal multiplication of values based on M0+ microcontrollers
    GeneralMultiplier gm(SRAM);
    time_taken = gm(vectorized_multipliers, multiplicants, result);
    ofstream out1("output1.txt");
    print(out1, result);
    out1.close();

    cout << time_taken.tv_sec << "." << time_taken.tv_usec << '\n';

    // multiplication using What's Next pipeline;
    ApproxMultiplier am(SRAM);
    thread t1(&ApproxMultiplier::operator(), &am, std::ref(vectorized_multipliers), std::ref(multiplicants), std::ref(time_based_result));

    // sleep till half time
    while(!started);
    sleep(time_taken.tv_sec * time_ratio);
    usleep(time_taken.tv_usec * time_ratio);
    incomplete = false;

    //wait for thread to join
    t1.join();

    ofstream out2("output2.txt");
    print(out2, time_based_result);
    out2.close();

    pid_t proc_id;
    if ((proc_id = fork()) == 0) {
        execl("/usr/local/bin/python3", "python3", "./plotter.py", (char*)nullptr);
        cerr << "execl failed!\n";
    }
    
    wait(&proc_id);
    return 0;
}