#include <iostream>

using namespace std;

class String {
private:
    int size;
    char *characters = new char[size];
public:
    String(int size = 0, char *characters = "")
    {
        this->size = size;
        this->characters = new char[size];
        for(int i = 0; i < size; i++)
        {
            this->characters[i] = characters[i];
        }
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
