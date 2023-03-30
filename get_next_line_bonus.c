/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hojakim <hojakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:26:49 by hojakim           #+#    #+#             */
/*   Updated: 2023/03/24 17:58:55 by hojakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

char	*read_line(int fd, char *buffer, char *backup)
{
	char	*tmp;
	int		readlen;

	while (!gnl_strchr(backup, '\n'))
	{
		readlen = read(fd, buffer, BUFFER_SIZE);
		if (readlen < 0)
		{
			free(backup);
			return (NULL);
		}
		if (readlen <= 0)
			break ;
		buffer[readlen] = '\0';
		if (!backup)
			backup = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(backup, buffer);
			free(backup);
			backup = tmp;
		}
	}
	return (backup);
}

char	*get_one_line(char *backup)
{
	int		i;
	char	*result_line;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
		{
			break ;
		}
		i++;
	}
	result_line = ft_substr(backup, 0, i + 1);
	return (result_line);
}

char	*refresh_backup(char *backup)
{
	int		i;
	char	*new_backup;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
		{
			if (backup[i + 1] == '\0')
				break ;
			new_backup = ft_substr(backup, i + 1, ft_strlen(backup) - (i + 1));
			free(backup);
			return (new_backup);
		}
		i++;
	}
	free(backup);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*backup[OPEN_MAX];
	char		buffer[BUFFER_SIZE + 1];
	char		*result;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		return (NULL);
	}
	backup[fd] = read_line(fd, buffer, backup[fd]);
	if (!backup[fd])
	{
		return (NULL);
	}
	result = get_one_line(backup[fd]);
	backup[fd] = refresh_backup(backup[fd]);
	return (result);
}

// if (!backup)
// {
// 	backup = (char *)malloc(sizeof(char) * 1);
// 	backup[0] = '\0';
// }

// #include <fcntl.h>
// #include "get_next_line_utils.c"
// void	check_leak(void)
// {
// 	system("leaks --list -- a.out");
// }
// int	main(void)
// {
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		perror("open");
// 		return (-1);
// 	}
// 	for (int i = 0; i < 2; i++)
// 		printf("result : %s\n", get_next_line(fd));
// 	close(fd);
// 	atexit(check_leak);
// 	// char *a = "asd";
// 	// char *b = "123";
// 	// printf("%s + %s = %s", a, b, ft_strjoin(a,b));
// 	return (0);
// }