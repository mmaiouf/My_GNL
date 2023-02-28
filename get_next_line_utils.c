/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:20 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/28 02:51:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


int		get_index_linebreak(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int		get_len_line(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

int		ft_strlen(char const *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void    *ft_memcpy(void *dest, void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < size)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char    *ft_strjoin(char *s1, char *s2)
{
	char    *mystr;
	size_t  len_s1;
	size_t  len_s2;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	if (s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	mystr = malloc((sizeof(char) * (len_s1 + len_s2 + 1)));
	if (mystr == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_memcpy(mystr, s1, len_s1);
	ft_memcpy(mystr + len_s1, s2, len_s2);
	mystr[len_s1 + len_s2] = '\0';
	free(s1);
	return (mystr);
}