#include "book.h"
book::book() // Constructor
{ 
    bookName = "unassigned";
    bookISBN = NULLID;
}

string book::getName() const // Get book name
{
    return bookName;
}

string book::getbookAuthor() const // Get author
{
    return bookAuthor;
}

string book::getbookISBN() const // Get ISBN
{
    return bookISBN;
}

string book::gettype() const // Get type
{
    return type;
}

string book::getbookPress() const // Get publisher
{
    return bookPress;
}

int book::getbookStatue() const // Get status
{
    return bookStatue;
}

void book::setName(string a) // Set book name
{
    bookName = a;
}

void book::setAuthor(string b) // Set author
{
    bookAuthor = b;
}

void book::setISBN(string c) // Set ISBN code
{
    bookISBN = c;
}

void book::settype(string d) // Set book type
{
    type = d;
}

void book::setPress(string e) // Set publisher
{
    bookPress = e;
}

void book::setStatue(int f = 0) // Set status
{
    bookStatue = f;
}

void book::readBookInformation() // Read book information function
{
    cout << "Please enter the book name:" << endl; // Read book name
    cin >> bookName;
    
    cout << "Please enter the author name:" << endl; // Read author name
    cin >> bookAuthor;

    cout << "Please enter the ISBN code:" << endl; // Read ISBN code
    cin >> bookISBN;

    cout << "Please enter the category:" << endl; // Read category
    cin >> type;

    cout << "Please enter the publisher:" << endl; // Read publisher
    cin >> bookPress;

    cout << "Please enter the status: (0 for in library, 1 for borrowed)" << endl; // Read status
    cin >> bookStatue;
}

void book::printBookInformation() // Print book information function
{
    cout << "Book Name: " << bookName << endl; // Output book name
    cout << "Author: " << bookAuthor << endl; // Output author
    cout << "ISBN Code: " << bookISBN << endl; // Output ISBN code
    cout << "Category: " << type << endl; // Output category
    cout << "Publisher: " << bookPress << endl; // Output publisher
    changeStatue(); // Call status change function
}

void book::changeStatue() // Judge status
{
    if (bookStatue == 0)
    {
        cout << "Status: In library" << endl; // Output status
    }
    else
    {
        cout << "Status: Borrowed" << endl; // Output status
    }
}

book::~book()
{
    // Destructor
}