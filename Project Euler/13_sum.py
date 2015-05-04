
def get_int_product(a):
	product = 1
	for i in range(len(a)):
		product = product*int(a[i])
	return product


with open ("large_number.txt", "r") as myfile:
    data=myfile.read().replace('\n', '')

maxim = 0;
for i in range(len(data)-13):
	substr = data[i:i+13]
	if '0' not in substr:
		temp = get_int_product(substr)	
		if(temp > maxim):
			maxim = temp;
			print substr
			print maxim
