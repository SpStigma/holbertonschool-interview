#!/usr/bin/python3
"""
Module for UTF-8 validation.
"""


def validUTF8(data):
    """
    Determine if a given data set represents a valid UTF-8 encoding.

    A character in UTF-8 can be 1 to 4 bytes long.
    The data set can contain multiple characters.
    Each integer in the list represents 1 byte of data,
    therefore only the 8 least significant
    bits of each integer are considered.
    """
    n_bytes = 0

    mask1 = 1 << 7
    mask2 = 1 << 6

    for num in data:
        mask = 1 << 7
        if n_bytes == 0:
            while mask & num:
                n_bytes += 1
                mask = mask >> 1

            if n_bytes == 0:
                continue

            if n_bytes == 1 or n_bytes > 4:
                return False
        else:
            if not (num & mask1 and not (num & mask2)):
                return False

        n_bytes -= 1

    return n_bytes == 0
