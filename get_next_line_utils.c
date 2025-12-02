/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhend <mhend@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:17:32 by mhend             #+#    #+#             */
/*   Updated: 2025/11/28 01:49:52 by mhend            ###   ########.fr       */
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

char    *strjoinn(char *s1, char *s2)
{
    char    *s;
    size_t  s1len;
    size_t  s2len;
    size_t  tot;
    int     i;
    int     j;

    if (!s1)
    {
        s1 = malloc(1);
        if (!s1)
            return (NULL);
        s1[0] = '\0';
    }
    if (!s2)
        return (free(s1), NULL);
    s1len = strlenn(s1);
    s2len = strlenn(s2);
    tot = s1len + s2len;
    s = malloc(sizeof(char) * tot + 1);
    if (!s)
        return (free(s1), NULL);
    i = 0;
    while (s1[i])
    {
        s[i] = s1[i];
        i++;
    }
    j = 0;
    while (s2[j])
        s[i++] = s2[j++];
    s[i] = '\0';
    free (s1);
    return (s);
}

char    *substrr(const char *s, unsigned int start, size_t len)
{
    size_t  slen;
    char    *sub;
    size_t  i;
    
    if (!s)
        return (NULL);
    slen = strlenn(s);
    if (start >= slen)
        len = 0;
    else if (start + len > slen)
        len = slen - start;
    sub = malloc(sizeof(char) * (len + 1));
    if (!sub)
        return (NULL);
    i = 0;
    while (i < len)
    {
        sub[i] = s[i + start];
        i++;
    }
    sub[i] = '\0';
    return (sub);
}

char    *strdupp(const char *s)
{
    size_t  len;
    char    *dup;
    size_t  i;

    len = strlenn(s);
    dup = malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    i = 0;
    while (i < len)
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}




