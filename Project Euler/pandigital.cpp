#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

int maxim = 0;
vector<int> pv;
bool myfunction (int i,int j) { return (i<j); }

void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

bool is_prime(int a){
	
	if(binary_search(pv.begin(),pv.end(),a,myfunction)){
		return true;
	}

	int limit = int(sqrt(a));

	for (vector<int>::iterator i = pv.begin(); i != pv.end(); ++i ){
		int curr = *i;
		if(curr > limit)
			return true;
		if(a%curr == 0)
			return false;
	}
	return true;
}

void permute(char *a, int i, int n) 
{
   int j; 
   if (i == n){

   	 int curr = atoi(a);
     if(is_prime(curr) && curr > maxim){
     	maxim = curr;
     	cout << maxim << endl;
     }
 }
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}

int main(){

	pv.push_back(2);
	int count = 1;
	for(long long int i = 3; i < 32000; i+=2)
	{
		bool is_prime = true;
		for(int j = 0; j < count; j++){
			if(i%pv[j] == 0){
				is_prime = false;
				break;
			}
		}
		if(is_prime){
			pv.push_back(i);
			count++;
		}
	}

	char src[] = "12345";
	permute(src,0,4);
	char src2[] = "123456";
	permute(src2,0,5);
	char src3[] = "1234567";
	permute(src3,0,6);
	char src4[] = "12345678";
	permute(src4,0,7);
	char src5[] = "123456789";
	permute(src5,0,8);

}