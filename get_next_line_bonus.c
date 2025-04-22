/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:38:06 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/04/22 16:38:39 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_into_stash(int fd, char *stash, char *buffer)
{
	ssize_t	bytes_read;
	char 	*tmp;
	
	bytes_read = 1;
	while (!has_newline(stash) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
        {
            free(stash);
            return (NULL);
        }
        if (bytes_read == 0)
            break;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stash, buffer);
		if (!tmp)
		{
			free(stash);
			return (NULL);
		}
		free(stash);
		stash = tmp;
	}
	return (stash);
}


char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash[fd] = read_into_stash(fd, stash[fd], buffer);
	free(buffer);
	if (stash[fd] == NULL || stash[fd][0] == '\0')
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = extract_line(stash[fd]);
	stash[fd] = update_stash(stash[fd]);
	return (line);
}


// #include <fcntl.h>
// #include <sys/types.h>
// #include <stdio.h>

// int main(void) {
//     char *line;
//     int fd ; 
// 	fd = open("test.txt", O_RDONLY);

// 	while(line = get_next_line(fd))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// 	return 0;
// }
