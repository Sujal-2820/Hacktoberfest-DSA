#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
struct node *top = NULL;
void push(int val)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = val;
    p->link = top;
    top = p;
}
void pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Popped Element : " << top->data << endl;
        top = top->link;
    }
}

void display()
{
    struct node *ptr;
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        ptr = top;
        while (ptr != NULL)
        {
            cout << ptr->data << "\t";
            ptr = ptr->link;
        }
    }
    cout << endl;
}
int main()
{
    int choice, value;
    while (1)
    {
        cout << "1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the element to be pushed : ";
            cin >> value;
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
            break;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
    return 0;
}