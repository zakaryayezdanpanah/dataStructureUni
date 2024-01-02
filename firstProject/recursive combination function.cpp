#include <iostream>

using namespace std;

int combFun(int ,int);


int main()
{
   //sample
   cout<<combFun(5,3);

    return 0;
}


int combFun(int n,int k)
{
    if(k==n || k==0)
    return 1;
    //using Pascal's rule.
    return combFun(n-1,k)+combFun(n-1,k-1);
};
