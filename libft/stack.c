/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaley <agaley@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:07:18 by agaley            #+#    #+#             */
/*   Updated: 2023/04/30 14:24:28 by agaley           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Initialize memory allocation stack anchor
 * @return t_stack* or NULL if malloc fails
 */
t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	return (stack);
}

/**
 * Adds an element to a memory allocation stack
 * @param stack pointer towards stack anchor
 * @param new_addr the address of the allocated item
 */
void	stack_add(t_stack *stack, void *new_addr)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(*new));
	if (stack == NULL || new == NULL)
	{
		ft_printf("Stacking error");
		return ;
	}
	new->addr = new_addr;
	new->next = stack->head;
	stack->head = new;
}

/**
 * Removes last element from a memory allocation stack
 * @param stack pointer towards stack anchor
 */
void	pop(t_stack *stack)
{
	t_node	*popped;
	void	*address_to_pop;

	if (stack == NULL)
	{
		ft_printf("Popping_error");
		return ;
	}
	else if (stack->head)
	{
		popped = NULL;
		popped = stack->head;
		address_to_pop = popped->addr;
		if (address_to_pop != NULL)
			free(address_to_pop);
		stack->head = popped->next;
		free(popped);
	}
}

/**
 * Frees a memory allocation stack and all elements in it
 * @param stack pointer towards stack anchor
 */
void	free_stack(t_stack *stack)
{
	while (stack && stack->head)
		pop(stack);
	free(stack);
}

/**
 * Malloc and adds element to a memory allocation stack
 * @param stack pointer towards stack anchor
 * @param size size_t to be allocated by malloc
 */
void	*malloc_n_collect(t_stack *stack, size_t size)
{
	void	*addr;

	addr = malloc(size);
	if (!addr)
		return (NULL);
	stack_add(stack, addr);
	return (addr);
}
