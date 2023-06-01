/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juandrie <juandrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:41:31 by juandrie          #+#    #+#             */
/*   Updated: 2023/06/01 12:31:00 by juandrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_line(char *stash)
{
	int		i;
	char	*new_line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	new_line = (char *)malloc(sizeof(char) * (i + 2));
	if (!new_line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		new_line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		new_line[i] = stash[i];
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_clean(char *stash)
{
	int		i;
	int		c;
	char	*new_stash;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free (stash);
		return (NULL);
	}
	new_stash = (char *)malloc(sizeof(char) * (ft_strlen(stash) - i));
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	i++;
	c = 0;
	while (stash[i])
	{
		new_stash[c++] = stash[i++];
	}
	new_stash[c] = '\0';
	free (stash);
	return (new_stash);
}

char	*ft_read_and_save(int fd, char *stash)
{
	char	*buf;
	int		read_bytes;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read_bytes = 1;
	while (!ft_strchr(stash, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free (buf);
			free (stash);
			return (NULL);
		}
		buf[read_bytes] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*stash[1024];
	
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!stash[fd])
	{
		stash[fd] = malloc (sizeof(char));
		if (!stash[fd])
			return (NULL);
		stash[fd][0] = '\0';
	}
	stash[fd] = ft_read_and_save(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = ft_get_line(stash[fd]);
	if (!line)
	{
		free (stash[fd]);
		return (NULL);
	}
	stash[fd] = ft_clean(stash[fd]);
	return (line);
}
