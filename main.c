#include <stdio.h>
#include "s_manager.h"
#include <unistd.h>
#include <fcntl.h>
int	manager(void)
{
	t_node		*member_list;
	t_node		*book_list;
	int			book_file;
	int			member_file;

	member_file = open(MEMBER_FILE, O_CREAT | O_RDWR);
	book_file = open(BOOK_FILE, O_CREAT | O_RDWR);
	member_list = NULL;//read_books_from_file(member_file);
	book_list = NULL;//read_members_from_file(book_file);
	(void)member_file;
	(void)book_file;
	(void)member_list;
	(void)book_list;
	return (1);
}

int main(void)
{
	/* code */
	return 0;
}
