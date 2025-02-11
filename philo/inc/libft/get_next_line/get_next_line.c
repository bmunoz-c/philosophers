/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmunoz-c <bmunoz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:36:35 by ltrevin-          #+#    #+#             */
/*   Updated: 2025/01/13 22:52:18 by bmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_fd(int fd, t_list **lst)
{
	char	*buffer;
	int		bytes_read;

	while (!has_nl(*lst))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (clear_lst(lst));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (!bytes_read)
			return (free(buffer));
		buffer[bytes_read] = '\0';
		if (!add_node(lst, buffer))
			return (clear_lst(lst));
	}
}

char	*save_line(t_list **lst)
{
	int		len;
	t_list	*aux;
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	aux = *lst;
	len = index_newline(*lst);
	if (!len)
		return (NULL);
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (aux)
	{
		while (aux->content[j] && i < len)
			line[i++] = aux->content[j++];
		j = 0;
		aux = aux->next;
	}
	line[i] = '\0';
	return (line);
}

void	save_next(t_list **lst)
{
	t_list	*last;
	char	*content;
	int		start;
	int		i;
	int		len;

	last = last_node(*lst);
	len = 0;
	start = index_newline(last);
	while (last->content[start + len])
		len++;
	if (!len)
		return (clear_lst(lst));
	content = malloc(sizeof(char) * (len + 1));
	if (!content)
		return (clear_lst(lst));
	i = 0;
	while (last->content[start] && i < len)
		content[i++] = last->content[start++];
	content[i] = '\0';
	clear_lst(lst);
	if (!add_node(lst, content))
		return ;
}

char	*get_next_line(int fd)
{
	static t_list	*lst = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (read(fd, line, 0) < 0)
	{
		clear_lst(&lst);
		return (NULL);
	}
	read_fd(fd, &lst);
	if (!lst)
		return (NULL);
	line = save_line(&lst);
	if (!line)
		clear_lst(&lst);
	if (!lst)
		return (NULL);
	save_next(&lst);
	return (line);
}
/*int main(void)
{
	int    fd;
	char  *next_line = " ";
	int  count;

	count = 0;
	printf("Init program\n");
	fd = open("file.txt", O_RDONLY);
	printf("File open succes!\n");
	while (next_line){
		next_line = get_next_line(fd);
		printf("	Returned in [%d]: |%s|\n", count, next_line);
		// free(next_line);
		count++;
	}
	close(fd);
	return (0);
}*/
