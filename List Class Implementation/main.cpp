#include <iostream>
#include <stdexcept>
#include <cstring> // For strlen

using namespace std;

/*
1 => push_back(),
2 => pop_back(),
3 => resizing inside the push_back() if size isn't enough,
4 => indexing,
5 => copy constructor,
6 => equal operator
*/

class List {
private:
    int Size;
    int inputSize;
    char* elements;

public:

    List(const List &l)
    {
        this->Size = l.Size;
        this->inputSize = l.inputSize;
        //cout << "size: " << Size << " and input size: " << inputSize << endl;
        this->elements = new char[Size]();
        for (int i = 0; i < inputSize; i++)
        {
            this->elements[i]=l.elements[i];
            //cout << "Added element: " << elements[i] << endl;
        }
        this->elements[inputSize] = '\0';
        //cout << "Copy constructor called!\n";

    }



    List(int Size = 10, char *elements = "")
        {
            inputSize = 0;
            for (; elements[inputSize] != '\0'; inputSize++);

            this->Size = inputSize > Size ? inputSize : Size;

            this->elements = new char[this->Size]();

            int j = 0;
            for (; this->inputSize < this->Size - 1 && elements[j] != '\0'; j++) {
                this->elements[j] = elements[j];
            }
            this->elements[j] = '\0';

    }

    ~List() {
        delete[] elements; // Free dynamically allocated memory
    }

    void display() const {
        if (inputSize == 0) {
            cout << "Empty string.\n";
        } else {
            for (int i = 0; i < inputSize; i++) {
                cout << elements[i];
            }
            cout << endl;
        }
    }

    int getSize() const {
        return Size;
    }
    List& operator=( List &l)
    {
        if (this == &l) return *this;

        delete[] this->elements;
        this->Size = l.Size;
        this->inputSize = l.inputSize;
        //cout << "new size:" << Size << endl;
        this->elements = new char[Size]();
        //cout << "input size: " << l.inputSize << endl;
        for (int i = 0; i < l.inputSize; i++) {
            this->elements[i] = l.elements[i];
            //cout << "Added element: " << elements[i] << endl;
        }
        return *this;
    }

    void pushBack(char element) {
        //cout << "num of elements before increment: " << inputSize << endl;
        //cout << "List size: " << Size << endl;
        //cout << "num of elements after increment: " << inputSize << endl;
        if (inputSize >= Size) {
            Size *= 2;
            char* newElements = new char[Size]();
            for (int i = 0; i < inputSize; i++) {
                newElements[i] = elements[i];
                //cout << "Added element is: " << elements[i] << endl;
                //cout << "Added element is: " << newElements[i] << endl;
                //cout << "List size: " << Size << endl;
            }
            newElements[inputSize++] = element;
            delete[] elements;
            elements = newElements;
            //Size = newSize;
        }
        else
        {
            elements[inputSize++] = element;
        }
        elements[inputSize] = '\0';
    }
        void popBack() {
            //cout << "input size before pop: " << inputSize << endl;
            elements[inputSize-1] = '\0';
            inputSize--;
            //cout << "New input size after pop: " << inputSize << endl;

    }
    char operator[](int index)
    {
        try {
            if (index > this->Size)
            {
                return -1;
                throw out_of_range("Out of bounds!");
            }

        }
        catch (const exception& e)
        {
            cout << e.what();;
        }

        return this->elements[index];
    }


    char& getStart() {
        if (inputSize == 0) {
            throw runtime_error("List is empty!");
        }
        return elements[0];
    }

    char& getEnding() {
        if (inputSize == 0) {
            throw runtime_error("List is empty!");
        }
        return elements[inputSize - 1];
    }
};

int main() {

    List l1(10, "esraa");
    l1.display();
    cout << l1.getStart() << endl;
    cout << l1.getEnding() << endl;
    List l2(15, "Lululemon");
    l2.display();
    l2.pushBack('a');
    l2.display();
    l2.pushBack('a');
    l2.pushBack('a');
    l2.pushBack('a');
    l2.pushBack('a');
    l2.pushBack('a');
    l2.pushBack('a');
    l2.display();
    l2.popBack();
    l2.display();
    cout << l2[7] << endl;
    l1 = l2;
    l1.display();
    List l3(13,"Farida");
    List l4(l3);
    l4.display();


    return 0;
}
