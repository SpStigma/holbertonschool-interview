#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * draw_menger - Draws the character at the given position (x, y) for the sponge.
 * @x: The x coordinate.
 * @y: The y coordinate.
 * @size: The current size of the grid being processed.
 */
void draw_menger(int x, int y, int size)
{
    while (size > 0)
    {
        if ((x / size) % 3 == 1 && (y / size) % 3 == 1)
        {
            printf(" ");
            return;
        }
        size /= 3;
    }
    printf("#");
}

/**
 * menger - Draws a 2D Menger Sponge of the given level.
 * @level: The level of the Menger Sponge.
 */
void menger(int level)
{
    int size;
    int x, y;

    if (level < 0)
    {
        return;
    }

    size = (int)pow(3, level);
    for (y = 0; y < size; y++)
    {
        for (x = 0; x < size; x++)
        {
            draw_menger(x, y, size);
        }
        printf("\n");
    }
}
