#include <iostream>

using namespace std;

/*
1=>push_back(),
2=>pop_back(),
3=>resizing inside the push_back() if size isn't enough,
4=>indexing,
5=>copy constructor,
6=>equal operator
*/

class List
{
private:
    int Size;
    int inputSize;
    char * elements = new char[Size]();
public:
    List(int Size = 10, char *elements = "")
    {
        this->inputSize = 0;
        for (; elements[inputSize] != '\0'; inputSize++);
        this->Size = inputSize > Size ? inputSize : Size;
        this->elements = new char[this->Size]();

        int j = 0;
        for (; this->inputSize < this->Size - 1 && elements[j] != '\0'; j++) {
            this->elements[j] = elements[j];
        }
        this->elements[j] = '\0';

    }
    void display()
    {
        if (elements[0] == '\0')cout << "Empty string.\n";
        else{
                //int i = this->inputSize;
                for (int i = 0; elements[i] != '\0'; i++)
                {
                    cout << this->elements[i];
                }
                cout << endl;
            }
    }

    int getSize()
    {
        return Size;
    }

    void pushBack(char  element)
    {
        this->inputSize += 1;
        if (this->Size <= this->inputSize + 2) // accounting for the added character and the null terminator
        {
            List old = *this;
            List New(old.Size + 10);
            int i = 0;
            for (; i < old.inputSize; i++)
            {
                New.elements[i] = old.elements[i];
            }
            New.elements[i++] = element;
            New.elements[i] = '\0';
            this->Size += 10;
            delete [] this->elements;
            *this = New;
        }
        else
        {this->elements[this->inputSize] = element;
        this->elements[this->inputSize + 1] = '\0';}

    }

    char& getStart()
    {
        return elements[0];
    }
    char& getEnding()
    {
        return elements[inputSize-1];
    }
    ~List()
    {
        delete [] elements;
    }
};

int main()
{

    List l1(10,"esraa");
    l1.display();
    cout << l1.getStart() << endl;
    cout << l1.getEnding() << endl;
    List l2(3, "uno");
    l2.pushBack('Q');
    l2.display();
    cout << l2.getSize() << endl;
    return 0;
}
