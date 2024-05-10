/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:38:04 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/10 15:27:39 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*static char	*take_after_new_line(char *temp)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	if (temp == "\n")
		return (free(temp), NULL);
	dest = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!dest)
		return (free(temp), NULL);
	j = 0;
	while (temp[i])
		dest[j++] = temp[++i];
	dest[j] = '\0';
	free(temp);
	return (dest);
}

static char	*take_until_new_line(char *buf)
{
	int		i;
	char	*dest;

	i = 0;
	if (!buf[i])
		return (NULL);
	while (buf && buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (buf && buf[i] && buf[i] != '\n')
	{
		dest[i] = buf[i];
		i++;
	}
	if (buf[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

static char	*read_until_new_line(int fd, char *str)
{
	char	*buff;
	char	*line;
	int		bytes_read;

	if (!str)
	{
		str = malloc(1 * sizeof(char));
		str[0] = '\0';
	}
	if (!str)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(str), NULL);
	bytes_read = 1;
	while (!ft_strchr(str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), free(str), NULL);
		buff[bytes_read] = '\0';
		line = str;
		str = ft_strjoin(line, buff);
		if (!str)
			return (free(buff), NULL);
	}
	return (free(buff), str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*read;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
	read = read_until_new_line(fd, str);
	if (!read)
		return (0);
	line = take_until_new_line(read);
	if (!line)
	{
		free(line);
		free(read);
		free(str);
		str = NULL;
		return (NULL);
	}
	str = take_after_new_line(read);
	return (line);
}*/
