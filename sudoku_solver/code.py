#!/bin/python
from copy import copy, deepcopy
# Head ends here
def remove_possibilities(a):
  change = True
  while change:
    change = False
    for i in range(9):
        for j in range(9):
          if(len(a[i][j])>1):
            x,y=3*(i/3),3*(j/3)
            vals=a[i][:]+[row[j] for row in a]+[a[x][y],a[x+1][y],a[x+2][y],a[x][y+1],a[x+1][y+1],a[x+2][y+1],a[x][y+2],a[x+1][y+2],a[x+2][y+2]]
            #print "the main grid is"
            #print a
            #print "vals is"
            #print vals
            vals[:]=(value for value in vals if len(value)==1)
            for value in vals:
              if(value[0] in a[i][j]):
                change=True
                a[i][j].remove(value[0])

def find_singleton(a):
  #print "input to singleton is"
  #print a
  for i in range(9):
    j = 0
    row = a[i][:]
    col=[row[i] for row in a]
    row = a[i][:]
    x,y=3*(i/3),3*(i%3)
    box = [a[x][y],a[x][y+1],a[x][y+2],a[x+1][y],a[x+1][y+1],a[x+1][y+2],a[x+2][y],a[x+2][y+1],a[x+2][y+2]]
    freq=[0,0,0,0,0,0,0,0,0,0]
    for elems in row:
      if(len(elems)>1):
        for elem in elems:
          freq[elem]+=1
    if( 1 in freq):
      index = freq.index(1)
      for elems in row:
          if index in elems:
            a[i][j]=[index];
            #print "singleton in row ",i, "with value ", index,j, row
            remove_possibilities(a)
            return True;
          j=j+1;
    freq=[0,0,0,0,0,0,0,0,0,0]
    for elems in col:
      if(len(elems)>1):
        for elem in elems:
          freq[elem]+=1
    if( 1 in freq):
      index = freq.index(1)
      for elems in col:
          if index in elems:
            a[j][i]=[index];
            #print "singleton in col ",i, "with value ", index,j,col
            remove_possibilities(a)
            return True;
          j=j+1;
    freq=[0,0,0,0,0,0,0,0,0,0]
    for elems in box:
      if(len(elems)>1):
        for elem in elems:
          freq[elem]+=1
    if( 1 in freq):
      index = freq.index(1)
      for elems in box:
        if index in elems:
           a[x+(j/3)][y+(j%3)]=[index];
           #print "singleton in box ",i, "with value ", index,j, box
           remove_possibilities(a)
           return True;
        j=j+1;
  return False

def clean(grid):
  
  remove_possibilities(grid)
  
  for i in range(9):
    for j in range(9):
      if(len(grid[i][j])==0):
         #print "a contradiction found in upper one ",i,j, grid[i][j]
         return False
  while True:
    if(find_singleton(grid) == False):
      break
    for i in range(9):
      for j in range(9):
        if(len(grid[i][j])==0):
           #print "a contradiction found in lower ones"
           return False
  return grid

def sudoku_solve(grid):

  if all(len(grid[i/9][i%9]) == 1 for i in range(81)):
    #print "Solved it"
    #print grid
    return grid

  n,i = min( (len(grid[i/9][i%9]),i) for i in range(81) if len(grid[i/9][i%9]) > 1)
  #print grid
  #print n,i,grid[i/9][i%9]

  seq = list();
  elems = grid[i/9][i%9]
  temp_grid=[];
  new=[];
  for d in elems:
    temp_grid=deepcopy(grid);
    #print "assigning ",d," to ",i, "for grid"
    #print grid
    #print "temp_grid = "
    temp_grid[i/9][i%9]=[d]
    #print temp_grid
    if( clean(temp_grid) != False):
      x = sudoku_solve(temp_grid)
      if(x):
        return x
      #seq.append(sudoku_solve(temp_grid))
    else:
      seq.append(False)
      #print "grid is false while assigning ",d," to ",i
 
  #print "seq for ",n,i,elems, grid[i/9][i%9]," is ", seq
  for e in seq:
    if e: 
      print "e is "
      print e
      return e
  return False;

# Tail starts here
n = input()

for temp in range(n):
    board = []
    for j in range(9):
        board.append([int(k) for k in raw_input().split()])
    for k in range(9):
        for l in range(9):
          if board[k][l]==0:
            board[k][l]=[1,2,3,4,5,6,7,8,9]
          else:
            board[k][l]=[board[k][l]]
    clean(board)
    board = sudoku_solve(board)
    for i in range(9):
      print board[i][0][0],board[i][1][0],board[i][2][0],board[i][3][0],board[i][4][0],board[i][5][0],board[i][6][0],board[i][7][0],board[i][8][0]
