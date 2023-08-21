#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * flush_buffer - a function that flushes a buffer
 * @buffer: a pointer to the buffer
 * @buffer_index: a pointer to the buffer index
 */

void flush_buffer(char *buffer, int *buffer_index)
{
	buffer[*buffer_index] = '\0';

	write(STDOUT_FILENO, buffer, *buffer_index);

	*buffer_index = 0;
}

`
