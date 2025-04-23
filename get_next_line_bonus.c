/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:38:06 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/04/23 11:38:11 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_into_stash(int fd, char *stash, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	bytes_read = 1;
	while (has_newline(stash) == 0 && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
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
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	if (!line)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	stash[fd] = update_stash(stash[fd]);
	return (line);
}

// #include <fcntl.h>
// #include <stdio.h>

// int main(void)
// {
//     int fd1 = open("file1.txt", O_RDONLY);
//     int fd2 = open("file2.txt", O_RDONLY);
//     char *line1 = NULL;
//     char *line2 = NULL;

//     if (fd1 < 0 || fd2 < 0)
//     {
//         printf("Error opening files");
//         return 1;
//     }

//     while (1)
//     {
//         line1 = get_next_line(fd1);
//         if (line1)
//         {
//             printf("file1: %s", line1);
//             free(line1);
//         }

//         line2 = get_next_line(fd2);
//         if (line2)
//         {
//             printf("file2: %s", line2);
//             free(line2);
//         }

//         if (!line1 && !line2)
//             break;
//     }

//     close(fd1);
//     close(fd2);
//     return 0;
// }
