global types
types = [0]*201
types[0] = 0
types[1] = 1
coins = [1,2,5,10,20,50,100,200];
def get_types(a, count):
	if(a < 0):
		return 0;
	if(a == 0):
		return 1;
	if(count< 0):
		return 0;
	return get_types(a, count-1) + get_types(a-coins[count], count)

print get_types(200, 7)