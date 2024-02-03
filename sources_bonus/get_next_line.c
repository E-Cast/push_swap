/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecastong <ecastong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 07:38:00 by ecastong          #+#    #+#             */
/*   Updated: 2024/02/03 15:44:41 by ecastong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	safe_free(void *ptr)
{
	if (ptr)
	{
		free(ptr);
		ptr = NULL;
	}
}

static char	*str_utils(char *str1, char *str2, char *dest)
{
	ssize_t	i;
	size_t	j;

	if (ft_strlen(str1) + ft_strlen(str2) == 0)
		return (NULL);
	if (!dest)
	{
		dest = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
		if (!dest)
		{
			safe_free(str1);
			return (NULL);
		}
	}
	i = 0;
	j = 0;
	while (str1 && str1[i])
		dest[i++] = str1[j++];
	j = 0;
	while (str2 && str2[j])
		dest[i++] = str2[j++];
	dest[i] = '\0';
	safe_free(str1);
	return (dest);
}

static char	*ft_strchr(const char *str, int chr)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)chr)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)chr)
		return ((char *)&str[i]);
	return (NULL);
}

static void	ft_bzero(void *str, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!str)
		return ;
	ptr = (char *)str;
	i = 0;
	while (i < len)
		ptr[i++] = 0;
}

static int	read_fd(int fd, char *stash, char **line)
{
	int	b_read;

	b_read = 1;
	if (stash[0] == '\0')
	{
		b_read = read(fd, stash, BUFFER_SIZE);
		if (b_read == 0)
			return (0);
		if (b_read == -1)
		{
			safe_free(*line);
			return (-1);
		}
	}
	*line = str_utils(*line, stash, NULL);
	if (*line == NULL)
		return (-1);
	ft_bzero(stash, BUFFER_SIZE);
	return (b_read);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	int			errcode;

	if (fd < 0 || fd >= 100 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (!ft_strchr(line, '\n'))
	{
		errcode = read_fd(fd, stash, &line);
		if (errcode == 0)
			return (line);
		if (errcode == -1)
			return (NULL);
	}
	str_utils(NULL, &line[ft_strchr(line, '\n') - line + 1], stash);
	line[ft_strchr(line, '\n') - line + 1] = '\0';
	return (str_utils(line, NULL, NULL));
}
