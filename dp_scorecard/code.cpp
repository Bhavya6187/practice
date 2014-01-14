#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

void print(vector<int> a)
{
  for( vector<int>::const_iterator i = a.begin(); i != a.end(); ++i)
    cout << *i << ' ';
  cout<<endl;
}

bool isValid(int i,vector<int> a,int max)
{
  int lower = -1;
  while(find(a.begin(), a.end(), lower+1) != a.end())
    lower++;
  //printf("lower = %d\n",lower);
  if(i <= lower)
    return false;
  int upper = max;
  while(find(a.begin(), a.end(), upper-1)!= a.end())
    upper--;
  //printf("upper = %d\n",upper);
  if(i>=upper)
    return false;
  return true;

}

int get_num_scorecard(int m,int total,int max,vector<int> a)
{
  //printf("%d %d %d\n",m,total,max);
  if(total > max*m)
    return 0;
  if(total<0)
    return 0;
  if(m==0)
    return 1;
  if(total<0 )
    return 0;
  if(total < m-1)
    return 0;
  if(m==1 && total>=max )
    return 0;
  if(m==1 && total<max && isValid(total,a,max))
    return 1;
  if(m==1 && total<max && !isValid(total,a,max))
    return 0;
  int sum = 0;
  vector<int> v = a;
 
  for(int i=0; i < max && total- i >= m-2; i++)
  {
      if(isValid(i,a,max))
      {
        a.push_back(i);
        //printf("%d is valid\n",i);
        sum+=get_num_scorecard(m-1,total-i,max,a);
        //print(a);
        a=v;
      }
      else
      {
        //print(a);
        //printf("%d is not valid\n",i);
      }
  }
  return sum;
}
int main() {
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    
    vector<int> a;
    int _a_item;
    int max;
    int sum=0,total,m=0;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> max;
        sum = 0;
        m=0;
        a.clear();
        for(int i=0; i<max; i++) {
          cin >> _a_item;
          if(_a_item != -1)
          {
            sum+=_a_item;
            a.push_back(_a_item);
          }
          else
          { 
            m++;
          }
        }
        total = (max*(max-1))/2;
       // printf("%d %d %d\n",m,total-sum,max);
        printf("%d\n",get_num_scorecard(m,total-sum,max,a));
    }
    return 0;
}
