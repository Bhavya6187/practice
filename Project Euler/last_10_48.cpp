#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int main()
{

long long int sum = 0;

long long int mod = 10000000000;
for(long long int i = 1; i <= 1000 ; i++){
	long long int temp = 1;
	for(long long int j = 1; j <=i; j++){
		temp *=i;
		temp %= mod;
	}
	sum +=temp;
}

cout << sum%mod;

}