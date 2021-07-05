/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mturquin <mturquin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:14:57 by mturquin          #+#    #+#             */
/*   Updated: 2021/01/08 21:14:46 by mturquin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strdup1(char *str);
char	*ft_strdup2(char *str);
int		ft_strchr_gnl(const char *str);
int		ft_strlendo_n(char *str);
char	*ft_freebuf_gnl(char *buf);

#endif
