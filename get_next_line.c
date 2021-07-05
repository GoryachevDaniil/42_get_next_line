/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 01:55:17 by mturquin          #+#    #+#             */
/*   Updated: 2021/01/08 21:14:49 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			ft_strlen_gnl(const char *str)
{
	int			i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int				ft_free_gnl(char *buff, char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
	if (buff)
	{
		free(buff);
		buff = NULL;
	}
	return (-1);
}

char			*ft_freebuf_gnl(char *buf)
{
	free(buf);
	buf = NULL;
	return (buf);
}

int				get_next_line(int fd, char **line)
{
	static char	*buff;
	char		*buf;
	int			rb;
	char		*check[0];

	if (((read(fd, check, 0)) < 0 || BUFFER_SIZE < 1 || !line || fd < 0) ||
		(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1))))
		return (-1);
	rb = 1;
	while ((ft_strchr_gnl(buff) == 0 && rb != 0))
	{
		if ((rb = read(fd, buf, BUFFER_SIZE)) < 0)
			return (ft_free_gnl(buff, buf));
		buf[rb] = '\0';
		if (!(buff = ft_strjoin_gnl(buff, buf)))
			return (ft_free_gnl(buff, buf));
	}
	buf = ft_freebuf_gnl(buf);
	if (!(*line = ft_strdup1(buff)))
		return (ft_free_gnl(buff, buf));
	if (!(buff = ft_strdup2(buff)) && rb != 0)
		return (ft_free_gnl(buff, buf));
	rb == 0 ? ft_freebuf_gnl(buff) : 0;
	return (rb ? 1 : 0);
}
