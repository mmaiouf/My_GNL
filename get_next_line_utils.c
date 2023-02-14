/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momaiouf <momaiouf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:56:20 by momaiouf          #+#    #+#             */
/*   Updated: 2023/02/14 22:56:49 by momaiouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void    *ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < size)
	{
		((unsigned char *)dest)[i] = ((unsigned const char *)src)[i];
		i++;
	}
	return (dest);
}

char    *ft_strjoin(char const *s1, char const *s2)
{
	char    *mystr;
	size_t  len_s1;
	size_t  len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	mystr = malloc((sizeof(char) * (len_s1 + len_s2 + 1)));
	if (mystr == NULL)
		return (NULL);
	ft_memcpy(mystr, s1, len_s1);
	ft_memcpy(mystr + len_s1, s2, len_s2);
	mystr[len_s1 + len_s2] = '\0';
	return (mystr);
}
