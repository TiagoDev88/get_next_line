/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:38:06 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/04/21 17:45:45 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "get_next_line.h"
#include <stdio.h>

int	has_newline(char *stash)
{
	int i;

	if (!stash)
		return (0);
	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		len1;
	int		len2;
	int		i;
	int		j;

	len1 = 0;
	len2 = 0;
	if (!s2)
		return (NULL);
	while (s1 && s1[len1])
		len1++;
	while (s2 && s2[len2])
		len2++;
	newstring = malloc(sizeof(char) * ((len1 + len2) + 1));
	if (!newstring)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < len1)
		newstring[i] = s1[i];
	j = -1;
	while (++j < len2)
		newstring[i + j] = s2[j];
	newstring[i + j] = '\0';
	free(s1);
	return (newstring);
}
char	*extract_line(char *stash)
{
	char	*newline;
	int 	i;
	int 	j;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	newline = malloc(sizeof(char) * (i + 1));
	if (!newline)
		return (NULL);
	j = 0;
	while (j < i)
	{
		newline[j] = stash[j];
		j++;
	}
	newline[j] = '\0';
	return (newline);
}
char	*update_stash(char *stash)
{
	char	*newstash;
	int 	i;
	int 	j;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	j = 0;
	while (stash[i + j])
		j++;
	newstash = malloc(sizeof(char) * (j + 1));
	if (!newstash)
		return (NULL);
	j = 0;
	while (stash[i + j])
	{
		newstash[j] = stash[i + j];
		j++;
	}
	newstash[j] = '\0';
	free(stash);
	return (newstash);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char 		*buffer;
	char 		*line;
	ssize_t 	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 0;
	while (has_newline(stash) == 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	if ((bytes_read == 0 && !stash) || (stash && *stash == '\0'))
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	stash = update_stash(stash);
	if (!line || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

#include <fcntl.h>
#include <sys/uio.h>
#include <sys/types.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *line;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			free(line);
		else
			break;
	}
	close(fd);
	return(0);
}