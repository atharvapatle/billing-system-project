#include <bits/stdc++.h>
using namespace std;

class bill_sys
{
    int pcode;
    int price;
    int dpr;
    string pname;

public:
    void menu();
    void administrator();
    void add();
    void modify();
    void deletee();
    void buyer();
    void list();
    void reciept();
};

void bill_sys::menu()
{
x:
    cout << "\t\t______Welcome to my billing system______\t\t" << endl;
    cout << "\t1. Administrator\n";
    cout << "\t2. Buyer\n";
    cout << "\t3. Exit\n\n";
    cout << "\t\tPlease enter your choice: ";
    int c;
    cin >> c;
    switch (c)
    {
    case 1:
        administrator();
        break;

    case 2:
        buyer();
        break;

    case 3:
        cout << "Thank You!" << endl;
        exit(0);

    default:
        cout << "Please enter valid input!";
        goto x;
    }
}

void bill_sys::administrator()
{
q:
    string email, password;
    cout << "1. Login\n";
    cout << "2. Back to main menu";
    cout << "Enter choice: ";
    int c;
    cin >> c;

    switch (c)
    {
    case 1:

        break;
    case 2:
        menu();

    default:
        cout << "Please enter valid input!";
        goto q;
    }

    cout << "Please enter your email : ";
    cin >> email;
    cout << "\nEnter password : ";
    cin >> password;
    if (email == "atharvapatle1214129@gmail.com" && password == "1214129@al")
    {
        cout << "Login Succesfull!\n";
    }
    else
    {
        cout << "Enter valid password!\n";
        goto q;
    }
w:
    cout << "1. Add\n";
    cout << "2. Modify\n";
    cout << "3. Delete\n";
    cout << "4. Main Menu\n";
    cout << "Enter choice: ";

    cin >> c;

    switch (c)
    {
    case 1:
        add();
        break;
    case 2:
        modify();
        break;
    case 3:
        deletee();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Please enter valid input!";
    }
    goto w;
}

void bill_sys::buyer()
{
m:
    cout << "\t\t\tBUYER\n";
    cout << endl;
    cout << "1. Buy product\n";
    cout << "2. Main menu" << endl;
    int k;
    cout << "Enter choice : ";
    cin >> k;
    switch (k)
    {
    case 1:
        reciept();
        break;
    case 2:
        menu();
    default:
        cout<<"Invalid Input!\n";
    }
    goto m;
}

void bill_sys::add()
{
    cout << "Enter product code: ";
    cin >> pcode;
    cout << "\nEnter product name: ";
    cin >> pname;
    cout << "\nEnter product price";
    cin >> price;
    cout << "Enter discount %: ";
    cin >> dpr;
    fstream file;
    file.open("database.txt", ios::app);
    file << pcode << " " << pname << " " << price << " " << dpr << endl;
    file.close();
}

void bill_sys::modify()
{
    int code, c, p, d;
    string name;
    int token = 0;
    cout<<"\t\tModify\n";
    cout << "Enter code : ";
    cin >> code;
    fstream file, file1;
    file.open("database.txt", ios::in);
    file1.open("database1.txt", ios::app | ios::out); // make a duplicate of it!
    file >> pcode >> pname >> price >> dpr;
    while (!file.eof())
    {
        if (code == pcode)
        {
            cout << "Enter new product code: ";
            cin >> c;
            cout << "\nEnter product name: ";
            cin >> name;
            cout << "\nEnter product price";
            cin >> p;
            cout << "Enter discount %: ";
            cin >> d;

            file1 << c << " " << name << " " << p << " " << d << endl;
            token++;
        }
        else
        {
            file1 << pcode << " " << pname << " " << price << " " << dpr << endl;
        }
        file >> pcode >> pname >> price >> dpr;
    }

    file.close();
    file1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");
    if (token == 0)
    {
        cout << "Record not found!" << endl;
    }
}

void bill_sys::deletee()
{
    int code, c, p, d;
    string name;
    int token = 0;
    cout << "Enter code to remove : ";
    cin >> code;
    fstream file, file1;
    file.open("database.txt", ios::in);
    file << pcode << pname << price << dpr;
    file1.open("database1.txt", ios::app | ios::out); // make a duplicate of it!
    while (!file.eof())
    {
        if (code == pcode)
        {

            token++;
            continue;
        }
        else
        {
            file1 << pcode << " " << pname << " " << price << " " << dpr << endl;
        }
        file >> pcode >> pname >> price >> dpr;
    }

    file.close();
    file1.close();
    remove("database.txt");
    rename("database1.txt", "database.txt");
    if (token == 0)
    {
        cout << "Record not found!" << endl;
    }
    else
        cout << "Deleted succesfull\n";
}

void bill_sys::list()

{
    cout << "\t\t________LIST________\t\t" << endl;
    fstream file;
    file.open("database.txt", ios::in);
    cout << "no\t\tName\t\tPrice\t\t\n";
    file >> pcode >> pname >> price >> dpr;
    while (!file.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << endl;
        file >> pcode >> pname >> price >> dpr;
    }
    file.close();
}

void bill_sys::reciept()
{
    fstream file;
    int arrc[100], arrq[100];
    char choice;
    int c = 0;
    float amount = 0, dis = 0, total = 0;
    cout << "\n\t\t\tRECIEPT\t\t" << endl;
    file.open("database.txt", ios::in);
    if (!file)
    {
        cout << "File not found!\n";
    }
    else
    {
        file.close();
        list();
        do
        {
        k:
            cout << "Enter product code :";
            cin >> arrc[c];
            cout << "Enter product quantity :";
            cin >> arrq[c];
            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrq[i])
                {
                    cout << "Duplicate product! Try again.\n";
                    goto k;
                }
            }
            c++;
            cout << "Wanna buy another product!: ";
            cin >> choice;

        } while (choice == 'y');
        cout << "\t\t______________Reciept______________\t\t\n\n";
        cout << "\t\tProduct code\tName\tPrice\tQuantity\tamount\tamount with discount";

        for (int i = 0; i < c; i++)
        {
            file.open("database.txt", ios::in);
            file >> pcode >> pname >> price >> dpr;
            while (!file.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - ((amount * dpr) / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << arrq[i] << "\t\t" << amount << "\t\t" << dis << endl;
                }
                file >> pcode >> pname >> price >> dpr;

            }
            file.close();

            cout << "\n\nTotal Amount: " << total;
        }
    }
}

int main()
{
    bill_sys helo;
    helo.menu();
}
