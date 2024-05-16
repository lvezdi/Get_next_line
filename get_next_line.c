/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:38:04 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/16 10:27:50 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (free(temp), NULL);
	j = 0;
	while (temp[i])
		dest[j++] = temp[++i];
	dest[j] = '\0';
	free(temp);
	return (dest);
}

static char	*take_until_new_line(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str && str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

static char	*read_until_new_line(int fd, char **str)
{
	char	*buff;
	int		bytes_read;

	if (!*str)
	{
		*str = malloc(1 * sizeof(char));
		*str[0] = '\0';
	}
	if (!*str)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(*str), NULL);
	bytes_read = 1;
	while (!ft_strchr(*str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), free(*str), NULL);
		buff[bytes_read] = '\0';
		*str = ft_strjoin(*str, buff);
		if (!*str)
			return (free(buff), NULL);
	}
	return (free(buff), *str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_until_new_line(fd, &str);
	if (!str)
		return (0);
	line = take_until_new_line(str);
	if (!line)
	{
		free(line);
		free(str);
		str = NULL;
		return (NULL);
	}
	str = take_after_new_line(str);
	return (line);
}

/*int main()
{
	//Simple main
	
	int	fd;
	char	*line;

	fd = open("t1", O_RDONLY);
	while ((line = get_next_line(1)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	printf("%s", line);
	close(fd);
	return (0);
}*/

/*int	main(int argc, char *argv[])
{
	char *buffer;

	// Read from file if an argument is provided on the command line
	if (argc == 2)
	{
		// Open the file for reading
		int fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening file");
			exit(EXIT_FAILURE);
		}

		// Calling the function to read the file contents
		while ((buffer = get_next_line(fd)) != NULL)
		{
			// Check if memory was allocated correctly
			if (buffer == NULL)
			{
				fprintf(stderr, "Failure to allocate buffer memory\n");
				break;
			}

			// Process the line read
			printf("RECEIVED: %s\n", buffer);

			// Release memory allocated to the line
			free(buffer);
		}

		// Close file descriptor
		if (close(fd) == -1)
		{
			perror("Error closing file");
			exit(EXIT_FAILURE);
		}
	}
	// Read from stdin if no arguments are provided on the command line
	else if (argc == 1)
	{
		printf("Enter text from stdin:\n");
		while ((buffer = get_next_line(STDIN_FILENO)) != NULL)
		{
			// Check if memory was allocated correctly
			if (buffer == NULL)
			{
				fprintf(stderr, "Failure to allocate buffer memory\n");
				break;
			}

			// Process the line read
			printf("RECEIVED: %s\n", buffer);

			// Release memory allocated to the line
			free(buffer);
		}
	}
	else
	{
		fprintf(stderr, "Uso: %s [nombre_del_archivo]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	return 0;
}*/
