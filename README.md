# csvReader
This project is a C library that allows for making code that can read values from a CSV file, to be manipulated inside the software.

## Applications
This library can be used in any type of CSV files, as long as data in the file is separated by an unkown character. For example, if the delimiter is not ',', it's ';', this project can be used. However, only ASCII character can be read, so if the desired CSV file contains non-ASCII values, this library will probably lead to bugs.

## Basic usage
There are three main structures in this library:
- String: contains a C string (array of char that ends in '\0'), the size of the string (number of characters) and the capacity of th string (how many character can be stored without increasing size). This structure can be dinamically increased, similar to the vector structure in C++;
- Column: contains the data of a column of the CSV file. This includes its title (if there is one), its size and the data (stored as strings, can be changed to int with the function ctoi);
- Table: all the data of the CSV file. This included all the columns, as well as its number of lines and number of columns.
<br><br>
Since the structure Table includes all information stored in the CSV file, this is the structure that most functions will use. There's some build-in functions for common manipulation (like get a particular column or turn values into integers), but you can easily build more functions using this structure.

## Verifying
The file "verify.py" does the same as the "main" file generated from make. As you can see, both generate the same answer (with a small differente due to python floats having a bigger precision than C floats).
