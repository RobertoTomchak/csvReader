#ifndef STRING_H
#define STRING_H

#include <stddef.h>
/*
	defines the struct string
	contains a literal string, its size and capacity
	behaves similar to a C++ vector
*/

struct String {
	char *text;
	size_t size;
	size_t capacity;
};

/*
	createString(size_t n): creates an empty string
	@parameters:
		n: initial size of string
	@return: pointer to an empty string
*/
struct String *createString(size_t n);

/*
	initializeString(struct String *s): sets given string to empty string
	@parameters:
		s: pointer to string
	@return: none
*/
void initializeString(struct String *s);

/*
	addChar(struct String *s, char c): adds char to end of string
	@parameters:
		*s: pointer to string to be modified
		 c: char to be added to s
	@return: 1 if successfull; 0 otherwise
*/ 
int addChar(struct String *s, char c);

/*
	concatenate(struct String *s1, struct String *s2): concatenates both string
	@parameters:
		*s1: pointer to first string
		*s2: pointer to second string
	@return: pointer to concatenated string
*/
struct String *concatenate(struct String *s1, struct String *s2);

/*
	sizeString(struct String *s): returns size of string
	@parameters:
		*s: pointer to string
	@return: size of given string
*/
size_t sizeString(struct String *s);

/*
	freeString(struct String *s): frees memory allocated to given string
	@parameters:
		*s: pointer to string to be freed
	@return: none
*/

void freeString(struct String *s);

#endif
