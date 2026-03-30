/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:58:02 by ancarlos          #+#    #+#             */
/*   Updated: 2024/11/11 18:40:04 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>

char	*get_line(char *line)
{
	int	i;
	char *get;

	i = 0;
	if (!line[i])
	{
		return (NULL);
	}
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n')
		get = ft_calloc(i + 2, 1);
	else
		get = ft_calloc(i + 1, 1);
	i = 0;
	while (line[i] != '\n' && line[i])
	{
		get[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
		get[i] = '\n';
	return (get);
}

char	*rest_read(char *line)
{
	int	i;
	char	*rest;
	char	*temp;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\0')
	{
		free(line);
		return (NULL);
	}
	temp = line + i + 1;
	rest = ft_strdup(temp);
	free(line);
	return (rest);
}
static char *join(char *line, char *buff)
{
	char	*str;

	str = ft_strjoin(line, buff);
	free(line);
	return (str);
}

char *read_of_read(char *line, int fd)
{
	char		*buff;
	int			read_ret;

	if (!line)
		line = ft_calloc(1,1);
	read_ret = 1;
	buff = ft_calloc(BUFFER_SIZE + 1, 1);
	while (read_ret > 0)
	{
		read_ret = read(fd, buff, BUFFER_SIZE);
		if (read_ret < 0)
		{
			free(line);
			free(buff);
			return (NULL);
		}
		buff[read_ret] = '\0';
		line = join(line, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (line);
}

char *get_next_line(int fd)
{

	static char	*line;
	char		*ret_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_of_read(line, fd);
	if (!line)
		return (NULL);
	ret_line = get_line(line);
	line =	rest_read(line);
	return (ret_line);
}

/* #include <fcntl.h>
int main()
{
	int	fd;
	fd = open("./try.txt", O_RDONLY);
	char *line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);



	// while (line != NULL)
	// {
	// 	printf("%s", line);
	// 	free(line);
	// 	line = get_next_line(fd);
	// }
	close(fd);
	return 0;
} */

