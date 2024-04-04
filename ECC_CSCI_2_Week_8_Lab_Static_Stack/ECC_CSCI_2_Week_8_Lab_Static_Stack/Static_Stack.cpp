/*
 Program Name: Static_Stack.cpp
 Programmer: Moris Gomez
 Date: Tuesday 04/03/2024
 Version Control: 4.0
 About: Week 8, CSCI 2, Lab 1.
 Description:
 The maximum number of car parts that can be added to the stack is 10. If the user tries to
 add more than 10 car parts, the program should display an error message and not add the car
 part to the stack. Similarly, if the user tries to remove a car part from an empty stack,
 the program should display an error message and not remove anything.

 Requirements:
 1. Implement the stack using an array of size 10.
 2. Use appropriate error messages to inform the user of any errors.
 3. Use functions to implement each of the operations described above.
 4. Use a menu-driven approach to allow the user to select an operation to perform.

 Example output:

 Welcome to the machine tracking system!
 Please select an option:

 1. Add a machine
 2. Remove a machine
 3. Display the top machine
 4. Display all machines
 5. Quit
*/

#include <iostream>
#include <string>
using namespace std;

//create StringStack:
class StringStack
{
private:
    string *stackArray; //does stackArray point to the address of the first element?
    //would we need to derefrence each index to access value?
    int size;
    int top;
    
public:
    //CONSTRUCTOR:
    StringStack()
    {
        //code for regular array: int name_array[sz];
        size = 10; //initializes the size of the stack array.
        stackArray = new string[size]; //initializes stack array with a set size of 'size'.
        top = -1; //initializes the top of the stack array to -1.
        //-1 means empty stack array.
    } //end constructor.

//MEMBER FUNCTION #1: isFull():
    bool isFull() const //const = read-only func, so wont modify object it is called on.
                            //sort of like a getter.
    {
        if(top == size - 1) //if top is size - 1, it if full
                                //array size 5 needs to have top index as 4 to be full.
        {
            return true;
        }
        else
        {
            return false;
        }
    } //end isFull() function.
//MEMBER FUNCTION #2: isEmpty():
    bool isEmpty() const
    {
        if(top == -1) //if top is -1, list is empty: -1 is initialized during constructor.
        {
            return true;
        }
        else
        {
            return false;
        }
    } //end isEmpty() function.

//MEMBER FUNCTION #3: push():
    void push(string str)
    {
        if(isFull()) //if stack is full, cannot push bc arrays are fixed size.
        {
            cout << "ERROR: Your Stack is FULL, so cannot add more car parts!" << endl;
        }
        else //not full.
        {
            top = top + 1; //top becomes new index.
            stackArray[top] = str; //set that new index to num.
        }
    } //end push() function.
    
//MEMBER FUNCTION #4: pop():
    void pop()
    {
        if(isEmpty()) //empty, so cannot remove any elements.
        {
            cout << "ERROR: Your Stack is EMPTY, so there are NO car parts to remove!" << endl;
        }
        else //has some indexes.
        {
            top = top - 1;
        }
    } //end pop() function.

//MEMBER FUNCTION #5: display():
    void display()
    {
        int t = top; //last one in, first one out.
        //using while loop to traverse through stack array.
        while(t >= 0)
        {
            cout << "Car Part: " << stackArray[t] << endl;
            t = t - 1;
        } //end while loop.
    } //end display() function.
    
//MEMBER FUNCTION #5: peek().
    string peek() const
    {
        if(isEmpty())
        {
            return "ERROR Stack is empty.";
        }
        else
        {
            return stackArray[top];
        }
        } //end peek() function.
}; //end StringStack class.
    

//DRIVER for classs StringStack via main function:
int main()
{
/*
 1) TESTING MEMBER FUNCTIONS:
    StringStack stackOne; //fixed size of 10 elements.
    stackOne.push("first element."); //FILO.
    stackOne.push("second element.");
    stackOne.push("third element.");
    stackOne.push("fourth element.");
    stackOne.push("fifth element."); //LIFO.
    stackOne.display();
    cout << stackOne.peek() << endl; //fith element.
    cout << stackOne.isEmpty() << endl; //0-F.
    cout << stackOne.isFull() << endl; //0-F.
    stackOne.pop();
    stackOne.display();
    stackOne.pop();
    stackOne.pop();
    stackOne.pop();
    stackOne.display(); //first element only at index 0.
 
    CONTRUCTOR = PASSED.
    PUSH = PASSED.
    POP = PASSED.
    PEEK = PASSED.
    ISEMPTY = PASSED.
    ISFULL = PASSED.
    DISPLAY = PASSED.
*/
    //create empty stack w/ fixed size of 10:
    StringStack stackUser;
    
    int x = 0; //default value.
    while (x != 5)
    {
        //display menu:
        cout << "1. Add a machine." << endl;
        cout << "2. Remove a machine." << endl;
        cout << "3. Display the top machine." << endl;
        cout << "4. Display all machines." << endl;
        cout << "5. Quit." << endl;
        cout << "=======================" << endl;
        cout << "=======================" << endl;
        
        //prompt & store user option in x as built-in int type:
        cout << "Enter option:";
        cin >> x;
        
        //logic paths for user options:
        if(x == 1)
        {
            //stores car part input in y:
            string y;
            cout << "Enter name of car part:";
            cin >> y;
            
            //adds y to stack:
            stackUser.push(y);
            
        }
        else if(x == 2)
        {
            stackUser.pop();
        }
        else if(x == 3)
        {
            cout << "top element is: " << stackUser.peek() << endl;
        }
        else if(x == 4)
        {
            stackUser.display();
        }
        else if(x == 5)
        {
            break;
        }
        else
        {
            cout << "ERROR: Invalid Option Selected. Try Again." << endl;
        }
    } //end while loop:
    cout << "PROGRAM HAS QUIT. RUN IT AGAIN FOR A NEW STACK." << endl;
    
    return 0;
}
