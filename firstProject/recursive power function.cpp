#include <iostream>

using namespace std;

int powerFun(int,int);

int main()
{
    //sample
     cout<<powerFun(2,5);

    return 0;
}

int powerFun(int num,int power)
{
    if(power==0)
    return 1;
     
    return powerFun(num,power-1)*2;       
}