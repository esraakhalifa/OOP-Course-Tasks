#include <iostream>

using namespace std;

class Stack{

private:
    int size;
    int top;
    int * items;
public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        items = new int [size];
    }
    int push(int data)
    {
        if(top == size - 1)
        {

            throw runtime_error("Stack is full.");
        }
        top++;
        items[top] = data;
        return 1;
    }
    int pop()
    {
        if (top == -1)
        {
            //return 0;
            throw runtime_error("Stack is already empty.");
        }
        int data = items[top];
        top--;
        return data;

    }
    void display()
    {
        int numItems = top + 1;
        for (int i = 0; i < numItems; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;

    }
    ~Stack()
    {
        delete [] items;
        //cout << "Des"
    }

};

int main()
{

    Stack s(10);
    s.push(15);
    s.push(20);
    s.push(35);
    s.push(25);
    s.push(25);
    s.push(25);
    s.push(25);
    s.push(25);
    s.push(25);
    s.display();
    s.push(25);
    try{
        s.push(25);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    try
    {
        s.pop();

    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }





}
