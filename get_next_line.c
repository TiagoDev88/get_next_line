/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:38:06 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/04/22 00:31:59 by tfilipe-         ###   ########.fr       */
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
	i = 0;
	while (i < len1)
	{
		newstring[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		newstring[i + j] = s2[j];
		j++;
	}
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
	int 	l;

	i = 0;
	if (!stash)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    }
    j = 0;
    while (stash[i + j])
        j++;
    newstash = malloc(sizeof(char) * (j + 1));
	if (!newstash)
	{
		free(stash);
		return (NULL);
	}
	l = 0;
	while (l < j)
	{
		newstash[l] = stash[i + l];
		l++;
	}
	newstash[l] = '\0';
	free(stash);
	return (newstash);
}

static char	*read_into_stash(int fd, char *stash, char *buffer)
{
	ssize_t	bytes_read;

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
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}


char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = read_into_stash(fd, stash, buffer);
	free(buffer);
	if (stash == NULL || *stash == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	stash = update_stash(stash);
	return (line);
}


#include <fcntl.h>
#include <sys/types.h>

// int main(void) {
//     char *line;
//     int fd = -1; // Um valor inválido para fd

//     // Teste com NULL (fd inválido)
//     line = get_next_line(fd);
//     printf("Resultado com NULL (fd inválido): %s\n", line);

//     // Teste com arquivo inexistente
//     fd = open("inexistente.txt", O_RDONLY);
//     if (fd == -1) {
//         printf("Arquivo inexistente não pode ser aberto\n");
//     } else {
//         line = get_next_line(fd);
//         printf("Resultado com arquivo inexistente: %s\n", line);
//         close(fd);
//     }

//     return 0;
// }