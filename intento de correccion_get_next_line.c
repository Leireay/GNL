#include <limits.h>
#include "get_next_line.h"

static void clear_buffer(char buffer[BUFFER_SIZE + 1])
{
    size_t  i;

    i = 0;
    while (i < BUFFER_SIZE + 1)
    {
        buffer[i] = '\0';
        i++;
    }
}

char    *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    char        *output;
    size_t      i;
    ssize_t     bytes_read;

    if (fd < 0 || fd > FOPEN_MAX)
        return (NULL);
    output = NULL;
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\n' && buffer[i + 1])
        strreplace(&output, strnjoin(output, buffer + i + 1, BUFFER_SIZE - i - 1));
    clear_buffer(buffer);
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        i = 0;
        while (buffer[i] && buffer[i] != '\n')
            i++;
        strreplace(&output, strnjoin(output, buffer, i + 1));
        if (buffer[i] == '\n')
            break ;
        clear_buffer(buffer);
    }
    if (bytes_read < 0)
    {
        free(output);
        return (NULL);
    }
    return (output);
}
