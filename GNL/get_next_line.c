/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aishamagoury <aishamagoury@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 16:00:29 by amagoury          #+#    #+#             */
/*   Updated: 2024/03/31 13:02:14 by aishamagour      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*del_line(char *s)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free (s);
		return (NULL);
	}
	buff = malloc ((sizeof(char)) * ft_strlen(s) - i + 1);
	if (!buff)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		buff[j++] = s[i++];
	buff[j] = '\0';
	free (s);
	return (buff);
}

char	*check_line(char *s)
{
	int		i;
	char	*str_l;

	if (!*s)
		return (NULL);
	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	str_l = malloc(i + 1 + (s[i] == '\n'));
	if (!str_l)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str_l[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		str_l[i] = s[i];
		i++;
	}
	str_l[i] = '\0';
	return (str_l);
}

char	*read_buffer(char *str, int fd)
{
	int		chr_reader;
	char	*buffer;

	chr_reader = 1;
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (ft_strchr(str, '\n') == 0 && chr_reader != 0)
	{
		chr_reader = read (fd, buffer, BUFFER_SIZE);
		if (chr_reader == -1)
		{
			free (buffer);
			if (str)
				free (str);
			return (NULL);
		}
		buffer[chr_reader] = '\0';
		str = ft_strjoin (str, buffer);
	}
	free (buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	str = read_buffer (str, fd);
	if (!str)
		return (NULL);
	line = check_line (str);
	str = del_line (str);
	return (line);
}
