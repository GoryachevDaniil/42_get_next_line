/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 01:55:17 by mturquin          #+#    #+#             */
/*   Updated: 2021/01/08 21:17:31 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*buff[2048];
	char		*buf;
	int			rb;
	char		*check[0];

	if (((read(fd, check, 0)) < 0 || BUFFER_SIZE < 1 || !line || fd < 0) ||
		(!(buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1))))
		return (-1);
	rb = 1;
	while ((ft_strchr_gnl(buff[fd]) == 0 && rb != 0))
	{
		if ((rb = read(fd, buf, BUFFER_SIZE)) < 0)
			return (ft_free_gnl(buff[fd], buf));
		buf[rb] = '\0';
		if (!(buff[fd] = ft_strjoin_gnl(buff[fd], buf)))
			return (ft_free_gnl(buff[fd], buf));
	}
	buf = ft_freebuf_gnl(buf);
	if (!(*line = ft_strdup1(buff[fd])))
		return (ft_free_gnl(buff[fd], buf));
	if (!(buff[fd] = ft_strdup2(buff[fd])) && rb != 0)
		return (ft_free_gnl(buff[fd], buf));
	rb == 0 ? ft_freebuf_gnl(buff[fd]) : 0;
	return (rb ? 1 : 0);
}
