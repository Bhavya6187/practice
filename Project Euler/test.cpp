#include <string>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
	int total = 0;
	int powers[10] = {0,1,32,243,1024,3125,7776,16807,32768,59049};
	for(int i = 10; i < 354294; i++){
		int curr = i;
		int sum = 0;
		while(curr > 0){
			sum += powers[curr%10];
			curr/=10;
		}

		if(sum == i)
			total += i;
	}
	cout << total << endl
}