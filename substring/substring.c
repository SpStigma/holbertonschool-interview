#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * is_valid_substring - Check if a substring starting at `start` is a valid
 * concatenation of words in `words`.
 * @s: The string to check.
 * @start: The starting index of the substring.
 * @word_len: The length of each word.
 * @nb_words: The number of words.
 * @words: The array of words.
 *
 * Return: 1 if valid, 0 if not.
 */
static int is_valid_substring(char const *s, int start, int word_len,
		int nb_words, char const **words)
{
	int i, j;
	int *word_used = (int *)malloc(sizeof(int) * nb_words);

	if (!word_used)
		return (0);

	memset(word_used, 0, sizeof(int) * nb_words);

	for (i = 0; i < nb_words; i++)
	{
		for (j = 0; j < nb_words; j++)
		{
			if (!word_used[j] &&
					strncmp(s + start + i * word_len, words[j], word_len) == 0)
			{
				word_used[j] = 1;
				break;
			}
		}
		if (j == nb_words)
		{
			free(word_used);
			return (0);
		}
	}

	free(word_used);
	return (1);
}

/**
 * find_substring - Find all substrings that are concatenations of words.
 * @s: The string to scan.
 * @words: Array of words to form substrings.
 * @nb_words: Number of words.
 * @n: Pointer to store the number of valid substrings found.
 *
 * Return: Array of starting indices of valid substrings, or NULL if none.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int word_len, i, s_len, *indices, index_count = 0;

	if (nb_words == 0 || !s || !words)
		return (NULL);

	word_len = strlen(words[0]);
	s_len = strlen(s);

	if (s_len < word_len * nb_words)
		return (NULL);

	indices = (int *)malloc(sizeof(int) * (s_len - word_len * nb_words + 1));
	if (!indices)
		return (NULL);

	for (i = 0; i <= s_len - word_len * nb_words; i++)
	{
		if (is_valid_substring(s, i, word_len, nb_words, words))
		{
			indices[index_count++] = i;
		}
	}

	if (index_count == 0)
	{
		free(indices);
		return (NULL);
	}

	*n = index_count;
	return (indices);
}
