import numpy as np
import matplotlib.pyplot as plt
import itertools

M = 23;

def binary_exp(b: int, e: int) -> int:
	if e == 0:
		return 1
	elif e == 1:
		return b
	elif e%2 == 1:
		return (b*binary_exp(b,e-1))%M
	else:
		x = binary_exp(b,e/2)
		return (x*x)%M

def inv(x: int) -> int:
	return binary_exp(x, M-2)

if __name__ == "__main__":
	table = np.zeros((M, M), dtype=np.int64)
	lst = np.arange(1, 24)
	for (i, j) in itertools.product(lst, lst):
		table[i-1][j-1] = (int)(i * inv(j))

	fig, ax = plt.subplots()
	ax.axis('off')
	table = ax.table(cellText = table, colLabels=lst, rowLabels=lst, loc='center', fontsize=24)
	table.auto_set_font_size(False)
	table.set_fontsize(15)

	plt.show()
