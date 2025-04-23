/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfilipe- <tfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:39:03 by tfilipe-          #+#    #+#             */
/*   Updated: 2025/04/23 11:33:29 by tfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *s);
int		has_newline(char *stash);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_line(char *stash);
char	*update_stash(char *stash);


#endif