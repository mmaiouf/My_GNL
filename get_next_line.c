/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:23 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/24 17:56:52 by marvin           ###   ########.fr       */
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
	//printf("backup au debut : %s\n", backup);
	while (nb_read) // while 0, donc tant qu'on ne trouve pas de \n et tant qu'il y a encore des choses a lire
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read <= 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		backup = ft_strjoin(backup, buffer);
		if (ft_strchr(backup, '\n'))
			break;
		//printf("buffer : %s\n", buffer);
		//printf("backup : %s\n", backup);
		//printf("nbread : %d\n", nb_read);
		//printf("----------------\n");
	}
	free(buffer);
	return (backup);
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

char	*get_a_line(char *backup)
{
	int		i;
	int		len_line;
	char	*line;

	i = 0;
	len_line = get_index_linebreak(backup);
	line = malloc(sizeof(char) * (len_line + 1));
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
	if (i != 0)
	{
		while (backup[++i])
			len_next_buffer++;
	}	
	//printf("len next buffer after parsing : %d\n", len_next_buffer);
	//printf("i after parsing : %d\n", i);
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
	//printf("nextbuff : %s\n", next_buffer);
	return (next_buffer);
}

char    *get_next_line(int fd)
{
    char        	*line;
    static char    	*backup;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		free(backup);
		return(NULL);
	}
    backup = read_file(fd, backup);
	if (backup == NULL)
	{
		free(backup);
		return (NULL);
	}
    line = get_a_line(backup);
    backup = get_next_line_start(backup);

    return (line);
}
