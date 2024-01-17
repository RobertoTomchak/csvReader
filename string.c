#include <stdlib.h>
#include <stddef.h>

#include "string.h"

/*
	createString(size_t n): creates an empty string
	@parameters:
		n: initial size of string
	@return: pointer to an empty string
*/
struct String *createString(size_t n)
{
	struct String *s = malloc(sizeof(struct String));
	if (!s)
		return NULL;

	// size must be n+1 to allocate space for '\0'
	s->text = malloc(sizeof(char) * (n + 1));
	if (!s->text)
		return NULL;
	s->text[0] = '\0';

	s->size = 0;
	s->capacity = n;

	return s;
}

/*
	initializeString(struct String *s): sets given string to empty string
	@parameters:
		s: pointer to string
	@return: none
*/
void initializeString(struct String *s)
{
	s->text = malloc(sizeof(char));
	if (!s->text)
		return;
	s->text[0] = '\0';
	s->size = 0;
	s->capacity = 0;
}

/*
	addChar(struct String *s, char c): adds char to end of string
	@parameters:
		*s: pointer to string to be modified
		 c: char to be added to s
	@return: 1 if successfull; 0 otherwise
*/ 
int addChar(struct String *s, char c)
{
	// if doesnt fit capacity, double capacity
	if (s->size + 1 >= s->capacity) {
		size_t newCapacity = 2 * (s->capacity + 1);
		char *temp = realloc(s->text, newCapacity);
		if (!temp)
			return 0;	
		s->text = temp;
		s->capacity = newCapacity;
	}
	s->text[s->size] = c;
	s->text[s->size + 1] = '\0';
	s->size++;
	return 1;	
}

/*
	concatenate(struct String *s1, struct String *s2): concatenates both string
	@parameters:
		*s1: pointer to first string
		*s2: pointer to second string
	@return: pointer to concatenated string
*/
struct String *concatenate(struct String *s1, struct String *s2)
{
	// s3 = s1 + s2
	struct String *s3 = malloc(sizeof(struct String));
	if (!s3)
		return NULL;

	// size needs +1 to allocate space for '\0'
	s3->text = malloc(sizeof(char) * (s1->size + s2->size + 1));
	if (!s3->text)
		return NULL;
	for (int i = 0; i < s1->size; i++)
		s3->text[i] = s1->text[i];
	for (int i = 0; i < s2->size; i++)
		s3->text[i+s1->size] = s2->text[i];
	s3->text[s1->size+s2->size] = '\0';

	s3->size = s1->size + s2->size;
	s3->capacity = s1->size + s2->size;

	return s3;
}

/*
	sizeString(struct String *s): returns size of string
	@parameters:
		*s: pointer to string
	@return: size of given string
*/
size_t sizeString(struct String *s)
{
	return s->size;
}

/*
	freeString(struct String *s): frees memory allocated to given string
	@parameters:
		*s: pointer to string to be freed
	@return: none
*/

void freeString(struct String *s)
{
	free(s->text);
	free(s);
	return;
}


