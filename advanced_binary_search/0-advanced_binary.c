#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 * @array: The array to print
 * @left: The starting index
 * @right: The ending index
 */
void print_array(int *array, size_t left, size_t right)
{
    size_t i;

    printf("Searching in array: ");
    for (i = left; i <= right; i++)
    {
        printf("%d", array[i]);
        if (i < right)
            printf(", ");
    }
    printf("\n");
}

/**
 * advanced_binary_recursive - Recursively searches for a
 * value in a sorted array
 * @array: The array to search
 * @left: The starting index
 * @right: The ending index
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
    size_t mid;

    if (left > right)
        return (-1);

    print_array(array, left, right);

    mid = left + (right - left) / 2;
    if (array[mid] == value && (mid == left || array[mid - 1] != value))
        return (mid);

    if (array[mid] >= value)
        return (advanced_binary_recursive(array, left, mid, value));
    else
        return (advanced_binary_recursive(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array of integers
 * @array: The array to search
 * @size: The size of the array
 * @value: The value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return (-1);

    return (advanced_binary_recursive(array, 0, size - 1, value));
}
