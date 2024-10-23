#!/usr/bin/python3
'''Determine the fewest number of coins needed to meet a given amount total.'''

def makeChange(coins, total):
    '''Calculate the minimum number of coins needed to make the given total.'''
    if total <= 0:
        return 0

    coins.sort(reverse=True)
    num_coins = 0
    reste = total

    for coin in coins:
        if coin <= reste:
            num_coins += reste // coin
            reste %= coin

    if reste == 0:
        return num_coins
    else:
        return -1
