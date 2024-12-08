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

    void pushBack(char element) {
       /* cout << "num of elements before increment: " << inputSize << endl;
        cout << "List size: " << Size << endl;
        inputSize++;
        cout << "num of elements after increment: " << inputSize << endl;
        char* newElements = new char[Size]();
        if (inputSize >= Size) {

            Size += 10;


            for (int i = 0; i < inputSize - 1; i++) {
                newElements[i] = elements[i];
                cout << "Added element is: " << newElements[i] << endl;
            }
            newElements[inputSize-1] = element;
            delete[] elements;
            elements = newElements;
            Size = newSize;
        }
        else
        {

        }
        elements[inputSize] = '\0';
    }/./*/
    /*
    issues:

    1==> newsize assigned gowa l if condition
    2==> l array of newelements mt3araf bardo gowa scope l if condition bas
    */

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


    List l2(3, "uno");
    l2.pushBack('Q');
    l2.display();
    cout << l2.getSize() << endl;

    return 0;
}
