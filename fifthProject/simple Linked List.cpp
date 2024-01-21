#include <iostream>

using namespace std;

struct list
{
    int num;
    list *link;
};

class linkedList
{
    list *head = NULL;

public:
    void insertAtBegin(int);
    void insertAtEnd(int);
    void insertAtIndex(int, int);
    void updateNode(int, int);
    int sizeOfList();
    void showAllItems();
    void concatenate(list *);
    void invert();
    int removeNodeAtBegin();
    int removeNodeAtEnd();
    int removeNodeAtIndex(int);
    list *getHead()
    {
        return head;
        // To access the head to connect two linked list
    };
};

void linkedList::insertAtBegin(int num)
{

    list *newNode = new list;
    newNode->num = num;
    if (head == NULL)
    {
        head = newNode;
        newNode->link = NULL;
    }
    else
    {
        newNode->link = head;
        head = newNode;
    }
}

void linkedList::insertAtEnd(int num)
{
    list *newNode = new list;

    newNode->num = num;
    newNode->link = NULL;

    if (this->head == NULL)
    {
        this->head = newNode;
    }
    else
    {
        list *temp = this->head;

        while (temp->link != NULL)
        {
            temp = temp->link;
        }

        temp->link = newNode;
    }
};

void linkedList::insertAtIndex(int num, int index)
{
    if (index < 0 || index > sizeOfList()-1)
    {
        cout << "The input index is out of range \n";
        return;
    }
    else if (index == 0)
    {
        insertAtBegin(num);
        return;
    }
    else if (index == sizeOfList()-1)
    {
        insertAtEnd(num);
        return;
    }
    else
    {
        list *temp = this->head;
        int counter = 0;
        list *newNode = new list;
        newNode->num = num;

        while (counter < index - 1)
        {
            if (temp->link == NULL)
            {
                cout << "The input index is out of range \n";
                return;
            }
            temp = temp->link;
            counter++;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }
}

void linkedList::updateNode(int num, int index)
{
    if (index < 0 || index > sizeOfList() - 1)
    {
        cout << "The input index is out of range \n";
        return;
    }

    list *temp = this->head;
    int counter = 0;

    while (counter < index && temp->link != NULL)
    {
        temp = temp->link;
        counter++;
    }

    temp->num = num;
};

int linkedList::sizeOfList()
{
    if (head == NULL)
    {
        cout << "list is empty \n";
        return 0;
    }
    else
    {
        list *temp = this->head;
        int counter = 0;
        while (temp != NULL)
        {
            temp = temp->link;
            counter++;
        }

        return counter;
    }
};

void linkedList::showAllItems()
{

    if (head == NULL)
    {
        cout << "list is empty \n";
    }
    else
    {
        list *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->num << " ";
            temp = temp->link;
        }
    }
};

void linkedList::concatenate(list *subListHead)
{

    list *temp = this->head;

    while (temp->link != NULL)
    {
        temp = temp->link;
    }

    temp->link = subListHead;
};

void linkedList::invert()
{
    list *preNode = NULL;
    list *currentNode = this->head;
    list *temp;

    if (head->link == NULL)
    {
        cout << "invalid input \n";
        return;
    }
    while (currentNode != NULL)
    {
        temp = currentNode->link;
        currentNode->link = preNode;
        preNode = currentNode;
        currentNode = temp;
    }
    this->head = preNode;
};

int linkedList::removeNodeAtBegin()
{
    if (head == NULL)
    {
        cout << "list is empty \n";
        return 0;
    }
    else
    {
        int removedNum = head->num;
        head = head->link;
        return removedNum;
    }
};

int linkedList::removeNodeAtEnd()
{
    if (head == NULL)
    {
        cout << "list is empty \n";
        return 0;
    }
    else
    {

        int removedNum;

        if (head->link == NULL)
        {
            removedNum = head->num;
            head = NULL;
        }
        else
        {
            list *temp = this->head;

            while (temp->link->link != NULL)
            {
                temp = temp->link;
            }
            removedNum = temp->link->num;
            temp->link = NULL;
        }

        return removedNum;
    }
};

int linkedList::removeNodeAtIndex(int index)
{
     if (index < 0 || index > sizeOfList() - 1)
    {
        cout << "The input index is out of range \n";
        return 0;
    }
    else if (index == 0)
    {
        removeNodeAtBegin();
        return 0;
    }
    else if (index == sizeOfList()-1)
    {
        removeNodeAtEnd();
        return 0;
    }
    else
    {
        list *temp = this->head;
        int removedNum;

        for (int counter = 0; counter < index - 1; counter++)
        {
            if (temp->link->link == NULL)
            {
                cout << "The input index is out of range \n";
                return 0;
            }
            else
            {
                temp = temp->link;
            }
        }
        removedNum = temp->link->num;
        temp->link = temp->link->link;
        return removedNum;
    }
};