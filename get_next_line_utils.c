/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:38:11 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/10 15:43:44 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (str == NULL)
		return (free(s1), NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*int	main(void)
{
	int	fd;
	char	*newline;

	fd = open("test.txt", O_RDONLY);
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
    while (i <= 7)
    {
        str = get_next_line(fd);
        printf("line %i=>%s\n", i + 1, str);
        free(str);
        i++;
    }
    return (0);
}*/
