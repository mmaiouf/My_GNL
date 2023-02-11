/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:23 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/11 21:59:40 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 1000

char	*get_a_line(int fd)
{
	int		nbread;
	int		i;
	char	*buff;
	char	*line;

	i = 0;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	line = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	nbread = read(fd, buff, BUFFER_SIZE);
	buff[nbread] = '\0';
	while (buff[i] && buff[i] != '\n')
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

char *get_next_line(int fd)
{
	char	*line;

	line = get_a_line(fd);
}