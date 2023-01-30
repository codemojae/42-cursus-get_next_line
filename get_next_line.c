/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:51:23 by hojakim           #+#    #+#             */
/*   Updated: 2023/01/30 21:00:47 by hojakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

# define BUFFER_SIZE 10

int	check_line(char *buf)
{
	while ()
	return (-1);
}

char	*get_next_line(int fd)
{
	char	*buf;
	int		len;

	if (!fd)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	len = read(fd, buf, BUFFER_SIZE);
	buf[BUFFER_SIZE] = '\0';
	printf("len : %d, %s\n", len, buf);
	return (buf);
}

int	main(int argc, char const *argv[])
{
	int		fd;
	int		len;

	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
	return (0);
}
