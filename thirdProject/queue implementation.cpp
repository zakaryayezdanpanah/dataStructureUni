#include <iostream>

using namespace std;

class queue
{

private:
    int front = -1, rear = -1, maxSize = 10, queue[10];

public:
    bool isEmpty();
    bool isFull();
    void enqueue(int);
    void ReverseQueue();
    void displayElements();
    int dequeue();
    int peek();
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
    this->queue[++this->rear] = value;
}

void queue::ReverseQueue()
{
    if (isEmpty())
        return;

    int temp;

    for (int i = 0; i <= (this->rear - (this->front + 1)) / 2; i++)
    {
        cout << "hello" << endl;

        temp = this->queue[this->front + 1 + i];
        this->queue[this->front + 1 + i] = this->queue[this->rear - i];
        this->queue[this->rear - i] = temp;
    }

    displayElements();
}

void queue::displayElements()
{
    if (isEmpty())
        return;
    for (int i = this->front + 1; i <= this->rear; i++)
    {
        cout << this->queue[i];
    }
}

int queue::dequeue()
{
    if (isEmpty())
        return 0;
    return this->queue[++this->front];
    // returns new first member of queue
}

int queue::peek()
{
    if (isEmpty())
        return 0;

    return this->queue[this->front + 1];
    // returns first member of queue
}
