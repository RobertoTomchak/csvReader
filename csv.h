#ifndef CSV_H
#define CSV_H

#include <stdbool.h>
#include <stdio.h>

#include <stddef.h>
#include "string.h"

/*
	defines the column of a table
	title is the title of the column (if none, is equal to "")
	"data" is an array of strings that keeps all data of that column
	size is the quantity of data in the column (how many lines)
*/
struct Column {
	struct String title;
	struct String *data;
	size_t size;
};

/*
	defines the table, defined by the csv file
	columns is an array of columns
	num_lines is the number of lines in the table
	num_columns is the number of columns in the table
*/
struct Table {
	struct Column *columns;
	size_t num_lines;
	size_t num_columns;
};

/*
	readCSV: reads the content of a CSV file
	@parameters:
		file: name of csv file
		delimiter: character used as delimiter in the csv file
		hasTitle: if columns have title or not
	@return: a pointer to the Table structure with the content of the csv file
*/
struct Table *readCSV(char *file, char delimiter, bool hasTitle);

/*
	getColumn: gets column with given title
	@parameters:
		table: pointer to table
		title: title of desired column
	@return: pointer to column (NULL if not found)	
*/
struct Column *getColumn(struct Table* table, char *title);

/*
	ctoi: turns the data of a column into integers
	@parameters:
		column: pointer to column with data
	@return: integer array with contents of column
*/
int *ctoi (struct Column *column);

/*
	freeTable: frees given tablr and all of its contents
	@parameters:
		table: pointer to table
	@return: none
*/
void freeTable(struct Table* table);

#endif
