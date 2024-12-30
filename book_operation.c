#include "s_manager.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

t_book	*read_book(void)
{
	static	int	id;
	t_book	*new_book;
	char		author[100];
	char		name[100];
	int			ret;

	write(STDOUT_FILENO, "name: ", 6);
	ret = read(STDIN_FILENO, name, BUFFER_SIZE);
	if (ret == -1)
	{
		printf("error when reading user input\n");
		return (NULL);
	}
	write(STDOUT_FILENO, "author: ", 8);
	ret = read(STDIN_FILENO, author, BUFFER_SIZE);
	if (ret == -1)
	{
		printf("error when reading user input\n");
		return (NULL);
	}
	new_book = malloc(sizeof(new_book));
	if (!new_book)
	{
		printf("allocation error!");
		return (NULL);
	}
	new_book->id = id++;
	new_book->name = strdup(name);
	if (!new_book->name)
	{
		printf("allocation error!");
		free(new_book);
		return (NULL);
	}
	new_book->author = strdup(author);
	if (!new_book->author)
	{
		printf("allocation error!");
		free(new_book->name);
		free(new_book);
		return (NULL);
	}
	return (new_book);
}