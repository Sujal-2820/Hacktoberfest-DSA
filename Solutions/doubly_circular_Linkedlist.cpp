// doubly circular linkedllist
#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
//node class
class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};
// doubly circular linked list class
class D_circularlinkedlist
{
    node *head;
    node *last;

public:
    D_circularlinkedlist()
    {
        head = NULL;
        last = NULL;
    }
    ~D_circularlinkedlist()
    {
        node *x;
        x = head;
        while (x->next != last)
        {
            x = x->next;
            delete (x);
        }
        delete (x);
    }
    void insertBeg(int item);
    void insertEnd(int x);
    void deleteBeg();
    void deleteEnd();
    void display();
    void insertAny(int index, int pro);
    void deleteAny(int pos);
    int lengthl();
    void reverse();
    void scarch(int sc);
};
void D_circularlinkedlist::insertBeg(int item)
{
    node *Newnode = new node(item);
    Newnode->data = item;
    if (head == NULL)
    {
        head = last = Newnode;
        Newnode->next = Newnode->prev = head;
    }
    else
    {
        Newnode->next = head;
        head->prev = Newnode;
        Newnode->prev = last;
        last->next = Newnode;
        head = Newnode;
    }
}
void D_circularlinkedlist::insertEnd(int it)
{
    node *en = new node(it);
    en->data = it;
    if (head == NULL)
    {
        head = last = en;
        en->next = en->prev = head;
    }
    else
    {
        en->prev = last;
        last->next = en;
        en->next = head;
        head->prev = en;
        last = en;
    }
}
void D_circularlinkedlist::deleteBeg()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    else if (head == last)
    {
        node *te;
        te = head;
        head = last = NULL;
        delete (te);
    }
    else
    {
        node *temp;
        head->next->prev = head->prev;
        temp = head;
        head = head->next;
        delete (temp);
    }
}
void D_circularlinkedlist::deleteEnd()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    else if (head == last)
    {
        node *te;
        te = head;
        head = last = NULL;
        delete (te);
    }
    else
    {
        node *t;
        last->prev->next = last->next;
        t = last;
        last = last->prev;
        delete (t);
    }
}
void D_circularlinkedlist::insertAny(int index, int pro)
{
    int c = lengthl();
    if (index == 1)
    {
        insertBeg(pro);
    }
    else if (index >= 2 && index <= c)
    {

        node *newn = new node(pro);
        node *q;
        q = head;
        for (int i = 1; i < (index - 1); i++)
        {
            q = q->next;
        }
        newn->data = pro;
        newn->prev = q;
        newn->next = q->next;
        q->next = newn;
        newn->next->prev = newn;
    }
    else if (index == c + 1)
    {
        insertEnd(pro);
    }
    else
        cout << "check the position!" << endl;
}
void D_circularlinkedlist::deleteAny(int pos)
{
    int a, i;
    a = lengthl();
    i = 1;
    node *anyd = head;
    if (pos < 1 || pos > a)
    {
        cout << "invalid position" << endl;
    }
    else if (pos == 1)
    {
        deleteBeg();
    }
    else if (pos == a)
    {
        deleteEnd();
    }
    else
    {
        while (i < pos - 1)
        {
            anyd = anyd->next;
            i++;
        }
        node *del = anyd->next;
        anyd->next = anyd->next->next;
        anyd->next->prev = del->prev;
        delete (del);
    }
}
int D_circularlinkedlist ::lengthl()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *len;
    len = head;
    int count = 0;
    while (len != last)
    {
        len = len->next;
        count++;
    }
    count += 1;
    return count;
}
void D_circularlinkedlist ::reverse()
{
    node *pre;
    node *temp;
    pre = head;
    while (pre != last)
    {
        temp = pre->next;
        pre->next = pre->prev;
        pre->prev = temp;
        pre = temp;
    }
    pre->next = pre->prev;
    pre->prev = temp;
    pre = head;
    head = last;
    last = pre;
}
void D_circularlinkedlist::scarch(int sc)
{
    node *s;
    s = head;
    int flag = 0;
    while (s->data != sc && s->next != head)
    {
        s = s->next;
        flag += 1;
    }
    if (s->data == sc)
    {
        ++flag;
        cout << "the position of scarched item"
             << "=";
        cout << flag << endl;
    }
    else if (s->prev->data == sc)
    {
        ++flag;
        cout << "the position of scarched item"
             << "=";
        cout << flag << endl;
    }
    else
       cout << "the scarched item is not found!" << endl;
    
}

void D_circularlinkedlist::display()
{
    if (head == NULL)
    {
        cout << "empty!" << endl;
    }
    node *s;
    s = head;
    while (s != last)
    {
        cout << s->data << " ";
        s = s->next;
    }
    cout << s->data;
    cout << endl;
}
int main()
{
    //create a doubly circular linkedlist
    D_circularlinkedlist l;
    int n, item, i;
    int index, pro, pos, sc;
    cout << "operations on Doubly circular linkedlist:" << endl;
    cout << "----------------------------------------------" << endl;
    cout << "0 for EXIT"
         << endl
         << "1.insert at beginning"
         << endl
         << "2.insert at end"
         << endl
         << "3.delete from beinning"
         << endl
         << "4.delete from end"
         << endl
         << "5.insert at any position"
         << endl
         << "6.delete any element"
         << endl
         << "7.length of the linkedlist"
         << endl
         << "8.reverse"
         << endl
         << "9.scarch an item"
         << endl
         << "10.display" << endl;
    cout << "-------------------------------" << endl;
    while (1)
    {
        cout << "enter your choice"
             << "=";
        cin >> n;
        switch (n)
        {
            // Insert node from beginning
        case 1:
            cout << "enter the item to be inserted"
                 << "=";
            cin >> item;
            l.insertBeg(item);
            break;
            // Insert node from end
        case 2:
            cout << "enter the item to be inserted"
                 << "=";
            cin >> i;
            l.insertEnd(i);
            break;
            // delete node from beginning
        case 3:
            l.deleteBeg();
            break;
            // delete node from end
        case 4:
            l.deleteEnd();
            break;
            // insert from any position
        case 5:
            cout << "enter the position where the value should be inserted"
                 << "=";
            cin >> index;
            cout << "enter the item to be inserted"
                 << "=";
            cin >> pro;
            l.insertAny(index, pro);
            break;
            // delete from any position
        case 6:
            cout << "enter the position from where the value should be deleted"
                 << "=";
            cin >> pos;
            l.deleteAny(pos);
            break;
            // print length of linkedlist
        case 7:
            int cou;
            cou = l.lengthl();
            cout << "the length of the doubly circular linkedlist"
                 << "=";
            cout << cou << endl;
            break;
            // reverse
        case 8:
            l.reverse();
            break;
            // scarch for an element
        case 9:
            cout << "enter the item to be scarched"
                 << " "
                 << "=";
            cin >> sc;
            l.scarch(sc);
            break;
            // display the element
        case 10:
            l.display();
            break;
        default:
            exit(99);
        }
    }
    return 0;
}
