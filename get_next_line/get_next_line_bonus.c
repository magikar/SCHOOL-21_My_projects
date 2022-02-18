/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmagikar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 17:54:38 by tmagikar          #+#    #+#             */
/*   Updated: 2021/01/19 11:40:53 by tmagikar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char		*check_buf(char *buf, char **line)
{
	char	*point_n;

	point_n = NULL;
	if (buf[0])
	{
		if ((point_n = ft_strchr(buf, '\n')))
		{
			*point_n = '\0';
			if (!(*line = ft_strdup(buf)))
				return (NULL);
			ft_memmove(buf, (point_n + 1), BUFFER_SIZE - (point_n - buf));
		}
		else
		{
			if (!(*line = ft_strdup(buf)))
				return (NULL);
		}
	}
	else
	{
		if (!(*line = (char*)malloc(1)))
			return (NULL);
		*line[0] = '\0';
	}
	return (point_n);
}

static char		*buf_read(char *buf, char **line)
{
	char	*point_n;
	char	*tmp;

	point_n = NULL;
	if ((point_n = ft_strchr(buf, '\n')))
	{
		*point_n = '\0';
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (NULL);
		free(tmp);
		ft_memmove(buf, (point_n + 1),
		BUFFER_SIZE - (point_n - buf) + 1);
	}
	else
	{
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (NULL);
		free(tmp);
		buf[0] = '\0';
	}
	return (point_n);
}

int				get_next_line(int fd, char **line)
{
	int			byte;
	char		*point;
	static char	buf[1025][BUFFER_SIZE + 1];

	point = NULL;
	if (BUFFER_SIZE < 1 || read(fd, buf[fd], 0) == -1 || line == NULL)
		return (-1);
	point = check_buf(buf[fd], line);
	if (line == NULL)
		return (-1);
	byte = -1;
	while (!point && (byte = read(fd, buf[fd], BUFFER_SIZE)))
	{
		buf[fd][byte] = '\0';
		point = buf_read(buf[fd], line);
		if (line == NULL)
			return (-1);
	}
	if (!point && !byte)
		return (0);
	return (1);
}
