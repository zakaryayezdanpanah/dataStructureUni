#include "./simple Linked List.cpp"

class queue
{

private:
    linkedList queue;
    int front = -1, rear = -1, maxSize = 10;

public:
    bool isEmpty();
    bool isFull();
    void enqueue(int);
    void displayElements();
    int dequeue();
};

bool queue::isEmpty()
{
    if (this->rear == this->front)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool queue::isFull()
{
    if (this->rear == this->maxSize - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void queue::enqueue(int value)
{
    if (isFull())
        return;
    this->rear++;
    this->queue.insertAtBegin(value);
}

void queue::displayElements()
{
    if (isEmpty())
        return;

    queue.showAllItems();
}

int queue::dequeue()
{
    if (isEmpty())
        return 0;
    this->front++;
    return queue.removeNodeAtEnd();
}