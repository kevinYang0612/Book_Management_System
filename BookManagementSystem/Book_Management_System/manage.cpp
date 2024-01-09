#include "manage.h"
#include "book.h"
manage::manage() // Destructor
{
}

int manage::getManage() // Login function
{
	cout << "Welcome to the library management system!" << endl;
	string a, b;
	cout << "Please enter your account number:" << endl;
	cin >> a;
	cout << "Please enter password:" << endl;
	cin >> b;
	string n, c;
	ifstream in("manage.txt"); // Open the file
	int i = 0;				   // label to determine whether the account exists or not
	do
	{
		if (in.eof()) // The end of the file ends
			break;

		string s;
		getline(in, s);		  // Read each line
		istringstream sin(s); // define sin stream
		sin >> n >> c;
		if ((a == n) && (c == b)) // Judge whether it exists
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

void manage::reviseInformation() // Modify information function
{
	int t = 0; // Tag, whether the account exists
	string a, b, c, d;
	cout << "Please enter personal information:" << endl;
	cout << "Account:" << endl;
	cin >> c;
	cout << "Password:" << endl;
	cin >> d;
	ifstream in("manage.txt"); // Open the file
	string s1;
	while (getline(in, s1)) // Read data
	{
		istringstream sin(s1); // Define sin stream
		sin >> a >> b;
		ofstream out("manage1.txt", ios::app); // Open the file
		if ((a == c) && (b == d))			   // This account exists
		{
			t = 1;
			string m, p;
			cout << "Please enter the modified information:" << endl;
			cout << "Name:" << endl;
			cin >> m;
			cout << "Password:" << endl;
			cin >> p;
			out << m << " " << p << endl;
			cout << "Modification successful" << endl;
		}
		else
			out << a << " " << b << endl; // Unmodified
		out.close();					  // Close the file
	}
	in.close(); // Close the file

	ifstream filein("manage1.txt");			  // Open the document
	ofstream fileout("manage.txt", ios::out); // Open the document and clear the content
	string s;
	while (getline(filein, s)) // Write the modified content to the file
	{
		fileout << s << endl;
	}
	filein.close();	 // Close the file
	fileout.close(); // Close the file

	if (t == 0) // This account does not exist
	{
		cout << "Input error!" << endl;
	}
	system("del manage1.txt");
}

void manage::add() // Define the add book function
{
	book book1;								 // instantiation object
	ofstream fileout("store.txt", ios::app); // Open the file
	if (!fileout)
	{
		cout << "Cannot open file!"
			 << "store.txt" << endl;
	}
	else
	{
		cout << "Please enter basic information about the book:" << endl;
		book1.readBookInformation(); // Read information
		fileout << book1.getName() << " " << book1.getbookAuthor() << " " << book1.getbookISBN() << " " << book1.gettype()
				<< " " << book1.getbookPress() << " " << book1.getbookStatue() << endl; // Write information
	}
	fileout.close(); // Close the file
}

void manage::revise() // Define the function to modify book information
{
	book book1;					  // instantiation object
	ifstream filein("store.txt"); // Open the file
	if (!filein)
	{
		cout << "Failed to open file!" << endl;
	}
	else
	{
		cout << "Please enter the title of the book to be modified:" << endl;
		int n = 0; // Tag, whether there is this book
		string t;  // Enter book title
		cin >> t;
		do
		{
			int v; // define variables
			string x, y, z, u, w;
			string s;
			getline(filein, s); // Read each line
			istringstream sin(s);
			sin >> x;								   // give the first string in s to a
			ofstream fileout("restore.txt", ios::app); // Write to a new file

			if (t != x)				  // Determine whether it is a modified place
				fileout << s << endl; // Write data

			if (t == x) // Determine whether it is a modified place
			{
				n = 1;
				sin >> y >> z >> u >> w >> v; // Read a line of string
				book1.setName(x);			  // Set the book name
				book1.setAuthor(y);			  // Set the author
				book1.setISBN(z);			  // Set ISBN code
				book1.settype(u);			  // Set book items
				book1.setPress(w);			  // Set the publishing house
				book1.setStatue(v);			  // Set status
				cout << "The original book information is:" << endl;
				book1.printBookInformation(); // output

				cout << "Please enter the modified book information:" << endl;
				book1.readBookInformation(); // Reread
				fileout << book1.getName() << " " << book1.getbookAuthor() << " " << book1.getbookISBN() << " " << book1.gettype()
						<< " " << book1.getbookPress() << " " << book1.getbookStatue() << endl; // Write to file
				fileout.close();																// Close the file
			}

		} while (!filein.eof()); // Determine whether the end of the file is reached
		if (n == 0)				 // This book does not exist
			cout << "The book to be modified was not found!" << endl;
	}
	filein.close(); // Close

	ifstream filei("restore.txt");			 // Open the document
	ofstream fileout("store.txt", ios::out); // Open the document and clear the content

	for (string s; getline(filei, s);) // Write the modified content to the file
	{
		fileout << s << endl;
	}
	filei.close();			   // Close the file
	fileout.close();		   // Close the file
	system("del restore.txt"); // Delete file copy
}

void manage::deleteBook()
{
	book book2;					  // instantiation object
	ifstream filein("store.txt"); // Open the file
	if (!filein)
	{
		cout << "Failed to open file!" << endl;
	}
	else
	{
		cout << "Please enter the title of the book to be deleted:" << endl;
		int n = 0; // Tag, whether there is this book
		string t;  // Enter book title
		cin >> t;
		do
		{
			int v; // define variables
			string x, y, z, u, w;
			string s;
			getline(filein, s); // Read each line
			istringstream sin(s);
			sin >> x;								   // give the first string in s to a
			ofstream fileout("restore.txt", ios::app); // Write to a new file

			if (t != x)				  // Determine whether it is a deleted place
				fileout << s << endl; // Write data

			if (t == x) // Determine whether it is a deleted place
			{
				n = 1;
				sin >> y >> z >> u >> w >> v; // Read a line of string
				book2.setName(x);			  // Set the book name
				book2.setAuthor(y);			  // Set the author
				book2.setISBN(z);			  // Set ISBN code
				book2.settype(u);			  // Set book items
				book2.setPress(w);			  // Set the publishing house
				book2.setStatue(v);			  // Set status
				cout << "The original book information is:" << endl;
				book2.printBookInformation(); // output

				cout << "Delete? (Y: Yes, N: No)" << endl;
				char a; // define variables
				cin >> a;
				if (a == 'Y')
				{
					cout << "Deletion successful!" << endl;
				}
				if (a == 'N')
				{
					cout << "Not deleted!" << endl;
					fileout << book2.getName() << " " << book2.getbookAuthor() << " " << book2.getbookISBN() << " " << book2.gettype()
							<< " " << book2.getbookPress() << " " << book2.getbookStatue() << endl; // Write to file
				}
				if (a != 'Y' || a != 'N')
				{
					system("pause");
				}
				fileout.close(); // Close the file
			}

		} while (!filein.eof()); // Determine whether the end of the file is reached
		if (n == 0)				 // This book does not exist
			cout << "The book to be deleted was not found!" << endl;
	}
	filein.close(); // Close

	ifstream filei("restore.txt"); // Open the document
	ofstream fileout("store.txt", ios::out);

	for (string s; getline(filei, s);)
	{
		fileout << s << endl;
	}
	filei.close();
	fileout.close();
	system("del restore.txt");
}

void manage::addReader() // Add reader function
{
	ofstream fout("student.txt", ios::app); // Open the file
	string a, b, c;
	cout << "Please enter the corresponding information!" << endl;
	cout << "Name:" << endl;
	cin >> a;
	cout << "Student ID:" << endl;
	cin >> b;
	cout << "Password:" << endl;
	cin >> c;
	fout << a << " " << b << " " << c << " " << endl;
	fout.close(); // Close the file
}

void manage::deleteReader()
{

	ifstream filein("student.txt"); // Open the file
	if (!filein)
	{
		cout << "Failed to open file!" << endl;
	}
	else
	{
		string t, m;
		int n = 0; // Tag, whether there is this reader
		cout << "Please enter the name of the student to be deleted:" << endl;
		cin >> m;
		cout << "Please enter the student number of the deleted student:" << endl;
		cin >> t;
		do
		{
			string x, y, z; // define variables
			string s;
			getline(filein, s); // Read each line
			istringstream sin(s);
			sin >> x >> y >> z;							// give the first string in s to a
			ofstream fileout("student1.txt", ios::app); // Write to a new file

			if (m != x || t != y)	  // Determine whether it is a deleted place
				fileout << s << endl; // Write data

			if (m == x && t == y) // Determine whether it is a deleted place
			{
				n = 1;
				cout << "The original student information is:" << endl;
				cout << "Name:" << x << endl;
				cout << "Student ID:" << y << endl;
				cout << "Password:" << z << endl;
				cout << "Delete? (Y: Yes, N: No)" << endl;
				char a; // define variables
				cin >> a;
				if (a == 'Y')
				{
					cout << "Deletion successful!" << endl;
				}
				if (a == 'N')
				{
					cout << "Not deleted!" << endl;
					fileout << x << " " << y << " " << z << endl; // Write to file
				}
				if (a != 'Y' || a != 'N')
				{
					system("pause");
				}
				fileout.close(); // Close the file
			}

		} while (!filein.eof()); // Determine whether the end of the file is reached
		if (n == 0)				 // This student does not exist
			cout << "The student to be deleted was not found!" << endl;
	}
	filein.close(); // Close

	ifstream filei("student1.txt");			   // Open the document
	ofstream fileout("student.txt", ios::out); // Open the document and clear the content

	for (string s; getline(filei, s);) // Write the modified content to the file
	{
		fileout << s << endl;
	}
	filei.close();				// Close the file
	fileout.close();			// Close the file
	system("del student1.txt"); // Delete file copy
}

manage::~manage() // Destructor
{
}
