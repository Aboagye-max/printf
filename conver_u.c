#include "main.h"

/**
 * convert_u - Converts an unsigned int argument to decimal and
 *               stores it to a buffer contained in a struct.
 * @args: A va_list pointing to the argument to be converted.
 * @flags: Flag modifiers.
 * @wid: A width modifier.
 * @prec: A precision modifier.
 * @len: A length modifier.
 * @output: A buffer_t struct containing a character array.
 *
 * Return: The number of bytes stored to the buffer.
 */

unsigned int convert_u(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	unsigned long int num;
	unsigned int ret = 0;

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

	if (!(num == 0 && prec == 0))
	{
		ret += convert_ubase(output, num, "0123456789", flags, wid, prec);
	}

	ret += print_neg_width(output, ret, flags, wid);
	return (ret);
}
