#include "main.h"

/**
 * _strdup - returns a pointer to a new string which is a
 * duplicate of the string str
 * @str: string to be duplicated
 * Return: pointer to the duplicated string
 */

char *_strdup(char *str)
{
	int i;
	char *cp_ptr;

	if (str == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		;
	cp_ptr = malloc(sizeof(char) * (i + 1));
	if (cp_ptr == NULL)
		return (NULL);
	for (i = 0; str[i]; i++)
		cp_ptr[i] = str[i];
	cp_ptr[i] = '\0';
	return (cp_ptr);
}

/**
 * _strlen - returns length of a string
 * @s: takes in a string literal
 * Return: returs the length of the string
 */

int _strlen(char *s)
{
	int i;

	if (s ==  NULL)
		return (0);
	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strcat - concatenate two strings
 * @src: first string
 * @dest: second string
 * Return: a string of src concatenated with dest
 */

char *_strcat(char *src, char *dest)
{
	int len_1, len_2, size;
	char *cat_str;

	if (src == NULL)
		len_1 = 0;
	else
		len_1 = _strlen(src);
	if (dest == NULL)
		len_2 = 0;
	else
		len_2 = _strlen(dest);
	size =  len_1 + len_2 + 2;
	cat_str = malloc(sizeof(char) * size);
	if (src != NULL)
		for (len_1 = 0; src[len_1]; len_1++)
			cat_str[len_1] =  src[len_1];
	cat_str[len_1] = '/';
	len_1++;
	if (dest != NULL)
		for (len_2 = 0; dest[len_2]; len_2++, len_1++)
			cat_str[len_1] = dest[len_2];
	cat_str[len_1] = '\0';
	return (cat_str);
}
/**
<<<<<<< HEAD
 * _strcmp - compare two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: 0 if both are same else -1.
 */
int _strcmp(char *str1, char *str2)
{
	int i = 0, j = 0, cmp = 0;

	while (str1[i] && str2[j])
	{
		if (str1[i] != str2[j])
		{
			cmp = -1;
			break;
		}
		i++;
		j++;
	}
	return (cmp);
=======
 * _strcmp - compares two strings
 * @strcmp1: first string, of two, to be compared in length
 * @strcmp2: second string, of two, to be compared
 * Return: 0 on success, anything else is a failure
 */
int _strcmp(char *strcmp1, char *strcmp2)
{
	int i;

	i = 0;
	while (strcmp1[i] == strcmp2[i])
	{
		if (strcmp1[i + 1] == '\0')
			return (0);
		i++;
	}
	return (strcmp1[i] - strcmp2[i]);
>>>>>>> 210119bfbe8624e2355d7500278e9f000f77ce07
}
