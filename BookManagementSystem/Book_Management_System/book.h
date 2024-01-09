#pragma once
#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<sstream> // Using string stream
#include<iomanip> // Formatted output
#define NULLID "0" // Macro definition
using namespace std; // Using namespace

class book
{
private:
    string bookName; // Book name
    string bookAuthor; // Author
    string bookISBN; // ISBN code
    string type; // Category
    int bookStatue; // Book status
    string bookPress; // Publisher

public:
    book(); // Constructor
    string getName() const; // Get book name
    string getbookAuthor() const; // Get author
    string getbookISBN() const; // Get ISBN
    string gettype() const; // Get type
    string getbookPress() const; // Get publisher
    int getbookStatue() const; // Get status

    void setName(string a); // Set book name
    void setAuthor(string b); // Set author
    void setISBN(string c); // Set ISBN code
    void settype(string d); // Set book type
    void setPress(string e); // Set publisher
    void setStatue(int f); // Set status

    void readBookInformation(); // Read book information function
    void printBookInformation(); // Print book information function
    void changeStatue(); // Judge status

    ~book(); // Destructor
};
#endif