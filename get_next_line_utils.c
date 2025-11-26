/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhend <mhend@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:17:32 by mhend             #+#    #+#             */
/*   Updated: 2025/11/24 23:39:55 by mhend            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  strlenn(const char *s)
{
    size_t  i;
    
    i = 0;
    while (s[i])
        i++;
    return (i);
}

char *strchrr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
            return ((char *)s);
        s++;
    }
    if ((char)c == '\0')
        return ((char *)s);
    return (NULL);
}

char    *strjoinn(char const *s1, char const *s2)
{
    char    *s;
    size_t  s1len;
    size_t  s2len;
    size_t  tot;
    int     i;
    int     j;

    if (!s1 || !s2)
        return (NULL);
    s1len = strlenn(s1);
    s2len = strlenn(s2);
    tot = s1len + s2len;
    s = malloc(sizeof(char) * tot + 1);
    if (!s)
        return (NULL);
    while (*s1)
    {
        *s = *s1;
        s1++;
    }
    while (*s2)
    {
        
    }
}


