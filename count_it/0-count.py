#!/usr/bin/python3
"""This is a module"""

import requests


def count_words(subreddit, word_list, after=None, count_dict=None):
    ''''
    Count words.
    '''
    # Initialize the count dictionary and lowercase the word list
    if count_dict is None:
        count_dict = {}
    word_list = [word.lower() for word in word_list]

    # Base URL and headers (user-agent required for Reddit)
    url = f'https://www.reddit.com/r/{subreddit}/hot/.json'
    headers = {'User-Agent': 'KeywordCounter/0.1'}
    params = {'limit': 100, 'after': after}

    # Make the request to the Reddit API
    response = requests.get(url, headers=headers, params=params)

    # If the request fails or the subreddit is invalid, stop here
    if response.status_code != 200:
        return

    # Retrieve the JSON response data
    data = response.json()
    posts = data['data']['children']
    after = data['data']['after']  # 'after' token for paginating posts

    # Count occurrences of the words in each title
    for post in posts:
        title = post['data']['title'].lower().split()

        for word in word_list:
            count_dict[word] = count_dict.get(word, 0) + title.count(word)

    # Base case: If 'after' is None, stop the recursion
    if after is None:
        # Sort the results by occurrence (descending), then alphabetically
        sorted_words = sorted(count_dict.items(), key=lambda x: (-x[1], x[0]))

        # Print the results
        for word, count in sorted_words:
            if count > 0:
                print(f'{word}: {count}')
        return

    # Recursive case: Next request with the new 'after' token
    return count_words(subreddit, word_list, after, count_dict)
