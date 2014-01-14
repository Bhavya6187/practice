k=input()
for i in range(k):
  x=float(input())-1
  y=0;
  while x>=0:
    y+=pow(-1,x)/(2*x+1)
    x=x-1
  print '{0:.15f}'.format(y)
