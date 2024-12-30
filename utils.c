#include <stdlib.h>
#include "s_manager.h"
#include <string.h>
#include <stddef.h>
#include <unistd.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (strlen(src));
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (strlen(src));
}
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = strlen(dst);
	src_len = strlen(src);
	i = 0;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (i < dstsize - dst_len - 1 && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	char	*str;
	size_t	len;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		*s1 = '\0';
	}
	len = strlen(s1) + strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * len);
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	ft_strlcpy(str, s1, len);
	ft_strlcat(str, s2, len);
	free(s1);
	return (str);
}

static char	*substr_until_newline(char *buffer)
{
	char		*line;
	size_t		i;
	size_t		j;

	i = 0;
	if (buffer == NULL || !buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + (buffer[i] == '\n') + 1));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = buffer[j];
		j++;
	}
	if (buffer[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*assign_leftover_string_to_buffer(char *buffer)
{
	char		*new_buffer;
	size_t		i;
	size_t		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	new_buffer = (char *)malloc(sizeof(char) * (strlen(buffer) - i + 1));
	if (new_buffer == NULL)
		return (free(buffer), NULL);
	i++;
	j = 0;
	while (buffer[i])
		new_buffer[j++] = buffer[i++];
	new_buffer[j] = '\0';
	return (free(buffer), new_buffer);
}

static char	*read_and_assign_to_buffer(int fd, char *buffer)
{
	char		*rd_buffer;
	ssize_t		rd_bytes;

	rd_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (rd_buffer == NULL)
		return (free(buffer), NULL);
	rd_bytes = 1;
	while (!strchr(buffer, '\n') && rd_bytes > 0)
	{
		rd_bytes = read(fd, rd_buffer, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (free(rd_buffer), free(buffer), NULL);
		rd_buffer[rd_bytes] = '\0';
		buffer = ft_strjoin(buffer, rd_buffer);
		if (buffer == NULL)
			return (free(rd_buffer), NULL);
	}
	return (free(rd_buffer), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_and_assign_to_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = substr_until_newline(buffer[fd]);
	if (line == NULL)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = assign_leftover_string_to_buffer(buffer[fd]);
	return (line);
}
