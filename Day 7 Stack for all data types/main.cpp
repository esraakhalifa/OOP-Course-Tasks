#include <iostream>

using namespace std;

template <typename T>
class Stack{

private:
    int size;
    int top;
    T * items;
    static int count;
public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        items = new T [size];
        count++;
        cout << "Constructor called!\n";
        cout << count << endl;
    }
    Stack(Stack &S)
    {
        this->size = S.size;
        this->top = S.top;
        this->items = new T[size];
        for (int i = 0; i < top + 1; i++)
        {
            this->items[i]=S.items[i];
        }
        cout << "Copy constructor called!\n";

    }

    int push(T data)
    {
        if(top == size - 1)
        {

            throw runtime_error("Stack is full.");
        }
        top++;
        items[top] = data;
        return 1;
    }
    T pop()
    {
        if (top == -1)
        {

            throw runtime_error("Stack is already empty.");
        }
        T data = items[top];
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
    }
    Stack& operator=(Stack &S)
    {
        delete[] items;
        size = S.size;
        top = S.top;
        items = new T[size];
        for (int i = 0; i < top + 1; i++)
        {
            items[i]=S.items[i];
        }
        cout << " = operator called!\n";
        return *this;
    }

};

template <typename T>
int Stack<T>::count = 0;

template <typename T>
void viewContentByVal(Stack<T> S)
{
    //Stack S1(S);
    S.display();
    cout << "I'm the viewContentByVal function!\n";
}
template <typename T>
void viewContentByRef(Stack<T> &S)
{
    S.display();
    cout << "I'm the viewContentByRef function!\n";
}


int main()
{

    Stack <int>s(10);
    s.push(15);
    s.push(20);
    s.push(35);
    s.push(25);
    s.push(25);
    s.push(25);
    s.push(25);
    s.push(25);
    s.push(25);
    s.push(25);
    Stack <int> s1(5);
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
    s.display();
    Stack <float> sF(5.0);
    Stack <double> sD(5.0);

}
