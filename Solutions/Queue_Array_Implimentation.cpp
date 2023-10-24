/**
 *  @file: Queue_Array_Implimentation.cpp
 *  @brief: This is a CPP file that shows the array implimentation of Queue data structure.
*/

#include <iostream>
using namespace std;

//==============================================| GLOBAL DECLARATION |===============================================

// Statically declaring Maximum Queue Size:
const int MAX_SIZE = 5;

// Declaring the queue:
int queue[MAX_SIZE];

// Initializing the front and rear pointers:
int front = -1, rear = -1;

//==============================================| FUNCTION DECLARATION |=============================================

void enqueue();
void dequeue();
void display();

//==============================================| MAIN FUNCTION |====================================================

int main()
{
    int choice;
    cout << "\n";
    cout << "\t\t\t\t1.  Enqueue Operation\n";
    cout << "\t\t\t\t2.  Display Operation\n";
    cout << "\t\t\t\t3.  Dequeue Operation\n";
    cout << "\t\t\t\t4.  Exit\n\n";

    while (true)
    {
        cout << "\nEnter Operation Choice (1-4): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            enqueue();
            break;

        case 2:
            display();
            break;

        case 3:
            dequeue();
            break;

        case 4:
            cout << "\t\t\t\t\tExited From the Code\n\n";
            return 0;

        default:
            cout << "\t\t\t\t** Invalid Input Given by the User **\n";
            cout << "\t\t\t\t\tEnter the correct input\n";
            break;
        }
    }

    return 0;
}

//==============================================| ENQUEUE OPERATION |================================================

void enqueue()
{
    cout << "\nENQUEUE OPERATION:\n";
    int value;

    // If rear pointer has reached to end of the Queue:
    if (rear == (MAX_SIZE - 1))
    {
        cout << "Queue is full.\n";
        return;
    }

    cout << "Enter the value: ";
    cin >> value;

    // If the queue is completely empty:
    if (rear == -1 && front == -1)
    {
        rear++;
        front++;
        queue[rear] = value;
    }

    // When the queue has some data in it:
    else
    {
        rear++;
        queue[rear] = value;
    }
    cout << "Enqueue Operation Successful.\n";
}

//==============================================| DISPLAY OPERATION |================================================

void display()
{
    cout << "\nDISPLAY OPERATION:\n";

    // if the queue is empty:
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty.\n";
        return;
    }

    // condition when all the elements of the queue have been removed and it became empty again:
    else if (front == (MAX_SIZE))
    {
        cout << "Queue is full. Front has reached the end.\n";
        return;
    }

    // Display the queue elements:
    else
    {
        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
}

//==============================================| DEQUEUE OPERATION |=================================================

void dequeue()
{
    cout << "\nDEQUEUE OPERATION:\n";
    int removed_element;

    // Situations when queue is empty:
    if ((front == -1 && rear == -1) || front == MAX_SIZE)
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty.\n";
            return;
        }
        else
        {
            cout << "Queue is full. Front has reached the end.\n";
            return;
        }
    }

    // Otherwise Deque the element and display it:
    removed_element = queue[front];
    front++;
    cout << "Removed Element is: " << removed_element;
    cout << "\nDequeue Operation Successful.\n";
}
