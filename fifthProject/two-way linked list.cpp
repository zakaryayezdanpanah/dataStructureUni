#include <iostream>

using namespace std;

struct list
{
    int num;
    list *nextNode;
    list *preNode;
};

class doublyLinkedList
{
    list *head = NULL;

public:
    void insertAtBegin(int);
    void insertAtEnd(int);
    void insertAtIndex(int, int);
    void updateNode(int, int);
    void showAllItems();
    void concatenate(list *);
    void invert();
    int sizeOfList();
    int removeNodeAtBegin();
    int removeNodeAtEnd();
    int removeNodeAtIndex(int);
    list *getHead()
    {
        return head;
        // To access the head to connect two linked list
    };
};

void doublyLinkedList::insertAtBegin(int num)
{

    list *newNode = new list;
    newNode->num = num;
    newNode->preNode = NULL;
    if (head == NULL)
    {
        newNode->nextNode = NULL;
        head = newNode;
    }
    else
    {

        newNode->nextNode = head;
        head->preNode = newNode;

        head = newNode;
    }
}

void doublyLinkedList::insertAtEnd(int num)
{

    list *newNode = new list;

    newNode->num = num;
    newNode->nextNode = NULL;

    if (head == NULL)
    {
        newNode->preNode = NULL;
        head = newNode;
    }
    else
    {
        list *temp = this->head;

        while (temp->nextNode != NULL)
        {
            temp = temp->nextNode;
        }

        newNode->preNode = temp;
        temp->nextNode = newNode;
    }
};

void doublyLinkedList::insertAtIndex(int num, int index)
{
    if (index < 0 || index > sizeOfList() - 1)
    {
        cout << "The input index is out of range \n";
        return;
    }
    else if (index == 0)
    {
        insertAtBegin(num);
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
            if (temp->nextNode == NULL)
            {
                cout << "The input index is out of range \n";
                return;
            }
            temp = temp->nextNode;
            counter++;
        }
        newNode->nextNode = temp->nextNode;
        temp->nextNode = newNode;
        newNode->preNode = temp;
    }
}

void doublyLinkedList::updateNode(int num, int index)
{
    if (index < 0 || index > sizeOfList() - 1)
    {
        cout << "The input index is out of range \n";
        return;
    }

    list *temp = this->head;
    int counter = 0;

    while (counter < index && temp->nextNode != NULL)
    {
        temp = temp->nextNode;
        counter++;
    }

    temp->num = num;
};

void doublyLinkedList::showAllItems()
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
            temp = temp->nextNode;
        }
    }
};

void doublyLinkedList::concatenate(list *subListHead)
{

    list *temp = this->head;

    while (temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }

    temp->nextNode = subListHead;
    subListHead->preNode = temp;
};

void doublyLinkedList::invert()
{
    list *preNode = NULL;
    list *currentNode = this->head;
    list *temp;

    if (head->nextNode == NULL)
    {
        cout << "invalid input \n";
        return;
    }
    while (currentNode != NULL)
    {
        temp = currentNode->nextNode;
        currentNode->nextNode = preNode;
        preNode = currentNode;
        currentNode = temp;
    }
    this->head = preNode;
};

int doublyLinkedList::sizeOfList()
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
            temp = temp->nextNode;
            counter++;
        }

        return counter;
    }
};

int doublyLinkedList::removeNodeAtBegin()
{
    if (head == NULL)
    {
        cout << "list is empty \n";
        return 0;
    }
    else
    {
        int removedNum;

        if (head->nextNode == NULL)
        {
            removedNum = head->num;
            head = NULL;
        }
        else
        {
            removedNum = head->num;
            head = head->nextNode;
            head->preNode = NULL;
        }
        return removedNum;
    }
};

int doublyLinkedList::removeNodeAtEnd()
{
    if (head == NULL)
    {
        cout << "list is empty \n";
        return 0;
    }
    else
    {

        int removedNum;

        if (head->nextNode == NULL)
        {
            removedNum = head->num;
            head = NULL;
        }
        else
        {
            list *temp = this->head;

            while (temp->nextNode->nextNode != NULL)
            {
                temp = temp->nextNode;
            }
            removedNum = temp->nextNode->num;
            temp->nextNode = NULL;
        }

        return removedNum;
    }
};

int doublyLinkedList::removeNodeAtIndex(int index)
{
    if (index < 0 || index > sizeOfList() - 1)
    {
        cout << "The input index is out of range \n";
        return 0;
    }
    else if (index == 0)
    {
        removeNodeAtEnd();
        return 0;
    }
    else if (index == sizeOfList() - 1)
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
            if (temp->nextNode->nextNode == NULL)
            {
                cout << "The input index is out of range \n";
                return 0;
            }
            else
            {
                temp = temp->nextNode;
            }
        }
        removedNum = temp->nextNode->num;
        temp->nextNode->nextNode->preNode = temp;
        temp->nextNode = temp->nextNode->nextNode;
        return removedNum;
    }
};