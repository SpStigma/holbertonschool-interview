#include "palindrome.h"

/**
 * is_palindrome - Checks if a number is a palindrome.
 * @n: The number to be checked.
 *
 * Return: 1 if the number is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
    unsigned long reversed = 0;
    unsigned long original = n;

    while (n != 0)
    {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    if (original == reversed)
    {
        return (1);
    }
    else
    {
        return (0);
    }
}
