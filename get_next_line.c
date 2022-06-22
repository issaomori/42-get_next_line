/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gissao-m <gissao-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:08:55 by gissao-m          #+#    #+#             */
/*   Updated: 2022/06/22 16:47:59 by gissao-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_str(int fd, char *read_line_str)
{
	int		read_byte;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	read_byte = 1;
	while (!ft_strchr(read_line_str, '\n') && read_byte != 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		read_line_str = ft_strjoin(read_line_str, buffer);
	}
	free(buffer);
	return (read_line_str);
}

char	*get_next_line(int fd)
{
	static char	*get_str;
	char		*the_line;

	the_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	get_str = ft_get_str(fd, get_str);
	if (!get_str)
		return (NULL);
	the_line = ft_return_line(get_str);
	get_str = ft_initial_position(get_str);
	if (the_line[0] == '\0')
	{
		free(get_str);
		free(the_line);
		return (NULL);
	}
	return (the_line);
}

/*
#include <stdio.h>
#include <fcntl.h>
int main (void)
{
	char *lida; //mesma coisa que string
	int		fd;
	int		i;

	fd = open("test.txt", O_RDONLY); //com o open abro o projeto e O_RDONLY SOMENTE LEITURA.
	
	i = 1;
	while (i < 9)
	{
		lida = get_next_line(fd);
		printf("%s", lida);
		free (lida);
		i++;
	}
	close(fd);
	return (0);
}*/