#include <iostream>

using namespace std;


class Stack{

private:
    int size;
    int top;
    int * items;
    static int count;
public:
    Stack(int size= 0)
    {
        this->size = size;
        top = -1;
        items = new int [size];
        count++;
        cout << "Constructor called!\n";
        cout << count << endl;
    }
    Stack(const Stack &S)
    {
        this->size = S.size;
        this->top = S.top;
        this->items = new int[size];
        for (int i = 0; i < top + 1; i++)
        {
            this->items[i]=S.items[i];
        }
        cout << "Copy constructor called!\n";
        count++;
        cout << count << endl;

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

            throw runtime_error("Stack is already empty.");
        }
        int data = items[top];
        top--;
        cout << "Successful pop.\n";
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
        count--;
        cout << "Destructor Call !\n";
        cout << count << endl;
    }
    Stack operator=( Stack &S)
    {
        delete[] items;
        size = S.size;
        top = S.top;
        items = new int[size];
        for (int i = 0; i < top + 1; i++)
        {
            items[i]=S.items[i];
        }
        cout << " = operator called!\n";
        return *this;
    }

};


int Stack::count = 0;


void viewContentByVal(Stack S)
{
    S.display();
    cout << "I'm the viewContentByVal function!\n";
}

void viewContentByRef(Stack &S)
{
    S.display();
    cout << "I'm the viewContentByRef function!\n";
}
Stack& TOO()
{
    Stack S;
    return S;

}


int main()
{

    Stack s(10);
    Stack s1;
    s1 = TOO();
    s = s1;
    /*s.push(15);
    s.push(20);
    s.push(35);
    s.push(25);
    s.push(25);
    s.push(25);
    s.push(25);
    s.push(25);
    s.push(25);
    s.push(25);
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s = s1;
    viewContentByVal(s);
    viewContentByRef(s);
    try
    {
        s.pop();

    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    s.display();*/



}
