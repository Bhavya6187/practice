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
/* Head ends here */
int sieve[20000];
int ways(int a) {
  if(a==1)
    return 1;
  if(a==2)
    return 1;
  if(a==3)
    return 1;
  if(a==4)
    return 2;
  return ways(a-1)+ways(a-4);
}
bool check_prime(int a,int j)
{
  int root = (int)sqrt(a);
  for(int i = 0; i < j; i++)
  {
    if(a%sieve[i] == 0)
      return false;
    if(sieve[i] > root)
      return true;
  }
  return true;

}
void make_sieve()
{
  int j = 2;
  sieve[0] =2;
  sieve[1]=3;
  for(int i = 5; i< 220000;i++ )
  {
    if(check_prime(i,j))
    {
      sieve[j] = i;
      j++;
    }

  }
}

int get_prime_count(int a)
{
  int i = 0;
  while(sieve[i] <= a)
  {
    i++;
  }
  return i;
}
/* Tail starts here */
int main() {
    make_sieve();
    int res;
    
    int _a_size;
    cin >> _a_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    int _a_item;
    for(int _a_i=0; _a_i<_a_size; _a_i++) {
        cin >> _a_item;
        res = ways(_a_item);
        cout << get_prime_count(res)<<endl;
    }
    
    
    return 0;
}
