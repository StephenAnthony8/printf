#include "main.h"
/**
 * int_count - iterates through the values of the number
 * @m: input value
 * Return: number of integers
 */
int int_count(int m)
{
	int n = 10, o, count = 0;


	o = m;
	if (m < 10)
	{
		count++;
		return (count);
	}

	while (m != 0)
	{
		if ((m / n) > 9)
		{
			n = n * 10;
		}
		else if ((m / n) <= 9)
		{
			count++;
			m = m % n;
			n = n / 10;

		}
	}
	while (o % 10 == 0)
	{
		count++;
		o = o / 10;
	}
	return (count);
}
/**
 * num_val - prints out numbers using _outp()
 * @n: input value
 * Return: count value
 */

int num_val(int n)
{
	int count;

	count = 0;
	if (n > 0)
		count = int_count(n);
	else if (n < 0)
	{
		count++;
		n = (-n);
		count += int_count(n);
	}
	else
		count = 1;
	return (count);
}
