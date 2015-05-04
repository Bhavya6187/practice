#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdlib>
#include <set>

using namespace std;

int maxim = 0;
vector<int> pv;

int main(){
int count[7] = {};
int count1[7] = {1,0,0,0,0,0,0};
for(int i = 0; i < 7 ; i++){
	int curr = i;
	for(int j = 1901 ; j<=2000; j++ ){
		if(curr == 0)
			count[i]++;
		if(j % 4 == 0)
			curr+=2;
		else
			curr++;
		curr%=7;
	}
}

for(int i = 0; i < 7 ; i++){
	int curr = i;
	for(int j = 1902 ; j<=2000; j++ ){
		if((j-1) % 4 == 0)
			curr+=2;
		else
			curr++;
		curr%=7;
		if(curr == 0)
			count1[i]++;

	}
}

string days[] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
for(int i = 0; i < 7 ; i++)
	cout << days[i] << " - " << count[i] << endl;
cout <<endl;
for(int i = 0; i < 7 ; i++)
	cout << days[i] << " - " << count1[i] << endl;
}