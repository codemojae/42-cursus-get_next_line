/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:51:23 by hojakim           #+#    #+#             */
/*   Updated: 2023/01/30 21:42:52 by hojakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define BUFFER_SIZE 10

int	check_endline(char *buf, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*join_str(char *s1, char *s2, size_t s1_len, size_t s2_len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	i = 0;
	while (i < s1_len)
		str[i] = s1[i];
	i = 0;
	while (i < s2_len)
		str[s1_len + i] = s2[i];
	return (str);
}

char	*get_next_line(int fd)
{
	char	*buf;
	char	*result;
	int		len;
	int		idx;

	if (!fd)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (0 < (len = read(fd, buf, BUFFER_SIZE)))
	{
		
	}
	idx = check_endline(buf, len);
	if (idx > 0)
	{
		buf[idx] = '\0';
	}
	else
	{
		buf[BUFFER_SIZE] = '\0';
	}
	printf("bf_size : %d len : %d\n%s\n", BUFFER_SIZE, len, buf);
	return (result);
}

int	main(int argc, char const *argv[])
{
	int		fd;
	int		len;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
