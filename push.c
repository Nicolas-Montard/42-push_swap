/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmontard <nmontard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:44:33 by nmontard          #+#    #+#             */
/*   Updated: 2025/12/18 13:55:37 by nmontard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/stack.h"
#include "stdlib.h"

void	pa(t_stack *a, t_stack *b)
{
	if (b->head->value == NULL)
		return ;
	a->head->previous->value = b->head->value;
	a->head = a->head->previous;
	b->head->value = NULL;
	b->head = b->head->next;
	a->size += 1;
	b->size -= 1;
}

void	pb(t_stack *b, t_stack *a)
{
	if (a->head->value == NULL)
		return ;
	b->head->previous->value = a->head->value;
	b->head = b->head->previous;
	a->head->value = NULL;
	a->head = a->head->next;
	b->size += 1;
	a->size -= 1;
}

int	main(void)
{
	t_stack *stackA;
	t_stack *stackB;
	int value1 = 6;
	int value2 = 8;
	int value3 = 10;
	int value4 = 12;
	int value5 = 14;

	stackA = malloc(sizeof(t_stack));
	stackA->size = 5;
	stackB = malloc(sizeof(t_stack));
	stackB->size = 0;
	add_node(stackA, &value1);
	add_node(stackA, &value2);
	add_node(stackA, &value3);
	add_node(stackA, &value4);
	add_node(stackA, &value5);
	add_node(stackB, NULL);
	add_node(stackB, NULL);
	add_node(stackB, NULL);
	add_node(stackB, NULL);
	add_node(stackB, NULL);
	stackA->head->previous = get_last_node(stackA);
	stackA->head->previous->next = stackA->head;
	stackB->head->previous = get_last_node(stackB);
	stackB->head->previous->next = stackB->head;
	printf("%d\n", *stackA->head->value);
	printf("%d\n", *stackA->head->next->value);
	printf("%d\n", *stackA->head->next->next->value);
	printf("%d\n", *stackA->head->next->next->next->value);
	printf("%d\n", *stackA->head->next->next->next->next->value);
	pb(stackB, stackA);
	pb(stackB, stackA);
	pb(stackB, stackA);
	printf("\n\n\n");
	printf("%d\n", *stackA->head->value);
	printf("%d\n", *stackA->head->next->value);
	printf("%d\n", *stackB->head->value);
	printf("%d\n", *stackB->head->next->value);
	printf("%d\n", *stackB->head->next->next->value);
}