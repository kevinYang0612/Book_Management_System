#pragma once
#ifndef MANAGE_H
#define MANAGE_H
#include <iostream>	 //Use standard input and output stream
#include <fstream>	 //Use file stream
#include <sstream>	 //Use string stream
using namespace std; // Use namespace
class manage
{
private:
	string number; // Login number
	string code;   // Password
public:
	manage();				  // Default constructor
	int getManage();		  // Declare the login function
	void reviseInformation(); // Declare the modification information function
	void deleteBook();		  // Declare the delete book function
	void add();				  // Declare the add book function
	void revise();			  // Declare the function to modify book information
	void addReader();		  // Declaration to add reader function
	void deleteReader();	  // Declare the delete reader function
	~manage();				  // Destructor
};
#endif
