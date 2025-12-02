/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhend <mhend@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 01:43:43 by mhend             #+#    #+#             */
/*   Updated: 2025/12/02 02:27:38 by mhend            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
    static char *stash[1024];
    char    *line;

    if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
        return (NULL);
    stash[fd] = read_to(fd, stash[fd]);
    if (!stash[fd])
        return (NULL);
    line = extract(stash[fd]);
    stash[fd] = update(stash[fd]);
    return (line);
}

#include <fcntl.h>
#include <stdio.h>

int main()
{
    int     fd1;
    int fd2;
    int fd3;
    char    *line;
    
    fd1 = open("test.txt", O_RDONLY);
    fd2 = open("test33.txt", O_RDONLY);
    fd3 = open("test44.txt", O_RDONLY);
    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
        return(1);
    while (line = get_next_line(fd1))
    {
        printf("%s", line);
        free(line);
    }
    printf("\n");
    printf("\n");
    while (line = get_next_line(fd2))
    {
        printf("%s", line);
        free(line);
    }
    printf("\n\n");
    while (line = get_next_line(fd3))
    {
        printf("%s", line);
        free(line);
    }
    close(fd1);
    close(fd2);
    close(fd3);
}