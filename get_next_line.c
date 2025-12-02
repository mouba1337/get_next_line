/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhend <mhend@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 01:56:32 by mhend             #+#    #+#             */
/*   Updated: 2025/12/02 00:25:52 by mhend            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *read_to(int fd, char *stash)
{
    char    *buffer;
    int bytes_read;

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (free(stash), NULL);
    bytes_read = 1;
     while (bytes_read > 0 && (!stash || !strchrr(stash, '\n')))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read == -1)
        {
            free (buffer);
            free (stash);
            return (NULL);
        }
        buffer[bytes_read] = '\0';
        stash = strjoinn(stash, buffer);
    }
        free(buffer);
        return (stash);
}

static char     *extract(char  *stash)
{
    int     i;
    char    *ptr;

    i = 0;
    if (!stash[i])
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    ptr = substrr(stash, 0, i + (stash[i] == '\n'));
    return (ptr);
}

static char     *update(char *stash)
{
    int     i;
    char    *new;

    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    new = substrr(stash, i + 1, strlenn(stash) - i);
    free(stash);
    return (new);
}

char    *get_next_line(int fd)
{
    static char *stash;
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = read_to(fd, stash);
    if (!stash)
        return (NULL);
    line = extract(stash);
    stash = update(stash);
    return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
    int     fd;
    char    *line;
    
    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
        return(1);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
