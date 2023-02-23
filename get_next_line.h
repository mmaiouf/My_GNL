/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:26 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/23 08:27:20 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif


# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int				ft_strlen(char const *str);
char			*get_next_line(int fd);
char			*get_a_line(char *backup);
char    		*ft_strjoin(char *s1, char *s2);
void    		*ft_memcpy(void *dest, void *src, size_t size);
char			*read_file(int fd, char *backup);
char			*get_next_line_start(char *backup);
int				ft_strchr(const char *str, int c);
int				get_index_linebreak(char *str);
#endif

/*
Comment
appelle t-on
un chien magique ?
tu sais pas ?
ben un magichien mdr
bon
*/