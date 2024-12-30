#include "s_manager.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

t_member	*read_member(void)
{
	static	int	id;
	t_member	*new_member;
	char		name[100];
	char		phone[100];
	int			ret;

	write(STDOUT_FILENO, "name: ", 6);
	ret = read(STDIN_FILENO, name, BUFFER_SIZE);
	if (ret == -1)
	{
		printf("error when reading user input\n");
		return (NULL);
	}
	write(STDOUT_FILENO, "phone: ", 7);
	ret = read(STDIN_FILENO, phone, BUFFER_SIZE);
	if (ret == -1)
	{
		printf("error when reading user input\n");
		return (NULL);
	}
	new_member = malloc(sizeof(new_member));
	if (!new_member)
	{
		printf("allocation error!");
		return (NULL);
	}
	new_member->id = id++;
	new_member->name = strdup(name);
	if (!new_member->name)
	{
		printf("allocation error!");
		free(new_member);
		return (NULL);
	}
	new_member->phone = strdup(phone);
	if (!new_member->phone)
	{
		printf("allocation error!");
		free(new_member->name);
		free(new_member);
		return (NULL);
	}
	return (new_member);
}

int	add_member(t_node **member_list, t_member *new_member)
{
	t_node	*last;
	if (!*member_list)
		(*member_list)->data = (void *)new_member;
	else
	{
		last->data = (void *)last_node(*member_list);
		last->next = (void *)new_member;
	}
}

int	delete_member(t_node *member_list, unsigned int id)
{

}



int	show_members(t_node *member_list)
{

}