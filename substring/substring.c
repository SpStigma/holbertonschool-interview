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
	char *temp_str;
	int i, j;

	temp_str = (char *)malloc(word_len * nb_words + 1);
	if (!temp_str)
		return (0);

	for (i = 0; i < nb_words; i++) {
		for (j = 0; j < word_len; j++) {
			temp_str[i * word_len + j] = s[start + i * word_len + j];
		}
	}
	temp_str[word_len * nb_words] = '\0';

	for (i = 0; i < nb_words; i++) {
		int found = 0;
		for (j = 0; j < nb_words; j++) {
			if (strcmp(temp_str + i * word_len, words[j]) == 0) {
				found = 1;
				break;
			}
		}
		if (!found) {
			free(temp_str);
			return (0);
		}
	}

	free(temp_str);
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
	int word_len, i, j, s_len, *indices, index_count = 0;

	if (nb_words == 0 || !s || !words)
		return (NULL);

	word_len = strlen(words[0]);
	s_len = strlen(s);

	if (s_len < word_len * nb_words)
		return (NULL);

	indices = (int *)malloc(sizeof(int) * (s_len - word_len * nb_words + 1));
	if (!indices)
		return (NULL);

	for (i = 0; i <= s_len - word_len * nb_words; i++) {
		if (is_valid_substring(s, i, word_len, nb_words, words)) {
			indices[index_count++] = i;
		}
	}

	if (index_count == 0) {
		free(indices);
		return (NULL);
	}

	*n = index_count;
	return (indices);
}
