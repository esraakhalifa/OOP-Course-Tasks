#include <iostream>

using namespace std;

class String {
private:
    int size;
    char *characters = new char[size];
public:

    String(int size = 0, char *characters = "")
    {
        int i = 0;
        for (; characters[i] != '\0'; i++);
        this->size = size > 0 ? size :i + 1;
        this->characters = new char[this->size];
        int j = 0;
        for (; i < this->size - 1 && characters[j] != '\0'; j++) {
            this->characters[j] = characters[j];
        }
        this->characters[j] = '\0';
    }

    String& operator+=( String &s)
    {
        int newSize = this->strlen() + s.strlen() + 1;
         char* newCharacters = new char[newSize];

        int indx = 0;
        for (; indx < this->strlen(); indx++)
        {
            newCharacters[indx] = this->characters[indx];
        }
        for(int indx2 = 0; indx2 < s.strlen(); indx2++)
        {
            newCharacters[indx++] = s.characters[indx2];
        }
        newCharacters[indx] = '\0';
        delete [] this->characters;
        this->size = newSize;
        this->characters = newCharacters;
        return *this;

    }

    String& operator=( String &s)
    {
        if (this == &s) return *this;

        delete[] this->characters; // freeing allocated space for old string

        this->size = s.size;
        this->characters = new char[this->size]; // allocating new memory for the new string
        for (int i = 0; i < this->size; i++) {
            this->characters[i] = s.characters[i];
        }
        return *this;
    }
    char operator[](int index)
    {
        try {
            if (index > this->size)
            {
                return -1;
                throw out_of_range("Out of bounds!");
            }

        }
        catch (const exception& e)
        {
            cout << e.what();;
        }

        return this->characters[index];
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

    int strcmp( String &S)  // works with a string obj only
    {
        if (this->strlen() > S.strlen()) return 1;
        else if (this->strlen() < S.strlen()) return -1;
        else return 0;
    }
    int getSize()
    {
        return size;
    }

    String strcat( String &addition) //const
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
   String esraa_substr(int start, int length)
   {
       String esraaString(length + 1);
       int originalIndx = start;
       for (int i = 0; i < esraaString.size && originalIndx <= length; i++)
       {
           esraaString.characters[i] = this->characters[originalIndx++];
       }
       return esraaString;
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
    s1 += s2;
    s1.display();
    cout << s1[3] << endl;
    cout << s1[13] << endl;
    String s5 = s1.esraa_substr(1,5);
    s5.display();
    return 0;
}
