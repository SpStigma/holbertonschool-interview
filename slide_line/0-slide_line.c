#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers, like the game 2048
 * @line: an array of integers containing size elements
 * @size: the size of the sliding array
 * @direction: the direction for sliding & merging (the increment)
 *
 * Return: 1 upon success, 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	int start, end, i, j;

	if (direction == SLIDE_RIGHT)
	{
		start = size - 1;
		end = 0;
	}
	else if (direction == SLIDE_LEFT)
	{
		start = 0;
		end = size - 1;
	}
	else
	{
		return (0);
	}
	for (i = start; i != end; i += direction)
	{
		for (j = i + direction; j != end + direction; j += direction)
		{
			if (line[i] == line[j] && line[i] != 0)
			{
				line[i] += line[j];
				line[j] = 0;
				break;
			}
			if (line[i] == 0)
			{
				line[i] += line[j];
				line[j] = 0;
			}
			else if (line[i] != line[j] && line[j] != 0)
				break;
		}
	}
	return (1);
}
