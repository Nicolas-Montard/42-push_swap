/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aslimani <aslimani@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:44:33 by nmontard          #+#    #+#             */
/*   Updated: 2026/01/13 15:05:41 by aslimani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/list_utils.h"
#include "headers/stack.h"
#include "headers/ft_printf.h"
#include <stdlib.h>

void	pa(t_stack *a, t_stack *b)
{
	if (b->head == NULL)
		return ;
	add_node(a, b->head->value);
	remove_node(b, b->head);
	ft_printf("pa\n");
}

void	pb(t_stack *b, t_stack *a)
{
	if (a->head == NULL)
		return ;
	add_node(b, a->head->value);
	remove_node(a, a->head);
	ft_printf("pb\n");
}
