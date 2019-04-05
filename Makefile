cc = clang++
flags = -Wall -std=c++11 -g
opt = -O0
out = -o test

all: IntermittentComputing.o GeneralMultiplier.o ApproxMultiplier.o Common.o
	$(cc) IntermittentComputing.o GeneralMultiplier.o ApproxMultiplier.o Common.o $(out)

IntermittentComputing.o: IntermittentComputing.cpp Multiplier.hpp Common.hpp
	$(cc) -c IntermittentComputing.cpp $(flags) $(opt)

GeneralMultiplier.o: GeneralMultiplier.cpp Multiplier.hpp Common.hpp
	$(cc) -c GeneralMultiplier.cpp $(flags)

ApproxMultiplier.o: ApproxMultiplier.cpp Multiplier.hpp Common.hpp
	$(cc) -c ApproxMultiplier.cpp $(flags)

Common.o: Common.cpp Common.hpp
	$(cc) -c Common.cpp $(flags)

.PHONY: clean
clean:
	rm -Rf *.o test test.dSYM