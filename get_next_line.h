/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:26 by momaiouf          #+#    #+#             */
/*   Updated: 2023/03/01 21:24:44 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>

char			*read_file(int fd, char *backup);
int				check_nbread_and_linebreak(char *str, int nb_read);
char			*get_a_line(char *backup);
char			*get_next_line_start(char *backup);
char			*get_next_line(int fd);
int				get_index_linebreak(char *str);
int				get_len_line(char *str);
int				ft_strlen(char const *str);
void			*ft_memcpy(void *dest, void *src, size_t size);
char			*ft_strjoin(char *s1, char *s2);

#endif
