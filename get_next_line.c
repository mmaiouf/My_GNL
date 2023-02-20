/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:23 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/20 21:39:13 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*read_file(int fd, char *backup)
{
	int		nb_read;
	char	*buffer;
	
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buffer == NULL)
		return(NULL);
	nb_read = 1;
	printf("backup au debut : %s\n", backup);
	while (nb_read)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		buffer[nb_read] = '\0';
		//if (nb_read == 0)
		//{
		//	free(buffer);
		//	return (buffer);
		//}
		backup = ft_strjoin(backup, buffer);
		printf("buffer : %s\n", buffer);
		printf("backup : %s\n", backup);
		printf("nbread : %d\n", nb_read);
		printf("----------------\n");
		if (ft_strchr(backup, '\n'))
			break;
	}
	free(buffer);
	return (backup);
}

char	*get_a_line(char *backup)
{
	int		i;
	char	*line;

	i = 0;
	line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (line == NULL)
		return (NULL);
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

int		get_index_linebreak(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*get_next_line_start(char *backup)
{
	int		i;
	int		j;
	int		len_next_buffer;
	char	*next_buffer;
	
	i = get_index_linebreak(backup);
	//printf("get index linebreak : %d\n", i);
	j = 0;
	len_next_buffer = 0;
	while (backup[++i])
	{
		len_next_buffer++;
	}
//	printf("len next buffer after parsing : %d\n", len_next_buffer);
	next_buffer = malloc(sizeof(char) * len_next_buffer + 1);
	if (next_buffer == NULL)
		return (NULL);
	i = i - len_next_buffer;
	//printf("i - len_next_buffer : %d\n", i);
	while(backup[i])
	{
		next_buffer[j] = backup[i];
		i++;
		j++;
	}
	next_buffer[j] = '\0';
	return (next_buffer);
}

char    *get_next_line(int fd)
{
    char        	*line;
    static char    	*backup;

    backup = read_file(fd, backup);
    line = get_a_line(backup);
    backup = get_next_line_start(backup);
    return (line);
}
