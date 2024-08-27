#!/usr/bin/python3


def rain(walls):
    """
    Calculates the amount of rainwater trapped between walls after rainfall.

    This function processes a list of integers representing wall heights aligned on a grid. 
    Each wall has a width of 1 unit. It returns the total amount of water that can be trapped 
    between the walls after it rains.
    """
    if not walls:
        return 0

    left = 0
    right = len(walls) - 1
    water = 0

    left_max = walls[left]
    right_max = walls[right]

    while left < right:
        if walls[left] < walls[right]:
            left += 1
            if walls[left] < left_max:
                water += left_max - walls[left]
            else:
                left_max = walls[left]
        else:
            right -= 1
            if walls[right] < right_max:
                water += right_max - walls[right]
            else:
                right_max = walls[right]

    return water
