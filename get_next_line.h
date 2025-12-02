/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhend <mhend@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:18:01 by mhend             #+#    #+#             */
/*   Updated: 2025/11/28 22:27:22 by mhend            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

char    *get_next_line(int fd);
size_t  strlenn(const char *s);
char *strchrr(const char *s, int c);
char    *strjoinn(char *s1, char *s2);
char    *substrr(const char *s, unsigned int start, size_t len);
char    *strdupp(const char *s);

#endif