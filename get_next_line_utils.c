/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 15:06:58 by mturquin          #+#    #+#             */
/*   Updated: 2021/01/08 21:14:48 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
	{
		free(str);
		return (NULL);
	}
	i = 0;
	if (s1)
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

char		*ft_strdup1(char *str)
{
	int		i;
	char	*str1;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(str1 = (char *)malloc(sizeof(char) * i + 1)))
	{
		free(str);
		return (0);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		str1[i] = str[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}

char		*ft_strdup2(char *str)
{
	int		i;
	char	*str1;
	int		n;

	i = 0;
	n = 0;
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	if (!(str1 = (char *)malloc(sizeof(char) *
					(ft_strlen_gnl(str) - (i = ft_strlendo_n(str)) + 1))))
	{
		free(str);
		return (0);
	}
	if (str[i])
		i++;
	while (str[i])
		str1[n++] = str[i++];
	str1[n] = '\0';
	free(str);
	return (str1);
}

int			ft_strchr_gnl(const char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i++] == '\n')
			return (1);
	}
	return (0);
}

int			ft_strlendo_n(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
