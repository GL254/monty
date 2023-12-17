#include "monty.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 for success, any other for fail.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	if (strlen(s1) != strlen(s2))
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
