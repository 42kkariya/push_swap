/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkariya <kkariya@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 00:00:00 by kkariya           #+#    #+#             */
/*   Updated: 2026/05/24 00:00:00 by kkariya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_list	*ft_listnew(int nb, t_list **cy_list)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		ft_exit(ERROR, *cy_list);
	newnode->nbr = nb;
	newnode->next = NULL;
	newnode->prev = NULL;
	return (newnode);
}

t_list	*ft_listlast(t_list *cy_list)
{
	while (cy_list->next != NULL)
	{
		cy_list = cy_list->next;
	}
	return (cy_list);
}

void	ft_list_add_back(t_list **cy_list, t_list	*new)
{
	t_list	*last;

	if (*cy_list == NULL)
		*cy_list = new;
	else
	{
		last = ft_listlast(*cy_list);
		last->next = new;
		new->prev = last;
	}
}

void	ft_join_list(t_list **cy_list)
{
	t_list	*last;

	last = ft_listlast(*cy_list);
	last->next = *cy_list;
	(*cy_list)->prev = last;
}

void	ft_make_cy_list(t_list	**cy_list, t_frag *frag, int argc, char **argv)
{
	int	i;
	int	nb;

	i = 0;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			ft_check_frag(&argv[i][2], frag, cy_list);
		else if ((argv[i][0] >= '0' && argv[i][0] <= '9')
				|| argv[i][0] == '-' || argv[i][0] == '+')
		{
			nb = ft_atoi(argv[i], cy_list);
			ft_list_add_back(cy_list, ft_listnew(nb, cy_list));
		}
		else
			ft_exit(ERROR, *cy_list);
		i++;
	}
	ft_join_list(cy_list);
}
