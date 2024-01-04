#include <iostream>

using namespace std;

class circularQueue
{

private:
    int front = 0, rear = 0, maxSize = 5, queue[5];

public:
    bool isEmpty();
    bool isFull();
    void enqueue(int);
    void ReverseQueue();
    void displayElements();
    int dequeue();
    int peek();
};

bool circularQueue::isEmpty()
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

bool circularQueue::isFull()
{
    if (this->rear == this->front - 1)
    {
        return true;
    }
    else if (this->rear == this->maxSize && this->front == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void circularQueue::enqueue(int value)
{
    if (isFull())
        return;

    if (this->rear == this->maxSize)
    {
        this->rear = 0;
        this->queue[this->rear] = value;
    }
    else
    {
        this->queue[++this->rear] = value;
    }
}

void circularQueue::displayElements()
{
    if (isEmpty())
        return;

    int counter = this->front + 1;
    while (true)
    {
        cout << queue[counter];
        if (counter == this->rear)
            break;
        else if (counter == this->maxSize)
        {
            if (this->rear == this->maxSize && this->front == 0)
                break;
            else
            {
                counter = 0;
            }
        }
        else
        {
            counter++;
        }
    }
}

int circularQueue::dequeue()
{
    if (isEmpty())
        return 0;
    if (this->front == this->maxSize)
    {
        this->front = 0;
        return this->queue[this->front];
    }
    else
    {
        return this->queue[++this->front];
    }
    // returns new first member of queue
}

int circularQueue::peek()
{
    if (isEmpty())
        return 0;

    if (this->front == this->maxSize)
    {
        return this->queue[0];
    }
    else
    {
        return this->queue[this->front + 1];
    }
    // returns first member of queue
}