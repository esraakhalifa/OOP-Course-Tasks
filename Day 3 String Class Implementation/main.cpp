#include <iostream>

using namespace std;

class String {
private:
    int size;
    char *characters = new char[size];
public:

    String(int size = 0, char *characters = "")
    {
        this->size = size > 0 ? size : this->strlen(characters) + 1;
        this->characters = new char[this->size];
        for (int i = 0; i < this->size - 1 && characters[i] != '\0'; i++) {
            this->characters[i] = characters[i];
        }
        this->characters[this->size - 1] = '\0';
    }


    String& operator=(const String &s)
    {
        if (this == &s) return *this;

        delete[] this->characters;

        this->size = s.size;
        this->characters = new char[this->size];
        for (int i = 0; i < this->size; i++) {
            this->characters[i] = s.characters[i];
        }
        return *this;
    }

    /*String reSize(int size, char character = '\0')
    {
        String s = *this;
        String sNew(size);
        int sizeDiff = sNew.size - s.size;
        if (sizeDiff >= 0)
        {
            int indx = 0;
            for (; indx < s.size; indx++)
            {
                sNew.characters[indx] = s.characters[indx];
            }

            for(;indx < sNew.size; indx++)
            {
                sNew.characters[indx] = character;
            }
        }
        else
        {
            for (int indx = 0; indx < sNew.size; indx++)
            {
                sNew.characters[indx] = s.characters[indx];
            }

        }
        *this = sNew;
        return *this;
    }*/


    int strlen()
    {
        int i = 0;
        while(this->characters[i] != '\0')
        {
            i++;
        }
        return i;
    }

    int strcmp(String S) // works with a string obj only
    {
        if (this->strlen() > S.strlen()) return 1;
        else if (this->strlen() < S.strlen()) return -1;
        else return 0;
    }
    int getSize()
    {
        return size;
    }

    String strcat(String addition)
    {
        int newSize = this->strlen() + addition.strlen() + 1;
        String newString(newSize);
        int indx = 0;
        for (; indx < this->strlen(); indx++)
        {
            newString.characters[indx] = this->characters[indx];
        }
        for (int indx2 = 0; indx2 < addition.strlen(); indx2++)
        {
            newString.characters[indx++] = addition.characters[indx2];
        }
        newString.characters[indx] = '\0';
        return newString;


    }
    void display()
    {
        if (this->strlen() == 0) cout << "Empty string.\n";
        else{
                for (int i = 0; i < this->strlen(); i++)
                {
                    cout << this->characters[i];
                }
                cout << endl;
            }
    }
/*
char * strcpy(char dest[], char source[], int Size)
{
    int source_size = strlen(source);
    if (Size > source_size)
    {
        int indx = 0;
        for (; source[indx] != '\0'; indx++)
        {
            dest[indx] = source[indx];
        }
        dest[indx] = '\0';
        for (indx++; indx < Size; indx++)
        {
            dest[indx] = '\0';
        }
    }
    else
    {
        printf("Error: Not enough space in destination buffer.\n");
    }
    return dest;

}
    */
    ~String()
    {
        delete [] characters;
    }
};

int main()
{
    String s1(10, "Esraa");
    s1.display();
    cout << s1.strlen() << "\n";
    String s2(10, "Mahmoud"), s3(10, "Uno"), s4(10, "Asmaa");
    cout << s1.strcmp(s2) << endl;
    cout << s1.strcmp(s3) << endl;
    cout << s1.strcmp(s4) << endl;
    String result = s1.strcat(s2);
    result.display();
    return 0;
}
