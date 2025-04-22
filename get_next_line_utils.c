/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:38:53 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/04/22 17:23:52 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_newline(char *stash)
{
	int	i;

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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstring;
	int		len1;
	int		len2;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstring = malloc(sizeof(char) * ((len1 + len2) + 1));
	if (!newstring)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		newstring[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		newstring[i++] = s2[j++];
	newstring[i] = '\0';
	return (newstring);
}

char	*extract_line(char *stash)
{
	char	*newline;
	int		i;
	int		j;

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
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] && stash[i] == '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	newstash = malloc(ft_strlen(stash) - i + 1);
	if (!newstash)
		return (NULL);
	j = 0;
	while (stash[i])
		newstash[j++] = stash[i++];
	newstash[j] = '\0';
	free(stash);
	return (newstash);
}
