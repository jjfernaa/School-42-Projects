/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-jof <juan-jof@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:33:22 by juan-jof          #+#    #+#             */
/*   Updated: 2025/02/04 19:04:40 by juan-jof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_append(int fd, char *rest, char *buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(rest, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			temp = rest;
			rest = ft_strjoin(rest, buffer);
			free(temp);
		}
	}
	if (bytes_read < 0)
	{
		free(rest);
		return (NULL);
	}
	return (rest);
}

static char	*read_until_newline(int fd, char *rest)
{
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!rest)
	{
		rest = ft_strdup("");
		if (!rest)
		{
			free(buffer);
			return (NULL);
		}
	}
	rest = read_and_append(fd, rest, buffer);
	free(buffer);
	return (rest);
}

static char	*extract_line(char *rest)
{
	char	*line;
	int		i;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] && rest[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (rest[i] && rest[i] != '\n')
	{
		line[i] = rest[i];
		i++;
	}
	if (rest[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_rest(char *rest)
{
	char	*new_rest;
	int		i;
	int		j;

	i = 0;
	while (rest[i] && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	new_rest = malloc(ft_strlen(rest) - i + 1);
	if (!new_rest)
	{
		free (rest);
		return (NULL);
	}
	i++;
	j = 0;
	while (rest[i])
		new_rest[j++] = rest[i++];
	new_rest[j] = '\0';
	free(rest);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = read_until_newline(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	line = extract_line(rest[fd]);
	rest[fd] = update_rest(rest[fd]);
	return (line);
}
