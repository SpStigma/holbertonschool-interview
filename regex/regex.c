#include "regex.h"

/**
 * regex_match - Checks if a pattern matches a given string.
 * @str: The string to scan.
 * @pattern: The regular expression pattern.
 *
 * Return: 1 if the pattern matches the string, otherwise 0.
 */
int regex_match(const char *str, const char *pattern)
{
	int first_match;

	/* If the pattern is empty, the string must also be empty */
	if (*pattern == '\0')
		return (*str == '\0');

	/* Check if the first character matches */
	first_match = (*str != '\0' && (*str == *pattern || *pattern == '.'));

	/* Handle '*' in the pattern */
	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
			(first_match && regex_match(str + 1, pattern)));
	}

	/* Proceed with the next characters */
	return (first_match && regex_match(str + 1, pattern + 1));
}
