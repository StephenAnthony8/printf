#include "main.h"
/**
 * prt_int - iterates through the values of the number
 * @m: input value
 */
void prt_int(int m)
{
	int n = 10, o;
	char c;

	o = m;
	if (m < 10)
	{
		c = (m  + '0');
		_outp(&c, 1);
		return;
	}

	while (m != 0)
	{
		if ((m / n) > 9)
		{
			n = n * 10;
		}
		else if ((m / n) <= 9)
		{
			c = ((m / n) + '0');
			_outp(&c, 1);
			m = m % n;
			n = n / 10;
		}
	}
	while (o % 10 == 0)
	{
		c = ((o % 10) + '0');
		_outp(&c, 1);
		o = o / 10;
	}
}
/**
 * num_prt - prints out numbers using _atoi
 * @n: input value
 */

void num_prt(int n)
{
	char c;

	if (n > 0)
		prt_int(n);
	else if (n < 0)
	{
		c = '-';
		_outp(&c, 1);
		n = (-n);
		prt_int(n);
	}
	else
	{
		c = n + '0';
		_outp(&c, 1);
	}
}
