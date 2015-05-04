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
int n = 5;

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

