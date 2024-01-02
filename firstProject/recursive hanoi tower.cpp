#include <iostream>

using namespace std;

void towerFun(int,char,char,char);

int main()
{
    //sample
    towerFun(3,'a','c','b');

    return 0;
}

void towerFun(int num,char a,char b,char c)
{
  	if (num==1) 
    {
		cout << "Move disk 1 from " <<a<< " to " << b<< endl;
		return;
	}
	towerFun(num - 1, a, c, b);
	cout << "Move disk " << num << " from " << a <<" to "<< b << endl;
	towerFun(num - 1, c, b, a);
    
}