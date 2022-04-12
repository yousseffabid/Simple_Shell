#include "shell.h"
/**
 *_pow - raises x to power of y
 *@number: x
 *@exponent: y
 *Return: result
 */
int _pow(int number, int exponent)
{
	int i, result;

	if (exponent == 0)
		return (1);
	i = 0;
	result = 1;
	while (i < exponent)
	{
		result *= number;
		i++;
	}

	return (result);
}
/**
 * _atoi - asci to integer
 * @string : Input
 *
 * Return: integer equivalent of asci char
 */
int _atoi(char *string)
{
	int i, flag, result, expo;

	flag = 0;
	if (string[0] == '-')
	{
		flag = 1;
		string[0] = '0';
	}
	expo = 0;
	result = 0;
	for (i = _strlen(string) - 1; i >= 0; i--)
	{
		result += (string[i] - '0') * _pow(10, expo);
		expo++;
	}
	if (flag == 1)
	{
		if (result <= 256)
			result = 256 - result;
		else
			result = 256 - (result - 256);
	}

	return (result);

}
