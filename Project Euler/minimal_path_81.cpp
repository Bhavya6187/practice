#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>
#include <sstream>


using namespace std;
vector< vector<int> > grid;
vector< vector<int> > min_val;
int n = 79;

int main()
{
	string line;
	ifstream myfile( "matrix.txt" );
	int maxim = 6400*10000;

	while (getline( myfile, line ))
	{
		vector<int> temp;
		vector<int> temp2;
		stringstream ss(line);
		int i;
		while (ss >> i)
		{
    		temp.push_back(i);
    		temp2.push_back(maxim);

		    if (ss.peek() == ',')
        		ss.ignore();
        }
        grid.push_back(temp);
        min_val.push_back(temp2);
	}

	for(int i = n; i >= 0 ; i--){
		for(int j = n; j >= 0 ; j--){
			if(i == n){
				min_val[i][j] = 0;
				for(int k = j; k <= n; k++)
					min_val[i][j] += grid[i][k];
			}
			else{
				if(j == n){
					min_val[i][j] = 0;
					for(int k = i; k <= n; k++)
						min_val[i][j] += grid[k][j];
				}
				else{
					min_val[i][j] = grid[i][j] + min(min_val[i+1][j] ,min_val[i][j+1]);
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

	cout << endl;
	for(int i = 0; i <= n ; i++){
		for(int j = 0; j <= n ; j++){
			cout << min_val[i][j] << "  ";
		}
		cout << endl;
	}*/
	cout << min_val[0][0] << endl;

}