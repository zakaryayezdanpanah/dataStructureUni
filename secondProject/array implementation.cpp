#include <iostream>

using namespace std;

class array
{
    private:

    int sizeCounter =0;
    int array[100];

    public:

     void insertAtIndex(int,int);
     int deleteAtIndex(int);
     int findIndexByValue(int);

};

void array ::insertAtIndex(int index,int value)
{
    for(int i=sizeCounter;i>=index;i--)
    {
       this->array[i+1]=this->array[i]; 
    }
    this->array[index]=value;
    sizeCounter++;

}

int array::deleteAtIndex(int index)
{
    int temp = this->array[index];

   for(int i=index;i<= sizeCounter;i++)
   {
    this->array[i]=this->array[i+1];
   }
   sizeCounter--;

   return temp;
};

int array::findIndexByValue(int value)
{
    for(int counter=0;counter<sizeCounter;counter++)
    {
        if(this->array[counter]==value)
        return counter;
    }
    return 0;
}