/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarlos <ancarlos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 16:56:14 by ancarlos          #+#    #+#             */
/*   Updated: 2025/12/23 16:56:15 by ancarlos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"


void ft_lstadd_back(t_gnl **lst, t_gnl*new)
{
	t_gnl	*temp;

	if(!lst || !new)
		return ;
	if(*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_gnl *ft_lstnew(char *content)
{
	t_gnl	*node;

	node = malloc(sizeof(t_gnl));
	if(!node)
		return (NULL);
	node->line = content;
	node->next = NULL;
	return (node);
}