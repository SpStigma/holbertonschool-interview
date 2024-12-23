#!/usr/bin/python3
"""This is a module"""


def isWinner(x, nums):
    """
    Determines the winner of each game and returns
    the player with the most wins.

    Arguments:
    x -- Number of rounds
    nums -- List of integers representing the maximum
    number (n) for each round

    Returns:
    Name of the player with the most wins or None if the
    winner cannot be determined
    """
    if not nums or x < 1:
        return None

    """Precompute primes up to the maximum value
    in nums using the Sieve of Eratosthenes """
    max_n = max(nums)
    primes = [True] * (max_n + 1)
    primes[0] = primes[1] = False  # 0 and 1 are not prime

    for i in range(2, int(max_n ** 0.5) + 1):
        if primes[i]:
            for j in range(i * i, max_n + 1, i):
                primes[j] = False

    # Count the number of primes up to each index
    prime_count = [0] * (max_n + 1)
    for i in range(1, max_n + 1):
        prime_count[i] = prime_count[i - 1] + (1 if primes[i] else 0)

    maria_wins = 0
    ben_wins = 0

    # Determine the winner for each round
    for n in nums:
        if prime_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    else:
        return None
