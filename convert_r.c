#include "main.h"

/**
 * convert_r -  a function that handles the conversion r
 * @args: a pointer
 * @output: a pointer to the output
 * @flags: to handle flags
 * @wid: to handle the width
 * @prec: precetions
 * @len: length
 * Return: ret
 */

unsigned int convert_r(va_list args, buffer_t *output,
		unsigned char flags, int wid, int prec, unsigned char len)
{
	char *str, *null = "(null)";
	int size, i;
	unsigned int ret = 0;

	(void)len;

	str = va_arg(args, char *);
	if (str == NULL)
		return (_memcpy(output, null, 6));

	for (size = 0; *(str + size);)
		size++;

	if (prec != -1 && prec < size)
	{
		size = prec;
	}

	ret += print_string_width(output, flags, wid, prec, size);

	for (i = size - 1; i >= 0; i--)
		ret += _memcpy(output, (str + i), 1);

	ret += print_neg_width(output, size, flags, wid);
	return (ret);
}
