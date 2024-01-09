#include "reader.h"
#include "book.h"

reader::reader()
{
	name = "unnamed";
}

string reader::getName() const // Get the name
{
	return name;
}

string reader::getNumber() const // Get student number
{
	return number;
}

string reader::getCode() const // Get password
{
	return code;
}

void reader::setName(string n) // Set name
{
	name = n;
}

void reader::setNumber(string nu) // Set student number
{
	number = nu;
}

void reader::setCode(string c) // Set password
{
	code = c;
}

int reader::getInformation() // Verification information
{
	cout << "Welcome to the library management system!" << endl;
	string a, b, t;
	cout << "Please enter your name:" << endl;
	cin >> a;
	cout << "Please enter your student ID:" << endl;
	cin >> b;
	cout << "Please enter password: (initial password is student ID)" << endl;
	cin >> t;

	string n, nu, c;
	ifstream in("student.txt"); // Open the file
	int i = 0;					// label to determine whether the account exists or not
	do
	{

		if (in.eof()) // The end of the file ends
			break;
		string s;			  // define variables
		getline(in, s);		  // Read each line
		istringstream sin(s); // define sin stream
		sin >> n >> nu >> c;
		if ((a == n) && (b == nu) && (c == t)) // Account exists
		{
			i = 1;
			return 1; // return true value
			cout << "Login successful!" << endl;
			break;
		}
	} while (!in.eof()); // Determine whether the end of the file is reached

	if (i == 0) // Account not found
		cout << "Input is incorrect!" << endl;
	return 0;	// return false value
	in.close(); // Close the file
}

void reader::reviseCode() // Revise password
{
	int t = 0;				 // label to determine whether the account exists
	string a, b, c, d, e, f; // define variables
	cout << "Please enter personal information:" << endl;
	cout << "Name:" << endl;
	cin >> d;
	cout << "Student ID:" << endl;
	cin >> e;
	cout << "Password: (Initial password is student ID)" << endl;
	cin >> f;
	ifstream in("student.txt"); // Open the file
	string s1;
	while (getline(in, s1)) // Read data
	{
		istringstream sin(s1); // Define sin1 stream
		sin >> a >> b >> c;
		ofstream out("student1.txt", ios::app); // Open the file for writing
		if ((a == d) && (b == e) && (c == f))	// Judge whether the input is correct
		{
			t = 1;
			string m, p, q; // define variables
			cout << "Please enter the modified information:" << endl;
			cout << "Name:" << endl;
			cin >> m;
			cout << "Student ID:" << endl;
			cin >> p;
			cout << "Password:" << endl;
			cin >> q;
			out << m << " " << p << " " << q << endl;
			cout << "Modification successful" << endl;
		}
		else
			out << a << " " << b << " " << c << endl; // Write unmodified content
		out.close();								  // Close the file
	}
	in.close(); // Close the file

	ifstream filein("student1.txt");		   // Open the document
	ofstream fileout("student.txt", ios::out); // Open the document and clear the content
	string s;
	while (getline(filein, s)) // Write the modified content to the file
	{
		fileout << s << endl;
	}
	filein.close();	 // Close the file
	fileout.close(); // Close the file

	if (t == 0) // Account input error
	{
		cout << "Input error!" << endl;
	}
	system("del student1.txt"); // Delete files
}

void reader::search() // Define query function
{
	book book1;					  // instantiation object
	ifstream filein("store.txt"); // Open the file
	if (!filein)
	{
		cout << "Failed to open file!" << endl;
	}
	else
	{
		cout << "Please enter the title of the book to be queried:" << endl;
		string t; // Enter book title
		cin >> t;
		int m = 0;							// tag to determine whether there is this book
		for (string s; getline(filein, s);) // Judge the title of the read book
		{
			int v;
			string a, x, y, z, u, w; // define variables
			istringstream sin(s);	 // define sin stream
			sin >> a;				 // Read the beginning of each line
			if (t == a)				 // Determine whether the searched book is found
			{
				m++;
				x = a;
				sin >> y >> z >> u >> w >> v; // Read a line of string
				book1.setName(x);			  // Set the book name
				book1.setAuthor(y);			  // Set the author
				book1.setISBN(z);			  // Set ISBN code
				book1.settype(u);			  // Set book items
				book1.setPress(w);			  // Set the publishing house
				book1.setStatue(v);			  // Set status
				book1.printBookInformation(); // output
				break;
			}
		}
		if (m == 0) // Determine whether this book exists
			cout << "The book you are looking for was not found!" << endl;
	}
	filein.close(); // Close the file
}

void reader::borrowBook() // Define the book borrowing function
{
	book book2; // instantiation object
	cout << "Please enter the book name:" << endl;
	ifstream filein("store.txt"); // Open the file
	string t;					  // Enter book title
	cin >> t;
	int m = 0;
	for (string s; getline(filein, s);) // Judge the title of the read book
	{
		int v;
		string a; // Read the beginning of each line
		string x, y, z, u, w;
		istringstream sin(s);
		sin >> a;
		if (t == a) // Determine whether the borrowed book is found
		{
			m++;
			x = a;
			sin >> y >> z >> u >> w >> v; // Read a line of string
			book2.setName(x);			  // Set the book name
			book2.setAuthor(y);			  // Set the author
			book2.setISBN(z);			  // Set ISBN code
			book2.settype(u);			  // Set book items
			book2.setPress(w);			  // Set the publishing house
			book2.setStatue(v);			  // Set status
			book2.printBookInformation(); // output
			break;
		}
	}

	if (m == 0) // Determine whether this book exists
		cout << "The book to be borrowed was not found!" << endl;
	filein.close(); // Close the file

	if (book2.getbookStatue() == 0) // Whether you are in the library
	{
		cout << "Do you want to borrow books? (Y: Yes, N: No)" << endl;
		char n;
		cin >> n;
		if (n == 'Y')
		{
			cout << "Book title:" << t << endl;
			cout << "Borrowing successfully!" << endl;
			ifstream filein("store.txt"); // Open the file
			do
			{
				string x, y, z, u, w; // define variables
				string s;
				getline(filein, s); // Read each line
				istringstream sin(s);
				sin >> x;									// give the first string in s to a
				ofstream fileout("restore1.txt", ios::app); // Write to a new file

				if (t != x)				  // Determine whether it is a modified place
					fileout << s << endl; // Write data

				if (t == x) // Determine whether it is a modified place
				{
					sin >> y >> z >> u >> w; // Read a line of string
					book2.setName(x);		 // Set the book name
					book2.setAuthor(y);		 // Set the author
					book2.setISBN(z);		 // Set ISBN code
					book2.settype(u);		 // Set book items
					book2.setPress(w);		 // Set the publishing house
					book2.setStatue(1);		 // Set status
					fileout << book2.getName() << " " << book2.getbookAuthor() << " " << book2.getbookISBN() << " " << book2.gettype()
							<< " " << book2.getbookPress() << " " << book2.getbookStatue() << endl;
					fileout.close(); // Close the file
				}

			} while (!filein.eof()); // Determine whether the end of the file is reached
			filein.close();			 // Close

			ifstream filei("restore1.txt");			 // Open the document
			ofstream fileout("store.txt", ios::out); // Open the document and clear the content
			for (string s; getline(filei, s);)		 // Write the modified content to the file
			{
				fileout << s << endl;
			}
			filei.close(); // Close the file
			fileout.close();
			system("del restore1.txt"); // Delete file copy
		}

		else if (n == 'N')
		{
			cout << "No books borrowed!" << endl;
		}
		else
		{
			cout << "Input error!" << endl;
		}
	}
	else // already borrowed and cannot be borrowed again
	{
		cout << "The book has been checked out!" << endl;
		system("pause");
	}
}

void reader::returnBook() // Define the book return function
{
	book book3; // instantiation object
	cout << "Please enter the book name:" << endl;
	ifstream filein("store.txt"); // Open the file
	string t;					  // Enter book title
	cin >> t;
	int m = 0;							// Tag, whether there is this book
	for (string s; getline(filein, s);) // Judge the title of the read book
	{
		int v;
		string a; // Read the beginning of each line
		string x, y, z, u, w;
		istringstream sin(s);
		sin >> a;
		if (t == a) // Determine whether the borrowed book is found
		{
			m++;
			x = a;
			sin >> y >> z >> u >> w >> v; // Read a line of string
			book3.setName(x);			  // Set the book name
			book3.setAuthor(y);			  // Set the author
			book3.setISBN(z);			  // Set ISBN code
			book3.settype(u);			  // Set book items
			book3.setPress(w);			  // Set the publishing house
			book3.setStatue(v);			  // Set status
			book3.printBookInformation(); // output
			break;
		}
	}
	if (m == 0) // Determine whether this book exists
		cout << "The book to be returned was not found!" << endl;
	filein.close();					// Close the file
	if (book3.getbookStatue() != 0) // Determine whether it has been lent out
	{
		cout << "Return the book? (Y: Yes, N: No)" << endl;
		char n;
		cin >> n;
		if (n == 'Y')
		{
			cout << "Book title:" << t << endl;
			cout << "Return the book successfully!" << endl;
			ifstream filein("store.txt");
			do
			{
				string x, y, z, u, w; // define variables
				string s;
				getline(filein, s); // Read each line
				istringstream sin(s);
				sin >> x;									// give the first string in s to a
				ofstream fileout("restore2.txt", ios::app); // Write to a new file
				if (t != x)									// Determine whether it is a modified place
					fileout << s << endl;					// Write data
				if (t == x)									// Determine whether it is a modified place
				{
					sin >> y >> z >> u >> w; // Read a line of string
					book3.setName(x);		 // Set the book name
					book3.setAuthor(y);		 // Set the author
					book3.setISBN(z);		 // Set ISBN code
					book3.settype(u);		 // Set book items
					book3.setPress(w);		 // Set the publishing house
					book3.setStatue(0);		 // Set status
					fileout << book3.getName() << " " << book3.getbookAuthor() << " " << book3.getbookISBN() << " " << book3.gettype()
							<< " " << book3.getbookPress() << " " << book3.getbookStatue() << endl; // Write the corresponding value
					fileout.close();
				}

			} while (!filein.eof()); // Determine whether the end of the file is reached
			filein.close();			 // Close

			ifstream filei("restore2.txt");			 // Open the document
			ofstream fileout("store.txt", ios::out); // Open the document and clear the content
			for (string s; getline(filei, s);)		 // Write the modified content to the file
			{
				fileout << s << endl;
			}
			filei.close();				// Close the file
			fileout.close();			// Close the file
			system("del restore2.txt"); // Delete file copy
		}
		else if (n == 'N')
		{
			cout << "The book has not been returned!" << endl;
		}
		else
		{
			cout << "Input error!" << endl;
		}
	}
	else
	{
		cout << "The book has not been checked out" << endl;
		system("pause");
	}
}

reader::~reader()
{
}