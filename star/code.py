from copy import copy, deepcopy
def check_constraints(a):
  l1 = [a[0],a[1],a[2],a[3]]
  l2 = [a[3],a[4],a[5],a[6]]
  l3 = [a[6],a[7],a[8],a[0]]
  l4 = [a[9],a[1],a[8],a[11]]
  l5 = [a[9],a[2],a[4],a[10]]
  l6 = [a[10],a[5],a[7],a[11]]
  l = [l1,l2,l3,l4,l5,l6]
  for line in l:
    if(sum(line)!=26 and (0 not in line)):
      return False
    if( sum(line)>=26 and (0 in line) ):
      return False
  return True

def find_next(b):
  a = b[:]
  index = 0;
  for val in a:
    if(val != 0):
      index+=1;
  print a
  print index
  if(index == 12):
    return -1,-1
  for i in range(1,13):
    if(i not in a):
      a = b[:]
      a[index] = i
      if(check_constraints(a) == True):
        return index,i

def solve(a):
  index = 0
  for val in a:
    if(val != 0):
      index+=1
    else:
      break

  print a,index
  if(0 not in a):
    if(check_constraints(a)):
      return a
    else:
      #print "false"
      return False
  
  for i in range(1,13):
    if(i not in a):
      print i
      b = a[:]
      b[index]=i;
      if(check_constraints(b) == True):
        retval = solve(b)
        if(retval != False ):
          return retval
  return False

a = [0]*12
a = solve(a)
print a
