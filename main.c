#include <stdlib.h>
#include <stdbool.h>

#include "csv.h"

float average(int* grades, size_t n)
{
	float ans = 0;
	for (size_t i = 0; i < n; i++)
		ans += grades[i];
	return ans / n;
}


int main()
{
	struct Table* table = readCSV("enem_data.csv", ';', true);
	int *grades = ctoi(getColumn(table, "NU_NOTA_REDACAO"));
	printf("Average Grade: %f\n", average(grades, table->num_lines));
	freeTable(table);
	free(grades);
	return 0;	
}
