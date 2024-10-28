/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:07:46 by yurolive          #+#    #+#             */
/*   Updated: 2024/10/21 14:26:54 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"
/*The get_next_line function reads a line from the file descriptor (fd).
   Each subsequent call to the function will return the next line from the 
   same file descriptor. The function can handle multiple file descriptors 
   simultaneously, returning the next line for each one independently.*/

char	*ft_free_gnl(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

static char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free_gnl(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free_gnl(&storage));
	new_storage = ft_substr(storage, len, ft_strlen(storage) - len);
	ft_free_gnl(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

static char	*new_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchr(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substr(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*readbuf(int fd, char *storage)
{
	int		rid;
	char	*buffer;

	rid = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free_gnl(&storage));
	buffer[0] = '\0';
	while (rid > 0 && !ft_strchr(buffer, '\n'))
	{
		rid = read (fd, buffer, BUFFER_SIZE);
		if (rid > 0)
		{
			buffer[rid] = '\0';
			storage = ft_strjoin_gnl(storage, buffer);
		}
	}
	free(buffer);
	if (rid == -1)
		return (ft_free_gnl(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[65536];
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage[fd] && !ft_strchr(storage[fd], '\n')) || !storage[fd])
		storage[fd] = readbuf (fd, storage[fd]);
	if (!storage[fd])
		return (NULL);
	line = new_line(storage[fd]);
	if (!line)
		return (ft_free_gnl(&storage[fd]));
	storage[fd] = clean_storage(storage[fd]);
	return (line);
}
