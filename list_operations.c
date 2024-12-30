#include "s_manager.h"
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

t_node	*last_node(t_node *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_member	*find_member_by_id(t_node *member_list, unsigned int id)
{
	if (!member_list)
		return (NULL);
	while (member_list)
	{
		if (((t_member *)member_list->data)->id == id)
			return (member_list->data);
		member_list = member_list->next;
	}
	return (member_list->data);
}