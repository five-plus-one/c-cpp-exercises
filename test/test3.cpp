#include<iostream>
using namespace std;
int f (int &x, int &y){
	x += 2, y /= 2;
return x+y;
}
int main(){
    int x = 5, y = 4;
cout << f (x, y) <<" "<< x <<" "<<y << endl;
}