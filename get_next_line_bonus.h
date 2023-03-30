/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:26:25 by hojakim           #+#    #+#             */
/*   Updated: 2023/03/24 17:32:34 by hojakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# include <stdlib.h>
# include <unistd.h>

unsigned int	ft_strlen(const char *s);
char			*ft_strdup(const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_len_check(char const *s, unsigned int start, size_t len);
char			*ft_substr(char const *s, unsigned int start, size_t len);

char			*gnl_strchr(const char *s, int c);
char			*read_line(int fd, char *buffer, char *backup);
char			*get_one_line(char *backup);
char			*refresh_backup(char *backup);
char			*get_next_line(int fd);

#endif