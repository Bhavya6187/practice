#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

vector<int> add_vecs(vector<int> a, vector<int> b){

  vector<int> c;
  while(a.size() < b.size()){
    a.push_back(0);
  }
  while(b.size() < a.size()){
    b.push_back(0);
  }
  int carry = 0;
  for(std::vector<int>::size_type i = 0; i != a.size(); i++) {
    c.push_back(a[i]+ b[i]+carry);
    if(c[i] >= 10){
      carry = c[i]/10;
      c[i] = c[i]%10;
    }else{
      carry = 0;
    }
  }
  while(carry > 0){
    c.push_back(carry%10);
    carry/=10;
  }
  return c;
}


int main()
{
  string line;
  ifstream myfile( "large_sum.txt" );
  
//  vector< vector<int> > numbers;

  string::iterator it;
  vector<int>::iterator it2;

  vector<int> result;
  for(int i = 0; i < 50 ; i ++){
    result.push_back(0);
  }

  while (getline( myfile, line ))
  {
    vector<int> temp;
    //cout << line<< endl;
    for ( it = line.begin() ; it < line.end(); it++)
    {
      it2 = temp.begin();
      it2 = temp.insert ( it2 , int(*it - '0') );
    }
    result = add_vecs(result,temp);
//    numbers.push_back(temp);
  }
  myfile.close();

  for (vector<int>::reverse_iterator i = result.rbegin(); i != result.rend(); ++i ){
    cout << *i;
  }
  return 0;
}