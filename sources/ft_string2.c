/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-jesu <mde-jesu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 18:25:19 by mde-jesu          #+#    #+#             */
/*   Updated: 2013/12/15 18:25:25 by mde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>

#include "ft_string.h"

char	*ft_strsub(char const *s, const uint32_t start, const size_t len)
{
	char	*new_str;

	if (s != NULL)
	{
		new_str = (char *) malloc(sizeof(char) * (len + 1));
		ft_strncpy(new_str, (char *) &s[start], len);
		return (new_str);
	}
	else
	{
		return (NULL);
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	len_s1 = ft_strlen(s1);
	const size_t	len_s2 = ft_strlen(s2);
	char			*new_str;
	size_t			len_mix;

	len_mix = len_s1 + len_s2;
	if ((new_str = (char *) malloc(sizeof(char) * (len_mix + 1))) != NULL)
	{
		if (len_mix != 0)
		{
			ft_strncpy(new_str, s1, len_s1);
			ft_strncat(new_str, s2, len_mix);
		}
	}
	return (new_str);
}

char	*ft_strdup(const char *s1)
{
	const size_t	len_s1 = ft_strlen(s1);
	char			*new_s1;

	if ((new_s1 = (char *) malloc(sizeof(char) * len_s1 + 1)) != NULL)
	{
		return (ft_strncpy(new_s1, s1, len_s1));
	}
	else
	{
		return (NULL);
	}
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const uint8_t	*str;
	size_t			i;

	str = (uint8_t *) s;
	i = 0;
	while (i < n && str[i] != (uint8_t) c)
	{
		i++;
	}
	if (i != n)
		return ((void *) (str + i));
	else
		return (NULL);
}

void	*ft_memmove(void *s1, const void *s2, const size_t n)
{
	void	*tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if ((tmp = (void *) malloc(n)) == NULL)
		return (NULL);
	ft_memcpy(tmp, s2, n);
	ft_memcpy(s1, tmp, n);
	free(tmp);
	return ((void *) s1);
}

