#include "holberton.h"
#include <stdlib.h>

/**
 * print_error - Prints "Error" and exits with status 98.
 */
void print_error(void)
{
	char *error_msg = "Error\n";
	int i = 0;

	while (error_msg[i] != '\0')
	{
		_putchar(error_msg[i]);
		i++;
	}
	exit(98);
}

/**
 * check_digits - Checks if a string is composed only of digits.
 * @str: The string to check.
 * Return: 1 if the string is valid, 0 otherwise.
 */
int check_digits(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * multiply - Multiplies two numbers passed as strings.
 * @num1: The first number.
 * @num2: The second number.
 */
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0, i, j;
	char *result;

	while (num1[len1])
		len1++;
	while (num2[len2])
		len2++;

	result = malloc(sizeof(char) * (len1 + len2));
	if (result == NULL)
		exit(98);

	for (i = 0; i < len1 + len2; i++)
		result[i] = '0';

	for (i = len1 - 1; i >= 0; i--)
	{
		for (j = len2 - 1; j >= 0; j--)
		{
			int product = (num1[i] - '0') * (num2[j] - '0');
			int temp = result[i + j + 1] - '0' + product;

			result[i + j + 1] = (temp % 10) + '0';
			result[i + j] += temp / 10;
		}
	}

	print_number(result);
	free(result);
}

/**
 * print_number - Prints the number stored in a string, ignoring leading zeros.
 * @result: The string containing the number.
 */
void print_number(char *result)
{
	int i = 0;

	while (result[i] == '0')
		i++;

	if (result[i] == '\0')
		_putchar('0');
	else
	{
		while (result[i])
		{
			_putchar(result[i]);
			i++;
		}
	}
	_putchar('\n');
}

/**
 * main - Multiplies two positive numbers passed via command-line arguments.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char *argv[])
{
	if (argc != 3 || !check_digits(argv[1]) || !check_digits(argv[2]))
		print_error();

	multiply(argv[1], argv[2]);

	return (0);
}
