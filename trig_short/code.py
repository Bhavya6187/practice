k=input()
for i in range(k):
  x=float(input())
  print round(x-pow(x,3)/6+pow(x,5)/120-pow(x,7)/5040+pow(x,9)/362880,3)
  print round(1-pow(x,2)/2+pow(x,4)/24-pow(x,6)/720+pow(x,8)/40320,3)
