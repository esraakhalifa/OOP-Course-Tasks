#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

typedef struct Employee
{
    char ID[5];
    char Age[10];
    char salary[10];
    char Name[20];
} Employee;


class Stack
{
private:
    int size;
    int top;
    Employee *items;

public:
    Stack(int size)
    {
        this->size = size;
        top = -1;
        items = new Employee[size];
    }

    int push(Employee data)
    {
        if (top == size - 1)
        {
            throw runtime_error("Stack is full.");
        }
        top++;
        items[top] = data;
        return 1;
    }

    Employee pop()
    {
        if (top == -1)
        {
            throw runtime_error("Stack is already empty.");
        }
        Employee data = items[top];
        top--;
        return data;
    }

    void display()
    {
        int numItems = top + 1;
        for (int i = 0; i < numItems; i++)
        {
            cout << items[i].ID << ". " << items[i].Name << ", " <<items[i].Age << ", earns" << items[i].salary ;
        }
        cout << endl;
    }

    ~Stack()
    {
        delete[] items;
    }
};


void renderMenu(int selectedOption)
{
    system("cls");

    char *options[] = {"Push", "Pop", "PrintStack"};


    for (int i = 0; i < 3; i++)
    {
        if (i == selectedOption)
        {
            cout << "\033[32m" << options[i] << "\033[0m" << endl;
        }
        else
        {
            cout << options[i] << endl;
        }
    }
}


void moveArrows(int &selectedOption)
{
    char click = _getch();
    if (click == -32)
    {
        click = _getch();
        if (click == 72)
        {
            selectedOption--;
            if (selectedOption < 0) selectedOption = 2;
        }
        else if (click == 80)
        {
            selectedOption++;
            if (selectedOption > 2) selectedOption = 0;
        }
    }

}

int main()
{
    int inputSize;
    cout << "Enter stack size: ";
    cin >> inputSize;
    Stack employeeStack(inputSize);

    int selectedOption = NULL;
    selectedOption = 0;
    renderMenu(selectedOption);

    while (true)
    {
        moveArrows(selectedOption);
        renderMenu(selectedOption);

        if (_kbhit())
        {
            char key = _getch();
            if (key == 13)
            {
                system("cls");
                if (selectedOption == 0)
                {

                    cout << "You selected 'Push'!" << endl;
                }
                else if (selectedOption == 1)
                {

                    cout << "You selected 'Pop'!" << endl;
                }
                else if (selectedOption == 2)
                {

                    cout << "You selected 'PrintStack'!" << endl;
                }

            }
        }
    }

    return 0;
}

