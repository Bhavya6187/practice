#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n = 20;
vector< vector<long long int> > grid;

int main(){
	
	for(int i = 0; i <= n ; i++){
		vector<long long int> temp;
		for(int j = 0; j <= n ; j++){
			temp.push_back(0);
		}
		grid.push_back(temp);
	}


	for(int i = n; i >= 0 ; i--){
		for(int j = n; j >= 0 ; j--){
			if(i == n)
				grid[i][j] = 1;
			else{
				if(j == n)
					grid[i][j] = 1;
				else{
					grid[i][j] = grid[i+1][j] + grid[i][j+1];
				}
			}
		}
	}

/*	for(int i = 0; i <= n ; i++){
		for(int j = 0; j <= n ; j++){
			cout << grid[i][j] << "  ";
		}
		cout << endl;
	}
*/
	cout << grid[0][0] << endl;
}
