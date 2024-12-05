#include <iostream>

using namespace std;

class Stack{

private:
    int size;
    int top;
    int * items;
    static int count;
public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        items = new int [size];
    }
    Stack(Stack &S)
    {
        this->size = S.size;
        this->top = S.top;
        this->items = new int[size];
        for (int i = 0; i < top + 1; i++)
        {
            this->items[i]=S.items[i];
        }
        cout << "Copy constructor called!\n";


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
        cout << "Destructor Call !\n";
    }
    Stack operator=(Stack &S)
    {
        this->size = S.size;
        this->top = S.top;
        this->items = new int[size];
        for (int i = 0; i < top + 1; i++)
        {
            this->items[i]=S.items[i];
        }
        cout << " = operator called!\n";
        return *this;
    }

};
int Stack::count = 0;

/*void viewContentByVal(Stack S)
{
    Stack S1(S);
    S1.display();
    cout << "I'm the viewContentByVal function!\n";
}*/
void viewContentByRef(Stack &S)
{
    Stack S1(S);
    S1.display();
    cout << "I'm the viewContentByRef function!\n";

}
/*void viewContentByRef(Stack &S)
{
    Stack S1(S);
    S1.display();
    cout << "I'm the viewContentByRef function!\n";

}*/

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
    //s.display();
    s.push(25);
    /*try{
        s.push(25);
    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }*/
    Stack s1(5);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    s = s1;
    viewContentByRef(s);
    //viewContentByVal(s);
    //s.pop();
    //s.pop();
    /*s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    */
    try
    {
        s.pop();

    }
    catch (const exception& e)
    {
        cout << e.what() << endl;
    }
    s.display();
}
