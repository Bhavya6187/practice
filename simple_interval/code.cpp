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
typedef int (*compfn)(const void*, const void*);

struct interval {
    int start;
    int end;
    bool mark;
};

int compare(interval *elem1, interval *elem2)
{
     if ( elem1->end < elem2->end)
             return -1;
     else if (elem1->end > elem2->end)
                return 1;
       else
         return 0;
};

int get_count(interval* a,int a_size,int k )
{
  int i = 0;
  int retval = 0;
  while(a[i].end <= k )
  {
    i++;
  }
  while(a[i].end >= k && i<a_size )
  {
    if(a[i].start <= k && a[i].mark == false )
    {
      a[i].mark = true;
  //    printf("for k = %d, we have start = %d and end = %d\n",k,a[i].start,a[i].end);
      retval++;
    }
    i++;
  }
  return retval;
}

int main(int argc, char *argv[]) {
    int res;
    
    int a_size;
    cin >> a_size;

    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    interval a[a_size];
    for(int i=0; i<a_size; i++) {
        scanf("%d %d",&a[i].start,&a[i].end );
        a[i].mark = false;
    }
    qsort((void *) &a, a_size, sizeof(interval), (compfn)compare );
    
    /*for(int i=0; i<a_size; i++) {
        printf("%d %d\n",a[i].start,a[i].end );
    }*/
   
    int q;
    cin >> q;
    int k_size;
    int k[20];
    int count = 0;

    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    for(int i=0; i<q; i++) {
        scanf("%d",&k_size);
        for(int i=0; i<k_size; i++) {
            scanf("%d",&k[i]);
        }

        for(int i=0; i<k_size; i++) {
            count += get_count(a,a_size,k[i]);
        }
        printf("%d\n",count);

        for(int i=0; i<a_size; i++) {
          a[i].mark = false;
        }
        count  = 0;
    }
    
    return 0;
}
