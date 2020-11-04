//IMPLEMENTATION OF STACK USING SINGLY LINKED LISTS
//2019-CS-682
//Muhammad Bilal
//IMPLEMENTATION OF STACK USING SINGLY LINKED LISTS
#include"iostream"
#include"conio.h"
#include <typeinfo>
#include <assert.h> 
using namespace  std;



class node //struct
{
public:
    node* nextptr = NULL;
    string ss;

    node()
    {
        nextptr = NULL;
    }

    node(string s)
    {
        ss = s;
        nextptr = NULL;
    }
    //TO Get the data
    string getstringData()
    {
        return ss;
    }
    void setstringData(string s)
    {
        ss = s;
    }
    node* getNextptr()
    {
        return nextptr;
    }
    void setnextptr(node* nptr)
    {
        nextptr = nptr;
    }
};


class linkedlist
{
    node* headptr;
    node* addnodeatspecificpoition;

public:
    linkedlist()
    {
        headptr = NULL;
    }
    void insertionAtTail(node* n)
    {
        if (headptr == NULL)
        {
            headptr = n;
        }
        else
        {
            node* rptr = headptr;
            while (rptr->getNextptr() != NULL)
            {
                rptr = rptr->getNextptr();
            }
            rptr->setnextptr(n);
        }
    }

    void insertionAtHead(node* n)
    {
        node* tmp = n;
        tmp->setnextptr(headptr);
        headptr = tmp;
    }

    int sizeOfLinkedList()
    {
        int i = 1;
        node* ptr = headptr;
        while (ptr->getNextptr() != NULL)
        {
            ++i;
            ptr = ptr->getNextptr();
        }
        return i;
    }

    bool isListEmpty() {
        if (sizeOfLinkedList() <= 1)
        {
            return true;
        }
        else
        {
            false;
        }
    }


    void insertionAtAnyPoint(node* n, int position)
    {
        if (position > sizeOfLinkedList() || position < 1) {
            cout << "\n\nInvalid insertion at index :" << position << " ,No such index exists.ERROR!\n";
            return;
        }

        addnodeatspecificpoition = new node;
        addnodeatspecificpoition = n;
        addnodeatspecificpoition->setnextptr(NULL);



        if (headptr == NULL)
        {
            headptr = addnodeatspecificpoition;
        }
        else if (position == 0)
        {
            addnodeatspecificpoition->setnextptr(headptr);
            headptr = addnodeatspecificpoition;
        }
        else
        {
            node* current = headptr;
            int i = 1;
            for (i = 1; current != NULL; i++)
            {
                if (i == position)
                {
                    addnodeatspecificpoition->setnextptr(current->getNextptr());
                    current->setnextptr(addnodeatspecificpoition);
                    break;
                }
                current = current->getNextptr();
            }
        }
    }

    void deleteNodeAtHead()
    {
        //temp to store head
        node* temp = headptr;
        cout << "\nDeleting the head node now i.e at position 0\n";
        headptr = temp->getNextptr();
        delete temp;

    }
    int searchNode(string d)
    {
        node* ptr = headptr;
        static int i = 0;
        bool flag = 0;

        while (ptr->getNextptr() != NULL)
        {
            if (i <= sizeOfLinkedList())
            {
                return -1;
            }
            if (ptr->getstringData() == d)
            {
                flag = 1;
                return i;
            }
            i++;
            ptr = ptr->getNextptr();
        }
        if (flag == 0) { cout << "\nNo element " << d << " exists in the linked list\n"; }
    }
   
    void deleteNodeAtAnyPoint(int position)
    {
        if (position > sizeOfLinkedList() || position < 0)
        {
            cout << "\nInvalid deletion index provided,There is no such node exists like:" << position << endl;
            return;
        }
        if (headptr == NULL)
        {
            cout << "\nThe list is empty now\n";
            return;
        }
        //temp to store head
        node* temp = headptr;
        //Delete head node
        if (position == 0)
        {
            cout << "\nDeleting the head node now i.e at position 0\n";
            headptr = temp->getNextptr();
            delete temp;
            return;
        }
        //store previous of to be deleted node
        for (int i = 0; temp != NULL && i < position - 1; i++)
        {
            temp = temp->getNextptr();
        }
        if (temp == NULL || temp->getNextptr() == NULL)
        {
            return;
        }
        //delete node at pos (next of pos-1)
        node* next = temp->getNextptr()->getNextptr();
        delete temp->getNextptr();
        temp->setnextptr(next);
    }

    void deletionAtTail()
    {
        if (headptr == NULL)
        {
            cout << NULL;
            return;
        }

        if (headptr->getNextptr() == NULL) {
            delete headptr;
            cout << NULL;
            return;
        }

        cout << "\nNow removing the last node at position " << sizeOfLinkedList() << endl;
        // Find the second last node 
        node* secondLast = headptr;
        while (secondLast->getNextptr()->getNextptr() != NULL)
        {
            secondLast = secondLast->getNextptr();
        }

        // Delete last node 
        delete secondLast->getNextptr();
        secondLast->setnextptr(NULL);
    }
    friend ostream& operator<<(ostream& output, const linkedlist& L)
    {

        node* ptr = L.headptr;
        try
        {
            while (ptr->getNextptr() != NULL)
            {
                output << ptr->getstringData() << endl;
                ptr = ptr->getNextptr();
            }

            output << ptr->getstringData();
            ptr->setnextptr(NULL);
            if (ptr->getNextptr() == NULL)
            {
                throw(ptr->getNextptr());
            }
        }
        catch (node* ptr) {
            output << "\nAccess denied at pointer:";
            output << ptr << endl;
        }

        return output;
    }

    ~linkedlist() {
        cout << "\nIn the destructor deleting all the nodes and singly linked list\n";
        delete addnodeatspecificpoition;
        node* temp = headptr, * next;
        while (temp != NULL)
        {
            next = temp->getNextptr();
            delete temp;
            temp = next;
        }

        delete headptr;
        headptr = NULL;
    }
    string GetNth(int index)
    {
        node* current = headptr;
        // the index of the 
        // node we're currently 
        // looking at 
        int count = 0;
        while (current != NULL) {
            if (count == index)
            {
                return (current->getstringData());
            }
            count++;
            current = current->getNextptr();
        }
        return "\nNO SUCH INDEX\n";
    }
      
};


//////////////////////////////////////////////STACK IMPLEMENTATION///////////////////////////////////////////////////////
class MyStack {
private:
    linkedlist values;
public:
    node* ptr;
    bool is_stack_empty()
    {
        try
        {
            return values.isListEmpty();
            if (ptr->getNextptr() == NULL)
            {
                throw(ptr->getNextptr());
            }
        }
        catch (node* ptr) {
            cout << "\nAccess denied at pointer:";
            cout << ptr << endl;
        }
        
    }
    void push(node *value)
    {
        node* n = value;
        values.insertionAtTail(n);
    }
    void pop()
    {
        cout <<"\nThe value which is poped is equal to : "<<values.GetNth(0) << endl;
        values.deleteNodeAtAnyPoint(0);
    }
    string peek()
    {
        string v = values.GetNth(0);
        return (v);
    }
    void displayStack()
    {
        cout << "\n";
        cout << values << endl;
    }
    ~MyStack()
    {
        delete ptr;
    }
};






///////////////////////////////////////STACK IMPLEMENTATION////////////////////////////////////////////////////////////



    int main()
    {

        MyStack S;

        cout << "\nShowing the STACK data:- \n";
        S.push(new node("ONCE"));
        S.push(new node("WE"));
        S.push(new node("WILL"));
        S.push(new node("PUT"));
        S.push(new node("OUR"));
        S.push(new node("FOOT"));
        S.push(new node("IN"));
        S.push(new node("GRAVE"));
        S.push(new node("IT"));
        S.push(new node("WILL"));
        S.push(new node("NEVER"));
        S.push(new node("NEVER"));
        S.push(new node("COME"));
        S.push(new node("BACK"));
        S.push(new node("TO"));
        S.push(new node("THIS"));
        S.push(new node("UNCERTAIN"));
        S.push(new node("WORLD"));
        S.displayStack();
        //cout << "\nThe value at the Nth Index is : " << L1.GetNth(0) << endl;


       
        bool check = true;
        while (check == true)
        {

            char options;

            cout << "\n\nEnter what you want to do \n\n1)=> Press '1' For Displaying the STACK,\n2)=> Press '2' For push in STACK"
                << "\n3)=> Press '3' For POP Method to occur\n4)=> Press '4' For GETTING THE (Top of stack)i.e peek."
                <<"\n5)=> Press 'e' To EXIT THE PROGRAM\n";


            cin >> options;


            switch (options)
            {
            case '1':
            {
                cout << "\nShowing the STACK data:- \n";
                S.displayStack();
                break;
            }
            case '2':
            {
                string value;
                cout << "\nEnter a value(string) for inserting at Tail\n";
                cin >> value;
                S.push(new node(value));
                break;
            }
            case '3':
            {
                S.pop();
                break;
            }
            case '4':
            {
                cout << "\nThe Top of the stack is equal to: " << S.peek() << endl;
                break;
            }
            case 'e':
            {
                cout << "The program is ending now: ";
                break;
            }
            default:
            {
                cout << "\n\nEnter right value please: \n";
            }

            }


            char option;

            cout << "Enter y for opening menu again and n for exiting\t";
            cin >> option;
            while (option != 'y' && option != 'n')
            {
                cout << "Enter right value Please! only y or n: ";
                char option1;
                cin >> option1;
                if (option1 == 'y' || option1 == 'n')
                {
                    break;
                }
            }
            if (option == 'y')
            {
                check = true;
            }
            else if (option == 'n')
            {
                check = false;
                cout << "The program is ending now! ";
            }
        }
    }

