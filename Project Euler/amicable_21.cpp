#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

int get_amicable(int i){

	int sum = 0;
	for(int j = 1; j <= i/2 ; j++){
		if(i%j == 0){
			sum +=j;
		}
	}
	return sum;
}
int main()
{

	set<int> am;
	int sum = 0;
	for(int i = 12; i < 10000; i++){
		int a = get_amicable(i);
		if(get_amicable(a) == i && a!=i){
			cout << "Numbers " << a << "   " << i << "are amicable" << endl;
			am.insert(a);
			am.insert(i);
		}
	}

	set<int>::iterator it;
	for (it=am.begin(); it!=am.end(); ++it){
    	cout << ' ' << *it;
    	sum += *it;
    }

	cout << endl<<sum << endl;
}