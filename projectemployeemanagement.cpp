#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
using namespace std;
struct employee
{
    string emp_name;
    int salary, id;
    long long phone_number;
};
employee ep[100]; // array declare to store the data
int t = 0;
void employee_data()
{
    int choice;
    cout << "Enter the how many employee data enter " << endl;
    cin >> choice;
    for (int i = t; i < t + choice; i++)
    {
        cout << "Enter data of employee " << i + 1 << endl;
        cout << "Enter the  Name :";
        cin >> ep[i].emp_name;
        // getline(cin, ep[i].emp_name);
        cout
            << "Enter the employee id :";
        cin >> ep[i].id;
        cout << "Enter the phone number :";
        cin >> ep[i].phone_number;
        cout << "Enter the employee salary :";
        cin >> ep[i].salary;
        cout << "_________________________________________" << endl;
    }
    t = t + choice;
}

void show_data()
{
    if (t != 0)
    {
        for (int i = 0; i < t; i++)
        {
            cout << "_________________________________________" << endl;
            cout << "Name :" << ep[i].emp_name << endl;
            cout << "Id :" << ep[i].id << endl;
            cout << "Phone :" << ep[i].phone_number << endl;
            cout << "Salary :" << ep[i].salary << "$" << endl;
            cout << "_________________________________________" << endl;
        }
    }
    else
    {
        cout << "Record Empty " << endl;
    }
}
void search_data()
{
    if (t != 0)
    {
        int id1;
        cout << "Enter the id you want to search it :";
        cin >> id1;

        for (int i = 0; i < t; i++)
        {
            if (id1 == ep[i].id)
            {

                cout << "Name :" << ep[i].emp_name << endl;
                cout << "Id :" << ep[i].id << endl;
                cout << "Phone :" << ep[i].phone_number << endl;
                cout << "Salary :" << ep[i].salary << "$" << endl;
            }
        }
    }
    else
    {
        cout << "Record Empty " << endl;
    }
}
void update_data()
{
    if (t != 0)
    {
        int id3;
        cout << "Enter the id which you want to update ";
        cin >> id3;

        // cout << "first data is " << endl;
        for (int i = 0; i < t; i++)
        {
            if (id3 == ep[i].id)
            {
                cout << "first data is " << endl;
                cout << "Name :" << ep[i].emp_name << endl;
                cout << "Id :" << ep[i].id << endl;
                cout << "Phone :" << ep[i].phone_number << endl;
                cout << "Salary :" << ep[i].salary << "$" << endl;
                cout << "_________________________________________" << endl;

                cout << "Enter the new data  " << endl;

                cout << "Enter data of employee " << i + 1 << endl;
                cout << "Enter the  Name :";
                cin >> ep[i].emp_name;
                // getline(cin, ep[i].emp_name);
                cout
                    << "Enter the employee id :";
                cin >> ep[i].id;
                cout << "Enter the phone number :";
                cin >> ep[i].phone_number;
                cout << "Enter the employee salary :";
                cin >> ep[i].salary;
                break;
            }
        }
    }
    else
    {
        cout << "Record Empty " << endl;
    }
}
void delete_data()
{
    if (t != 0)
    {
        char a;

        cout << " 1 Delete all data " << endl;
        cout << " 2 delete specific data " << endl;
        a = getch();
        if (a == '1')
        {
            t = 0;
            cout << "DELETEed..." << endl;
        }
        else if (a == '2')
        {
            int id3;
            cout << "Enter the id which you want to update ";
            cin >> id3;
            for (int i = 0; i < t; i++)
            {
                if (id3 == ep[i].id)
                {
                    for (int j = i; j < t; j++)
                    {
                        ep[j].emp_name = ep[j + 1].emp_name;
                        ep[j].id = ep[j + 1].id;
                        ep[j].phone_number = ep[j + 1].phone_number;
                        ep[j].salary = ep[j + 1].salary;
                        t--;
                        break;
                    }
                }
            }
        }
    }
    else
    {
        cout << "Record Empty " << endl;
    }
}

int main()
{
    cout << "\n\t\t Employee Management System " << endl;
    string userName, password, username1, password1;
    cout << "Create new username :";
    cin >> userName;
    cout << "Password :";
    cin >> password;
    cout << "\n\t\t Your account is creating please wait few second ";
    for (int i = 0; i < 5; i++)
    {
        cout << ".";
        Sleep(100);
    }
    cout << "\n\t\t Your id created successfully ";
    system("CLS");
start:
    cout << "Employee management system " << endl;
    cout << "Login " << endl;

    cout << "Username :";
    cin >> username1;
    cout << "Password :";
    cin >> password1;

    if (userName == username1 && password == password1)
    {
        system("CLS");
        char user;

        while (1)
        {
            cout << "________________________" << endl;
            cout << "press 1 Enter the data  " << endl;
            cout << "press 2 Show the data   " << endl;
            cout << "press 3 search the data " << endl;
            cout << "press 4 delete the data " << endl;
            cout << "press 5 Update the data " << endl;
            cout << "press 6 Logout " << endl;
            cout << "press 7 Exit " << endl;
            cout << "________________________" << endl;
            user = getch();

            switch (user)
            {
            case '1':
                employee_data();
                break;
            case '2':
                // system("CLS");
                show_data();
                break;
            case '3':
                search_data();
                break;
            case '4':
                delete_data();
                break;
            case '5':
                update_data();
                break;

            default:
                cout << "\aInvalid input" << endl;
            }
        }
    }
    else if (userName != username1)
    {
        cout << "\n\t\tincorrect username please check username ";
        Sleep(1000);
        goto start;
    }
    else if (password != password1)
    {
        cout << "\n\t\tincorrect Password please check Password ";
        Sleep(1000);
        goto start;
    }

    return 0;
}