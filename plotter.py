import matplotlib.pyplot as plt

l1 = []
l2 = []
l3 = []

with open('output_GM_SRAM.txt', 'r') as f:
    l1 = [int(x) for x in f.readline().split(', ')]

with open('output_AM_SRAM.txt', 'r') as f:
    l2 = [int(x) for x in f.readline().split(', ')]

with open('output_AM_ReRAM.txt', 'r') as f:
    l3 = [int(x) for x in f.readline().split(', ')]

x = 1
size = int(x * len(l1))
l1 = l1[:size]
l2 = l2[:size]
l3 = l3[:size]

error = [0] * len(l1)
i = 0
for x,y in zip(l1, l2):
    error[i] = (x-y)/x
    i += 1

error1 = [0] * len(l1)
j = 0
for x,y in zip(l1, l3):
    error1[j] = (x-y)/x
    j += 1

plt.title("SRAM multiplication results. Avg. error: {0}(SRAM), {1}(ReRAM)".format(sum(error)/i, sum(error1)/j))
line1, = plt.plot(l1)
line2, = plt.plot(l2)
line3, = plt.plot(l3)
plt.legend((line1, line2, line3), ('General multiplier', 'Approximate multiplier (SRAM)', 'Approximate multiplier (ReRAM)'))
plt.show()