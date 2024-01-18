#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#include "string.h"
#include "csv.h"

bool readData (FILE* ptr, char delimiter, struct String* data)
{
	char c;
	c = fgetc(ptr);
	while (c != EOF && c != '\n') {
		if (c == delimiter)
			return true;
		addChar(data, c);
		c = fgetc(ptr);
	}
	return false;
}

/*
	readCSV: reads the content of a CSV file
	@parameters:
		file: name of csv file
		delimiter: character used as delimiter in the csv file
		hasTitle: if columns have title or not
	@return: a pointer to the Table structure with the content of the csv file
*/
struct Table* readCSV(char* file, char delimiter, bool hasTitle)
{
	// counting number of lines and columns
	// if sees any inconsistents, returns NULL
	size_t num_lines = 0, num_columns = 0;
	FILE* ptr = fopen(file, "r");
	if (!ptr)
		return NULL;
	char c = fgetc(ptr);
	while (c != EOF) {
		if (c == delimiter)
			num_columns++;
		else if (c == '\n')
			num_lines++;
		c = fgetc(ptr);
	}

	fclose(ptr);
	num_columns = num_columns / num_lines + 1;
	if (hasTitle) 
		num_lines--;
	
	// allocates memory for csv content
	struct Table* table = malloc(sizeof(struct Table));
	table->num_lines = num_lines;
	table->num_columns = num_columns;
	table->columns = malloc(num_columns * sizeof(struct Column));
	for (size_t i = 0; i < num_columns; i++) {
		struct String* temp = createString(0);
		table->columns[i].title = *temp;
		free(temp);
		table->columns[i].size = num_lines;
		table->columns[i].data = malloc(num_lines * sizeof(struct String));
		for (size_t j = 0; j < num_lines; j++)
			initializeString(&(table->columns[i].data[j]));
	}

	// stores data
	ptr = fopen(file, "r");
	if (!ptr)
		return NULL;

	// title (if none, all titles are "")
	if (hasTitle) {
		for (size_t i = 0; i < num_columns; i++) {
			readData(ptr, delimiter, &(table->columns[i].title));
		}
	}
	
	for (size_t i = 0; i < num_lines; i++) {
		for (size_t j = 0; j < num_columns; j++) {
			readData(ptr, delimiter, &(table->columns[j].data[i]));
		}
	}
	fclose(ptr);
	return table;
}

/*
	getColumn: gets column with given title
	@parameters:
		table: pointer to table
		title: title of desired column
	@return: pointer to column (NULL if not found)	
*/
struct Column* getColumn(struct Table* table, char* title)
{
	for (size_t i = 0; i < table->num_columns; i++) {
		struct Column* col = &(table->columns[i]);
		// check if title is the same
		bool isSame = true;
		char* temp1 = title;
		char* temp2 = col->title.text;
		while (*temp1 && *temp2) {
			if (*temp1 != *temp2) {
				isSame = false;
				break;
			}
			temp1++; temp2++;
		}
		if (isSame)
			return col;
	}
	return NULL;
}

/*
	ctoi: turns the data of a column into integers
	@parameters:
		column: pointer to column with data
	@return: integer array with contents of column
*/
int *ctoi (struct Column* column)
{
	int* data = malloc(column->size * sizeof(int));
	for (int i = 0; i < column->size; i++)
		data[i] = atoi(column->data[i].text);
	return data;
}

/*
	freeTable: frees given tablr and all of its contents
	@parameters:
		table: pointer to table
	@return: none
*/
void freeTable(struct Table* table)
{
	// free columns
	for (size_t i = 0; i < table->num_columns; i++) {
		free(table->columns[i].title.text);
		for (size_t j = 0; j < table->columns[i].size; j++)
			free(table->columns[i].data[j].text);
		free(table->columns[i].data);
	}
	free(table->columns);
	free(table);
}
