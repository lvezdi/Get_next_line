
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (str == NULL)
		return (NULL);
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
	return (str);
}

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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*int	main()
{
	int	fd;
	int size;
	char *buff;

	fd = open("./test.txt", O_RDONLY);
	buff = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	size = read(fd, buff, BUFFER_SIZE);
	printf("size: %d\n", size);
	printf("%s\n" , buff);
	if (fd == -1)
		return (0);
	else
	{
		close(fd);
	}
	printf("fd: %d\n", fd);
	return (0);
}*/
