#!/usr/bin/python3
"""Function to see if all box can be unlocked"""


def canUnlockAll(boxes):
    """ Fct to see if all boxes can be unlocked"""

    if boxes is None:
        return False

    numBoxes = len(boxes)
    # Create a list of False of numbox lenght
    unlocked = [False] * numBoxes
    # unlock the first one
    unlocked[0] = True
    # list to stock index found
    keys_stack = [0]

    while keys_stack:
        # Remove and keep the index
        box_index = keys_stack.pop()
        for key in boxes[box_index]:
            if 0 < key < numBoxes and not unlocked[key]:
                # Change False to True in list unlocked
                unlocked[key] = True
                # Add index to keys_stack
                keys_stack.append(key)

    return all(unlocked)
