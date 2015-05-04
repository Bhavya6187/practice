#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <sstream>
#include <fstream>
#include <stdexcept>      // std::out_of_range

using namespace std;

int n = 20;
vector< vector<int> > grid;

int get_max(int i, int j){
	vector<int> temp;

	if(i-3 >= 0 && j-3 >= 0)
	   	temp.push_back(grid[i-3][j-3]*grid[i-2][j-2]*grid[i-1][j-1]*grid[i][j]);
	if(i-3 >= 0)
		temp.push_back(grid[i-3][j]*grid[i-2][j]*grid[i-1][j]*grid[i][j]);
	if(j-3 >= 0)
		temp.push_back(grid[i][j-3]*grid[i][j-2]*grid[i][j-1]*grid[i][j]);
	if(i+3 < 20 && j-3 >= 0)
	   	temp.push_back(grid[i+3][j-3]*grid[i+2][j-2]*grid[i+1][j-1]*grid[i][j]);
	if(i+3 < 20 && j+3 < 20)
	   	temp.push_back(grid[i+3][j+3]*grid[i+2][j+2]*grid[i+1][j+1]*grid[i][j]);
	if(i+3 < 20)
		temp.push_back(grid[i+3][j]*grid[i+2][j]*grid[i+1][j]*grid[i][j]);
	if(j+3 < 20)
		temp.push_back(grid[i][j+3]*grid[i][j+2]*grid[i][j+1]*grid[i][j]);
	if(i-3 >= 20 && j+3 < 20)
	   	temp.push_back(grid[i-3][j+3]*grid[i-2][j+2]*grid[i-1][j+1]*grid[i][j]);
	return *max_element(temp.begin(),temp.end());
}

int main(){
	
	int max = 0;
	string line;
	ifstream myfile( "grid.txt" );
	while (getline( myfile, line ))
	{
		vector<int> temp;
		stringstream ss(line);
		int i;
		while (ss >> i)
		{
    		temp.push_back(i);
        }
        grid.push_back(temp);
	}

	//cout << grid[5][5] << "    " << get_max(5,5);
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n ; j++){
			int temp = get_max(i,j);
			if(temp > max){
				max = temp;
			}
		}
	}
	cout << max;

}