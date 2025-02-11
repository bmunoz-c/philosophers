/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:36:37 by ltrevin-          #+#    #+#             */
/*   Updated: 2025/01/13 22:54:48 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	has_nl(t_list *lst)
{
	t_list	*last;
	int		i;

	if (!lst)
		return (0);
	last = last_node(lst);
	i = 0;
	while (last->content[i] != '\0')
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*last_node(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_list	*add_node(t_list **lst, char *content)
{
	t_list	*new_node;
	t_list	*last_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		last_node = *lst;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
	}
	return (new_node);
}

int	index_newline(t_list *lst)
{
	t_list	*tmp;
	int		len;
	int		i;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			len++;
			if (tmp->content[i] == '\n')
				break ;
			i++;
		}
		tmp = tmp->next;
	}
	return (len);
}

void	clear_lst(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}
