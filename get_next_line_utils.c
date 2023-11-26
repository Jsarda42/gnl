/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juliensarda <juliensarda@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:52:21 by jsarda            #+#    #+#             */
/*   Updated: 2023/11/26 11:03:41 by juliensarda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*des;
	unsigned const char	*s;

	des = dest;
	s = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		des[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	void	*res;
	size_t	s_len;

	s_len = ft_strlen(s1) + 1;
	res = malloc(sizeof(char) * s_len);
	if(!res)
		return (NULL);
	res = ft_memcpy(res, s1, s_len);
	return (res);
}
