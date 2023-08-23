#include "main.h"

/**
 * convert_o - Converts an unsigned int to octal and
 *             stores it to a buffer contained in a struct.
 * @args: A va_list poinitng to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */

unsigned int convert_o(va_list args, buffer_t *output,
		 unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;
	char zero = '0';

	if (len == LONG)
	{
		num = va_arg(args, unsigned long int);
	}

	else
	{
		num = va_arg(args, unsigned int);
	}

	if (len == SHORT)
	{
		num = (unsigned short)num;
	}

	if (HASH_FLAG == 1 && num != 0)
	{
		ret += _memcpy(output, &zero, 1);
	}

	if (!(num == 0 && prec == 0))
	{
		ret += convert_ubase(output, num, "01234567", flags, wid, prec);
	}

	ret += print_neg_width(output, ret, flags, wid);
	return (ret);
}
