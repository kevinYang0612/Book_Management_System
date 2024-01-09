# Library Management System

## Overview

Design Requirements

1. Basically complete the design of the library system, including basic functions, no interface design.
2. There should be a clear classification, with different functions for different entrants, and the functions should be complete.
3. There should be basic maintenance functions to complete the basic functional requirements for books and loginers.

Design Ideas

1. Write basic classes, including three classes: book, manage, and reader, complete the definition of the class Implement, implement the corresponding functions.
2. According to the functional requirements of the library system, implement the calling and implementation of functions between classes, and make more standardized modifications to the structure of the classes to complete the library function.
3. Write the main function, call the corresponding functions of the class, associate the various functions, complete the writing of the menu function, be able to realize the jump of the interface, and test the corresponding functions.
4. Debug each functional function, find errors, and make modifications.

## Features

### Administrator Functions

1. Administrator (not logged in)
* Login
* Modify personal information
2. Administrator (after logging in)
* Add reader
* Delete reader
* Add book information
* Modify book information
* Delete book information


### Reader Functions

3. Reader (not logged in)
* Login
* Modify personal information
4. Reader (after logging in)
* Search books
* Borrow books
* Return books

## Problems and Solutions Encountered in the Program

1. File input and output Use the text method to write to the file, using the file stream fstream, and use the append mode to write when writing multiple times to implement file saving.

2. Implement modification and deletion in the file Create a file copy, write the modified content to the copy file, then write the content of the copy file to the original file, and finally delete the copy file. When modifying a book, add a label variable to determine whether the book is found. After finding it, add 1 to the variable value to implement the mark. When deleting, first search, the same as modification, and then do not write the deleted content when writing to the copy file, to implement deletion.

3. Window jumping There is a main window, and there are two windows belonging to readers and administrators, respectively, each corresponding to the corresponding functions. Use the nested switch statement method to implement the gradual entry of the window.

4. Use the method of function encapsulation The code in the main function is very small, which looks very simple. The function functions are all encapsulated, and the menu function is also encapsulated, and the function is called directly, which looks clear.


## Future Improvements

Implement a more comprehensive search function.
Improve code efficiency and structure.
Add a user-friendly interface.
Explore database integration for better data management.

## Getting Started

Clone or download this repository.
Compile and run the main program file.
Follow the prompts in the console to interact with the system.

## Additional Comments

The library management system is a basic system with good functionality. It can meet the basic needs of library management. However, there are still some shortcomings, such as:

The search function is not perfect. It can only be searched by book name. It is recommended to add the ability to search by author, publisher, and other information.
The system uses a lot of for loop statements, which makes the code a bit redundant. It is recommended to use more efficient data structures and algorithms to improve the performance of the system.
The code optimization is not enough. Many codes are very complex, which can be further simplified to improve readability and maintainability.
Overall, the library management system is a good starting point for learning about library management systems. It can be used as a reference for the development of more advanced library management systems.


## Contributing

We welcome contributions to this project! Feel free to submit pull requests or open issues for any improvements or bug fixes

