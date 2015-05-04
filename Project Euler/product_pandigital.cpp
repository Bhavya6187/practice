#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <set>


using namespace std;

set<int> nums;
void swap (char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}


void permute(char *a, int i, int n) 
{
	int j; 
	int x,y,z;
   	if (i == n){
   		string str(a);
   		string str1,str2,str3;
   		for(j = 1; j <= 7; j++){
   			for(int k = 1; k < 8-j; k++){
   				str1 = str.substr(0, j);
   				str2 = str.substr(j, k);
   				str3 = str.substr(j+k);
   				x = atoi(str1.c_str());
   				y = atoi(str2.c_str());
   				z = atoi(str3.c_str());

   				if(x*y == z){
   					//cout << x << "*" << y << " = " << z << endl;
   					nums.insert(z);
   					/*cout << str << endl;
   					cout << str1 << endl;
   					cout << str2 << endl;
   					cout << str3 << endl;*/
   				}
   			}
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

	int sum = 0;
	char src[] = "123456789";
	permute(src,0,8);
	set<int>::iterator it;
	for (it=nums.begin(); it!=nums.end(); ++it){
    	cout << ' ' << *it;
    	sum += *it;
    }
    cout << endl << sum;

}