#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <sstream>
#include <algorithm>


using namespace std;
vector< string> names;

int main()
{
	string line;
	ifstream myfile( "names.txt" );
	getline( myfile, line );
	line.erase(remove(line.begin(), line.end(), '"'), line.end());

	istringstream ss( line );
    set<string> record;
    while (ss)
    {
      string s;
      if (!getline( ss, s, ',' )) break;
      record.insert( s );
    }

    set<string>::iterator it;
    long long int i = 1;
    long long int sum = 0;

	for (it=record.begin(); it!=record.end(); ++it){
	    long long int score = 0;
		string temp = *it;
		string::iterator it1;

    	for ( it1 = temp.begin() ; it1 < temp.end(); it1++)
	    {

	      	score += (long long int)(*it1 - 'A') + 1;
    	}

    	sum += (long long int)i*score;
    	if(i == 938){

    		cout << temp << "   " << score << endl;
    	}
    	i++;
    }
	cout << sum << endl;
}