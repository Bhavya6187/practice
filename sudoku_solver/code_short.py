from copy import deepcopy
def r(a):
  change = True
  while change:
    change = False
    for i in range(9):
        for j in range(9):
          if(len(a[i][j])>1):
            x,y=3*(i/3),3*(j/3)
            vals=a[i][:]+[row[j] for row in a]+[a[x][y],a[x+1][y],a[x+2][y],a[x][y+1],a[x+1][y+1],a[x+2][y+1],a[x][y+2],a[x+1][y+2],a[x+2][y+2]]
            vals[:]=(value for value in vals if len(value)==1)
            for value in vals:
              if(value[0] in a[i][j]):
                change=True
                a[i][j].remove(value[0])

def f(a):
  for i in range(9):
    j = 0
    col=[row[i] for row in a]
    row = a[i][:]
    x,y=3*(i/3),3*(i%3)
    box = [a[x][y],a[x][y+1],a[x][y+2],a[x+1][y],a[x+1][y+1],a[x+1][y+2],a[x+2][y],a[x+2][y+1],a[x+2][y+2]]
    freq=[0]*10
    for elems in row:
      if(len(elems)>1):
        for elem in elems:
          freq[elem]+=1
    if( 1 in freq):
      index = freq.index(1)
      for elems in row:
          if index in elems:
            a[i][j]=[index];
            r(a)
            return True;
          j=j+1;
    freq=[0]*10
    for elems in col:
      if(len(elems)>1):
        for elem in elems:
          freq[elem]+=1
    if( 1 in freq):
      index = freq.index(1)
      for elems in col:
          if index in elems:
            a[j][i]=[index];
            r(a)
            return True;
          j=j+1;
    freq=[0]*10
    for elems in box:
      if(len(elems)>1):
        for elem in elems:
          freq[elem]+=1
    if( 1 in freq):
      index = freq.index(1)
      for elems in box:
        if index in elems:
           a[x+(j/3)][y+(j%3)]=[index];
           r(a)
           return True;
        j=j+1;
  return False

def clean(g):
  r(g)
  for i in range(9):
    for j in range(9):
      if(len(g[i][j])==0):
         return False
  while True:
    if(f(g) == False):
      break
    for i in range(9):
      for j in range(9):
        if(len(g[i][j])==0):
           return False
  return g

def s(g):

  if all(len(g[i/9][i%9]) == 1 for i in range(81)):
    return g

  n,i = min( (len(g[i/9][i%9]),i) for i in range(81) if len(g[i/9][i%9]) > 1)
  seq = list();
  elems = g[i/9][i%9]
  t_g=[];
  new=[];
  for d in elems:
    t_g=deepcopy(g);
    t_g[i/9][i%9]=[d]
    if( clean(t_g) != False):
      x = s(t_g)
      if(x):
        return x
    else:
      seq.append(False)
 
  return False;

n = input()
for t in range(n):
    a = []
    for j in range(9):
        a.append([int(k) for k in raw_input().split()])
    for k in range(9):
        for l in range(9):
          if a[k][l]==0:
            a[k][l]=[1,2,3,4,5,6,7,8,9]
          else:
            a[k][l]=[a[k][l]]
    clean(a)
    a = s(a)
    for i in range(9):
      print a[i][0][0],a[i][1][0],a[i][2][0],a[i][3][0],a[i][4][0],a[i][5][0],a[i][6][0],a[i][7][0],a[i][8][0]
