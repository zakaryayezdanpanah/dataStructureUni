#include "./simple Linked List.cpp"   

class array
{

private:
    linkedList array;

public:
    void add(int);
    void insertAtindex(int, int);
    void showItems();
    int removeAtIndex(int);
};

void array::add(int value)
{
    this->array.insertAtEnd(value);
}

void array::insertAtindex(int index, int value)
{
    this->array.insertAtIndex(value, index);
}

void array::showItems()
{
    this->array.showAllItems();
}

int array::removeAtIndex(int index)
{
    return this->array.removeNodeAtIndex(index);
}