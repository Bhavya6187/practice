#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	int maxim = 0;
	for(int i = 2; i < 1000 ; i++){
		vector<int> nums;
		int num = 1;
		while(num < i)
			num *=10;
		int rem = num%i;
		nums.push_back(rem);
		while(rem != 0){
			rem*=10;
			rem = rem%i;
			vector<int>::iterator it = find(nums.begin(), nums.end(), rem);
			if(it!=nums.end()){
				int pos = (int)(nums.end()-it);
				if(pos > maxim){
					maxim = pos;
					cout << i << " - " << pos << endl;
				}
				break;
			}
			nums.push_back(rem);
		}

/*		cout << i << "  -  ";
		for (vector<int>::iterator it=nums.begin(); it!=nums.end(); ++it){
	    	cout << ' ' << *it;
	    }
	    cout << endl;*/
	}

}
