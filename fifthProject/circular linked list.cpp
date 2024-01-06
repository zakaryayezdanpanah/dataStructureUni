#include <iostream>

using namespace std;

struct list
{
    int num;
    list *link;
};

class circularLinkedList
{
    list *head = NULL;
    list *last = NULL;

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

void circularLinkedList::insertAtBegin(int num)
{

    list *newNode = new list;
    newNode->num = num;
    if (this->head == NULL)
    {
        this->head = newNode;
        newNode->link = this->head;
    }
    else if (this->head->link == this->head)
    {
        this->last = this->head;
        newNode->link = this->head;
        this->head = newNode;
        this->last->link = newNode;
    }
    else
    {
        newNode->link = this->head;
        this->head = newNode;
        this->last->link = newNode;
    }
}

void circularLinkedList::insertAtEnd(int num)
{
    list *newNode = new list;

    newNode->num = num;

    if (this->head == NULL)
    {
        this->head = newNode;
        this->head->link = this->head;
    }
    else if (this->head->link == this->head)
    {
        newNode->link = this->head;
        this->last = newNode;
        this->head->link = this->last;
    }
    else
    {
        newNode->link = this->head;
        this->last->link = newNode;
        last = newNode;
    }
};

void circularLinkedList::insertAtIndex(int num, int index)
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
        int counter = 1;
        list *newNode = new list;
        newNode->num = num;

        while (counter < index)
        {
            temp = temp->link;
            counter++;
        }
        newNode->link = temp->link;
        temp->link = newNode;
    }
}

void circularLinkedList::updateNode(int num, int index)
{
    if (index < 0 || index > sizeOfList() - 1)
    {
        cout << "The input index is out of range \n";
        return;
    }

    list *temp = this->head;
    int counter = 0;

    while (counter < index && temp->link != this->head)
    {
        temp = temp->link;
        counter++;
    }

    temp->num = num;
};

int circularLinkedList::sizeOfList()
{
    if (this->head == NULL)
    {
        cout << "list is empty \n";
        return 0;
    }
    else
    {
        list *temp = this->head;
        int counter = 0;
        do
        {
            temp = temp->link;
            counter++;
        } while (temp != this->head);

        return counter;
    }
};

void circularLinkedList::showAllItems()
{

    if (this->head == NULL)
    {
        cout << "list is empty \n";
        return;
    }
    else
    {
        list *temp = this->head;
        while (temp != NULL)
        {
            cout << temp->num << " ";
            temp = temp->link;
            if (temp == this->head)
            {
                return;
            }
        }
    }
};

void circularLinkedList::concatenate(list *subListHead)
{

   list *temp = subListHead;

   if(subListHead==NULL)
   {
    cout<<"invalid entry \n";
    return;
   }

    while (temp->link != subListHead)
    {
        temp = temp->link;
    }

    this->last->link = subListHead;
    temp->link = this->head;
};

void circularLinkedList::invert()
{
    if (this->head->link == NULL)
    {
        cout << "invalid input \n";
        return;
    }
    list *preNode = this->head;
    list *temp = this->head;
    list *currentNode = this->head->link;

    preNode->link = preNode;

    while(currentNode != this->head) {
      temp = currentNode->link;
      currentNode ->link = preNode;
      this->head->link = currentNode;
      preNode = currentNode;
      currentNode = temp;
    }

    this->head = preNode;
};

int circularLinkedList::removeNodeAtBegin()
{
    if (this->head == NULL)
    {
        cout << "list is empty \n";
        return 0;
    }
    else if (this->head->link == this->head)
    {
        int removedNum = this->head->num;
        this->head = NULL;
        return removedNum;
    }
    else
    {
        int removedNum = this->head->num;
        this->head = this->head->link;
        this->last->link = this->head;
        return removedNum;
    }
};

int circularLinkedList::removeNodeAtEnd()
{
    if (this->head == NULL)
    {
        cout << "list is empty \n";
        return 0;
    }
    else if (this->head->link == this->head)
    {
        int removedNum = this->head->num;
        this->head = NULL;
        return removedNum;
    }
    else
    {
        int removedNum;

        list *temp = this->head;

        while (temp->link->link != this->head)
        {
            temp = temp->link;
        }

        removedNum = temp->link->num;
        temp->link = this->head;

        return removedNum;
    }
};

int circularLinkedList::removeNodeAtIndex(int index)
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
    else if (index == sizeOfList() - 1)
    {
        removeNodeAtEnd();
        return 0;
    }
    else
    {
        list *temp = this->head;
        int removedNum;

        for (int counter = 1; counter < index; counter++)
        {
            temp = temp->link;
        }

        removedNum = temp->link->num;
        temp->link = temp->link->link;
        return removedNum;
    }
};
//zakarya yezdanpanah