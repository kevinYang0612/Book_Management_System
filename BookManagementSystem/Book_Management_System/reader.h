#pragma once
#ifndef READER_H
#define READER_H
#include <iostream>	 //Use standard input and output stream
#include <fstream>	 //Use file stream
#include <sstream>	 //Use string stream
using namespace std; // Use namespace
class reader
{
private:
	string name;   // name
	string number; // student number
	string code;   // Password
public:
	reader(void);

	void setName(string n);	   // Set name
	void setNumber(string nu); // Set student number
	void setCode(string c);	   // Set password

	string getName() const;	  // Get the name
	string getNumber() const; // Get student number
	string getCode() const;	  // Get the password

	int getInformation(); // Verify student information
	void reviseCode();	  // Change password
	void search();		  // Declare query function
	void borrowBook();	  // Declare the book borrowing function
	void returnBook();	  // Declare the book return function

	~reader(void);
};
#endif