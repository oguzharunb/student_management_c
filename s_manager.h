/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_manager.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obastug <obastug@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:36:35 by obastug           #+#    #+#             */
/*   Updated: 2024/12/30 20:37:32 by obastug          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MANAGER_H
# define S_MANAGER_H
#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif

#ifndef BOOK_FILE
# define BOOK_FILE "books.txt"
#endif

#ifndef MEMBER_FILE
# define MEMBER_FILE "members.txt"
#endif

#include <stddef.h>

typedef struct	s_book
{
	unsigned int	id;
	char			*name;
	char			*author;
}	t_book;

typedef struct	s_member
{
	unsigned int	id;
	char			*name;
	char			*phone;
}	t_member;

typedef struct s_borrow
{
	unsigned int	book_id;
	unsigned int	member_id;
	char			*borrow_date;
	char			*retrieve_date;
}	t_borrow;

typedef struct s_node
{
	void	*data;
	void	*next;
}	t_node;

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char *s1, char const *s2);
char		*get_next_line(int fd);


void		write_books_to_file(t_book book_list, int fd);
void		write_members_to_file(t_member	*member_list, int fd);

t_member	*read_members_from_file(int fd);
t_book		*read_books_from_file(int fd);

t_node		*last_node(t_node *list);

