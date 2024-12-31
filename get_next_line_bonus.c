/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteffahi <mteffahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 20:14:10 by mteffahi          #+#    #+#             */
/*   Updated: 2024/12/31 20:48:06 by mteffahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_fdlst	*ft_reading(t_fdlst **lst, int fd)
{
	t_fdlst	*new;
	int		rd;

	if (!lst)
		return (NULL);
	new = *lst;
	if (!new->remainder)
	{
		new->remainder = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!new->remainder)
			return (NULL);
		rd = 1;
		while (rd > 0)
		{
			rd = read(fd, new->remainder, BUFFER_SIZE);
			if (rd <= 0)
				break ;
			new->remainder[rd] = '\0';
		}
	}
}

static t_fdlst	*gt_fd_nd(t_fdlst	**lst, int fd)
{
	t_fdlst		*new_node;
	t_fdlst		*node;
	
	node = *lst;
	while (node)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	new_node = malloc(sizeof(t_fdlst));
	if (new_node)
		return (NULL);
	new_node->fd = fd;
	new_node->remainder = NULL;
	new_node->next = *lst;
	*lst = new_node;
	return (new_node);
}

char	*get_next_line_bonus(int fd)
{
	static t_fdlst	*fd_linked_list;
	char			*line;
	t_fdlst			*current;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = gt_fd_nd(&fd_linked_list, current);
	if (!current)
		return (NULL);
}