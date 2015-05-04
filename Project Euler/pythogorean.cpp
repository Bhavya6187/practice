#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

int main(){
	int squares[1000];
	for(int i = 0; i < 1000; i+=1){
		squares[i] = i*i;
	}
	for(int a = 0; a < 1000; a+=1){
		for(int b = 0; b < 1000-a; b+=1){
			float root = sqrt(squares[a]+squares[b]);
			if (root==floor(root)){
				int c = int(root);
				if(a + b + c == 1000){
					cout << a <<"  " << b << "  " << c<<endl;
					cout << a*b*c<<endl;
				}
			}
		}
	}
}