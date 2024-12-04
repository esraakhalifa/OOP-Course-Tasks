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
        //int numItems = top + 1;
        for (int i = top; i >=0; i--)
        {
            cout << items[i].ID << ". " << items[i].Name << ", " <<items[i].Age << " years old, earns " << items[i].salary << endl;
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


            char key = _getch();
            if (key == 13)
            {
                system("cls");
                if (selectedOption == 0)
                {

                    //cout << "You selected 'Push'!" << endl;
                    Employee employee;
                    printf("Enter ID: ");
                    scanf("%s", &employee.ID);
                    printf("Enter name: ");
                    scanf("%s", &employee.Name);
                    printf("Enter age: ");
                    scanf("%s", &employee.Age);
                    printf("Enter salary: ");
                    scanf("%s", &employee.salary);
                    try{
                        employeeStack.push(employee);
                    }
                    catch (const exception& e)
                    {
                        cout << e.what() << endl;
                    }

                    renderMenu(selectedOption);

                }
                else if (selectedOption == 1)
                {

                    //cout << "You selected 'Pop'!" << endl;
                    try{
                        Employee poppedEmployee = employeeStack.pop();
                        cout << poppedEmployee.ID << ". " << poppedEmployee.Name << ", " << poppedEmployee.Age << " years old, earns " << poppedEmployee.salary <<endl;
                    }
                    catch (const exception& e)
                    {
                        cout << e.what() << endl;
                    }

                   // employeeStack.pop();
                }
                else if (selectedOption == 2)
                {

                    employeeStack.display();
                }

            }
            else if ( key == -32 )
            {
                moveArrows(selectedOption);
            }

    }

    return 0;
}

