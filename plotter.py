import matplotlib.pyplot as plt

l1 = []
l2 = []

with open('output1.txt', 'r') as f:
    l1 = [int(x) for x in f.readline().split(', ')]

with open('output2.txt', 'r') as f:
    l2 = [int(x) for x in f.readline().split(', ')]

x = 1
size = int(x * len(l1))
l1 = l1[:size]
l2 = l2[:size]

error = [0] * len(l1)
i = 0
for x,y in zip(l1, l2):
    error[i] = (x-y)/x
    i += 1

plt.title("SRAM multiplication results. Avg. error: {0}".format(sum(error)/i))
line1, = plt.plot(l1)
line2, = plt.plot(l2)
plt.legend((line1, line2), ('General multiplier', 'Approximate multiplier'))
plt.show()