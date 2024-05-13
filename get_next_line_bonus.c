/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:38:04 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/13 11:45:02 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	char	*begin;

	dst = (char *)malloc(ft_strlen(s1) + 1);
	if (dst == NULL)
		return (NULL);
	begin = dst;
	while (*s1 != '\0')
		*dst++ = *s1++;
	*dst = '\0';
	return (begin);
}

static char	*take_after_new_line(char *temp)
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
	dest = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!dest)
	{
		return (free(temp), NULL);
	}
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
	int		readed;

	if (!str)
		str = ft_calloc(1, 1);
	if (!str)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(str), NULL);
	readed = 1;
	while (!ft_strchr(str, '\n') && readed != 0)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if (readed == -1)
			return (free(buff), free(str), NULL);
		buff[readed] = '\0';
		str = ft_strjoin(str, buff);
		if (!str)
			return (free(buff), NULL);
	}
	return (free(buff), str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
	str = read_until_new_line(fd, str);
	if (!str)
		return (0);
	line = take_until_new_line(str);
	if (!line)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = take_after_new_line(str);
	return (line);
}*/

/*int	main(void)
{
	int	fd;
	char	*newline;

	fd = open("test.txt", O_RDONLY);
	//printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	while ((newline = get_next_line(fd)))
	{
		printf("%s\n", newline);
		free(newline);
	}
	return (0);
}*/

/*int main(void)
{
    int     fd;
   char    *str;
    int     i;

    i = 0;
    fd = open("test.txt", O_RDONLY);
    printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
    while (i <= 9)
    {
        str = get_next_line(fd);
        printf("line %i=>%s\n", i + 1, str);
        free(str);
        i++;
    }
    return (0);
}*/
