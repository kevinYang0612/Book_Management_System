#include"book.h" // Header file
#include"manage.h"
#include"reader.h"
#include<iostream>
using namespace std; // Namespace

// Administrator related functions
void addbook() // Enter add book
{
    manage manage1; // Instantiate object
    for (int temp = 1; temp;) // Loop to add books
    {
        manage1.add(); // Call the add() function of the manage class
        cout << "Do you want to continue adding books (Y: Yes, N: No)" << endl; // Judge whether to loop
        char a; // Define variable
        cin >> a;
        if (a == 'Y') temp = 1;
        else if (a == 'N') temp = 0;
        else 
        { 
            cout << "Input error!" << endl; temp = 1; // Input error prompt
        }
    }
}

void deletebook() // Enter delete book
{
    manage manage6; // Instantiate object
    for (int temp = 1; temp;) // Loop to delete books
    {
        manage6.deleteBook(); // Call the deleteBook() function of the manage class
        cout << "Do you want to continue deleting books (Y: Yes, N: No)" << endl; // Judge whether to loop
        char a; // Define variable
        cin >> a;
        if (a == 'Y') temp = 1;
        else if (a == 'N') temp = 0;
        else 
        { 
            cout << "Input error!" << endl; temp = 1; // Input error prompt
        }
    }
}

void changebook() // Modify book information
{
    manage manage2; // Instantiate object
    for (int temp = 1; temp;) // Loop to modify book information
    {
        manage2.revise(); // Call the revise() function of the manage class
        cout << "Do you want to continue modifying (Y: Yes, N: No)" << endl; // Loop decision
        char a; // Define variable
        cin >> a;
        if (a == 'Y') temp = 1;
        else if (a == 'N') temp = 0;
        else 
        {
            cout << "Input error!" << endl; temp = 1; // Input error prompt
        }
    }
}

void addReader() // Add reader function
{
    manage manage3; // Instantiate object
    for (int temp = 1; temp;) // Loop to add
    {
        manage3.addReader(); // Call the addReader() function of the manage class
        cout << "Do you want to continue adding readers (Y: Yes, N: No)" << endl; // Loop decision
        char a; // Define variable
        cin >> a;
        if (a == 'Y') temp = 1;
        else if (a == 'N') temp = 0;
        else 
        {
            cout << "Input error!" << endl; temp = 1; // Input error prompt
        }
    }
}

void deleteReader() // Delete reader function
{
    manage manage7; // Instantiate object
    for (int temp = 1; temp;) // Loop to delete
    {
        manage7.deleteReader(); // Call the deleteReader() function of the manage class
        cout << "Do you want to continue deleting readers (Y: Yes, N: No)" << endl; // Loop decision
        char a; // Define variable
        cin >> a;
        if (a == 'Y') temp = 1;
        else if (a == 'N') temp = 0;
        else 
        {
            cout << "Input error!" << endl; temp = 1; // Input error prompt
        }
    }
}

void getManage() // Administrator login function
{
    manage manage4; // Instantiate object
    for (int temp = 1; temp;) // Loop to login
    {
        int b; // Receive return value of getManage()
        b = manage4.getManage(); // Call the getManage() function of the manage class
        if (b == 1) // Login successful
        {
            while (true)
            {
                system("cls"); // Clear screen content
                cout << "***************************" << endl;
                cout << "Welcome to the Book Management System!" << endl;
                cout << "Please select the corresponding function:" << endl;
                cout << "1. Add reader" << endl;
                cout << "2. Delete reader" << endl;
                cout << "3. Add book information" << endl;
                cout << "4. Delete book information" << endl;
                cout << "5. Modify book information" << endl;
                cout << "6. Exit" << endl;
                int t;
                cin >> t;
                switch (t)
                {
                    case 1: addReader(); break; // Call addReader() function
                    case 2: deleteReader(); break; // Call deleteReader() function
                    case 3: addbook(); break; // Call addbook() function
                    case 4: deletebook(); break; // Call deletebook() function
                    case 5: changebook(); break; // Call changebook() function
                    case 6:
                        cout << "Thank you for using!" << endl; // Exit
                        system("pause");
                        exit(0);

                    default:
                        cout << "Input error!" << endl; // Input error
                }
            }
        }
        else // Login failed, decide whether to continue logging in
        {
            cout << "Do you want to continue logging in (Y: Yes, N: No)" << endl; // Loop decision
            char a; // Define variable
            cin >> a;
            if (a == 'Y') temp = 1;
            else if (a == 'N') temp = 0;
            else 
            {
                cout << "Input error!" << endl; temp = 1; // Input error prompt
            }
        }
    }
}

void reviseInformation() // Administrator modify information function
{
    manage manage5; // Instantiate object
    for (int temp = 1; temp;) // Loop to modify
    {
        manage5.reviseInformation(); // Call the reviseInformation() function of the manage class
        cout << "Do you want to continue modifying (Y: Yes, N: No)" << endl; // Loop decision
        char a; // Define variable
        cin >> a;
        if (a == 'Y') temp = 1;
        else if (a == 'N') temp = 0;
        else 
        {
            cout << "Input error!" << endl; temp = 1; // Input error prompt
        }
    }
}

// Reader related functions
void search() // Search function
{
    reader reader3; // Instantiate object
    for (int temp = 1; temp;) // Loop to search
    {
        reader3.search(); // Call the search() function of the reader class
        cout << "Do you want to continue searching (Y: Yes, N: No)" << endl; // Loop decision
        char a; // Define variable
        cin >> a;
        if (a == 'Y') temp = 1;
        else if (a == 'N') temp = 0;
        else
        {
            cout << "Input error!" << endl; temp = 1; // Input error prompt
        }
    }
}

void borrowBook() // Borrow book function
{
    reader reader4; // Instantiate object
    for (int temp = 1; temp;) // Loop to borrow books
    {
        reader4.borrowBook(); // Call the borrowBook() function of the reader class
        cout << "Do you want to continue borrowing books (Y: Yes, N: No)" << endl; // Loop decision
        char a; // Define variable
        cin >> a;
        if (a == 'Y') temp = 1;
        else if (a == 'N') temp = 0;
        else 
        {
            cout << "Input error!" << endl; temp = 1; // Input error prompt
        }
    }
}

void reviseCode() // Modify password function
{
    reader reader6; // Instantiate object
    for (int temp = 1; temp;) // Loop to modify password
    {
        reader6.reviseCode(); // Call the reviseCode() function of the reader class
        cout << "Do you want to continue modifying (Y: Yes, N: No)" << endl; // Loop decision
        char a; // Define variable
        cin >> a;
        if (a == 'Y') temp = 1;
        else if (a == 'N') temp = 0;
        else
        {
            cout << "Input error!" << endl; temp = 1; // Input error prompt
        }
    }
}

void returnBook() // Return book function
{
    reader reader5; // Instantiate object
    for (int temp = 1; temp;) // Loop to return books
    {
        reader5.returnBook(); // Call the returnBook() function of the reader class
        cout << "Do you want to continue returning books (Y: Yes, N: No)" << endl; // Loop decision
        char a; // Define variable
        cin >> a;
        if (a == 'Y') temp = 1;
        else if (a == 'N') temp = 0;
		else 
		{
			cout<<"Input error"<<endl; temp=1;// error prompt
		}
	}
}

void getStudent() // Login function
{
    reader reader5; // Instantiate object
    for (int temp=1; temp;) // Loop for login
    {
        int a; // Receive return value of getInformation()
        a = reader5.getInformation(); // Call getInformation() function in reader class
        if (a == 1) // Login successful
        {
            while (true)
            {
                system("cls"); // Clear screen content
                cout << "***************************" << endl;
                cout << "Welcome to the Book Management System!" << endl;
                cout << "Please select the corresponding function:" << endl;
                cout << "1. Search for book information" << endl;
                cout << "2. Borrow books" << endl;
                cout << "3. Return books" << endl;
                cout << "4. Exit" << endl;
                int t;
                cin >> t;
                switch (t)
                {
                    case 1: search(); break; // Call search() function
                    case 2: borrowBook(); break; // Call borrowBook() function
                    case 3: returnBook(); break; // Call returnBook() function
                    case 4:
                        cout << "Thank you for using!" << endl; // Exit
                        system("pause");
                        exit(0);
                    default:
                        cout << "Input error!" << endl; // Input error
                }
            }
        }
        else
        {
            cout << "Do you want to continue logging in? (Y: Yes, N: No)" << endl; // Loop decision
            char a;
            cin >> a;
            if (a == 'Y') temp = 1;
            else if (a == 'N') temp = 0;
            else 
            {
                cout << "Input error!" << endl; temp = 1; // Input error prompt
            }
        }
    }
}

// Menu display functions
void display_2()
{   
    while (true)
    {
        system("cls"); // Clear screen content
        cout << "***************************" << endl;
        cout << "Welcome to the Book Management System!" << endl;
        cout << "1. Log in" << endl;
        cout << "2. Modify administrator information" << endl;
        cout << "3. Exit" << endl;
        int t;
        cin >> t;
        switch (t)
        {
            case 1: getManage(); break; // Call getManage() function
            case 2: reviseInformation(); break; // Call reviseInformation() function
            case 3:
                cout << "Thank you for using!" << endl; // Exit
                system("pause");
                exit(0);
            default:
                cout << "Input error!" << endl; // Input error
        }
    }
}

void display_3()
{
    while (true)
    {
        system("cls"); // Clear screen content
        cout << "***************************" << endl;
        cout << "Welcome to the Book Management System!" << endl;
        cout << "1. Log in" << endl;
        cout << "2. Modify reader information" << endl;
        cout << "3. Exit" << endl;
        int t;
        cin >> t;
        switch (t)
        {
            case 1: getStudent(); break; // Call getStudent() function
            case 2: reviseCode(); break; // Call reviseCode() function
            case 3:
                cout << "Thank you for using!" << endl; // Exit
                system("pause");
                exit(0);
            default:
                cout << "Input error!" << endl; // Error prompt
        }
    }
}

void display_1()
{
    while (true)
    {
        system("cls"); // Clear screen content
        cout << "***************************" << endl;
        cout << "Welcome to the Book Management System!" << endl;
        cout << "Please select your login identity:" << endl;
        cout << "1. Administrator" << endl;
        cout << "2. Reader" << endl;
        cout << "3. Exit" << endl;
        int t;
        cin >> t;
        switch (t)
        {
            case 1: display_2(); break; // Call display_2() function
            case 2: display_3(); break; // Call display_3() function
            case 3:
                cout << "Thank you for using!" << endl; // Exit
                system("pause");
                exit(0);
            default:
                cout << "Input error!" << endl; // Error prompt
        }
    }
}

// Main function
int main()
{
    while (1)
    {
        display_1(); // Call display_1() function
        system("pause");
    }
    return 0;
}