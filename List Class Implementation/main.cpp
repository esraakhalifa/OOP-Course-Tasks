#include <iostream>

using namespace std;

class List
{
private:
    int Size;
    char * elements = new char[Size]();
public:
    List(int Size = 10, char *elements = "")
    {
        int i = 0;
        for (; elements[i] != '\0'; i++);
        this->Size = i > Size ? i : Size;
        this->elements = new char[this->Size]();
        int j = 0;
        for (; i < this->Size - 1 && elements[j] != '\0'; j++) {
            this->elements[j] = elements[j];
        }
        this->elements[j] = '\0';
    }
    void display()
    {
        if (elements[0] == '\0')cout << "Empty string.\n";
        else{
                for (int i = 0; elements[i] != '\0'; i++)
                {
                    cout << this->elements[i];
                }
                cout << endl;
            }
    }
};

int main()
{

    List l1(10,"esraa");
    l1.display();
    return 0;
}
