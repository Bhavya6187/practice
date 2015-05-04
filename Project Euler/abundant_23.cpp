#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

using namespace std;

bool myfunction (int i,int j) { return (i<j); }
int main()
{

	std::vector<int> ab;
	for(int i = 12; i < 28123; i++){
		int sum = 0;
		for(int j = 1; j <= i/2 ; j++){
			if(i%j == 0){
				sum +=j;
			}
		}
		if(sum > i)
			ab.push_back(i);
			//cout << i << "   is abundant" << endl;
	}

	int count = ab.end() - ab.begin();
	int sum = 276;

	for(int i = 24; i <= 28123; i++){
		bool valid = true;
		if(i%2 == 0 && binary_search(ab.begin(),ab.end(),i/2,myfunction))
			continue;
		else
		{
			for(int j = 0; j < count && ab[j] < i; j++)
			{
				if(binary_search(ab.begin(),ab.end(),i - ab[j],myfunction))
				{
					valid = false; 
					break;
				}
			}
			if(valid)
				sum += i;
		}
	}

	cout << sum << endl;
}