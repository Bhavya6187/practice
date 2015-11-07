i = 0
numbers = []
maxim = []
with open ("67_data", "r") as f:
	for l in f:
		l2 = l.replace("\n","")
		temp = map(int, l2.split())
		numbers.append(temp)
		maxim.append([0]*len(temp))
maxim[0][0] = numbers[0][0]
for i in range(1,len(numbers)):
	for j in range(0,len(numbers[i])):
		n1 = 0;
		n2 = 0;
		if j - 1 >= 0:
			n1 = maxim[i-1][j-1] + numbers[i][j]
		if j < len(maxim[i-1]):
			n2 = maxim[i-1][j] + numbers[i][j]
		maxim[i][j] = max(n1,n2)

print max(maxim[len(maxim)-1])