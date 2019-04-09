import matplotlib.pyplot as plt

l1 = []
l2 = []
l3 = []
l4 = []

with open('output_GM_SRAM.txt', 'r') as f:
    l1 = [int(x) for x in f.readline().split(', ')]

with open('output_GM_ReRAM.txt', 'r') as f:
    l2 = [int(x) for x in f.readline().split(', ')]

with open('output_AM_SRAM.txt', 'r') as f:
    l3 = [int(x) for x in f.readline().split(', ')]

with open('output_AM_ReRAM.txt', 'r') as f:
    l4 = [int(x) for x in f.readline().split(', ')]

x = 1
size = int(x * len(l1))
l1 = l1[:size]
l2 = l2[:size]
l3 = l3[:size]
l4 = l4[:size]

error = [0] * len(l1)
i = 0
for x,y in zip(l1, l3):
    error[i] = (x-y)/x
    i += 1

error1 = [0] * len(l1)
j = 0
for x,y in zip(l2, l4):
    error1[j] = (x-y)/x
    j += 1

plt.title("SRAM multiplication results. Avg. error: {0}".format(sum(error)/i))
line1, = plt.plot(l1)
line2, = plt.plot(l3)
plt.legend((line1, line2), ('General multiplier', 'Approximate multiplier'))
plt.show()

plt.figure()
plt.title("ReRAM multiplication results. Avg. error: {0}".format(sum(error1)/j))
line3, = plt.plot(l2)
line4, = plt.plot(l4)
plt.legend((line3, line4), ('General multiplier', 'Approximate multiplier'))
plt.show()

plt.figure()
plt.title('Comparison of operations completed based on different memory types.')
line5, = plt.plot(l3)
line6, = plt.plot(l4)
plt.legend((line5, line6), ('Approximate multiplier(SRAM)', 'Approximate multiplier(ReRAM)'))
plt.show()

operations = 0

for x,y in zip(l3,l4):
    if x != 0 and y != 0 and int(x/y) != 0:
        operations += 1

print(operations)