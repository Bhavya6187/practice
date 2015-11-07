def is_pandigital(a):
	main_str = "";
	maxim = 0;
	for i in range(1,9):
		main_str = main_str + str(i*a);
		if(len(main_str) == 9):
			if(sorted(main_str) == ['1','2','3','4','5','6','7','8','9'] and int(main_str) > maxim):
				maxim = int(main_str)
				print maxim,a


for i in range(6,49999):
	is_pandigital(i)