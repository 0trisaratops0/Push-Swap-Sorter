/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   revrotops.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:10:21 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/05/31 18:11:24 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stacks *stack, int check)
{
	int	tmp;
	int	idx;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	idx = stack->size_a - 1;
	tmp = stack->a[idx];
	while (idx)
	{
		stack->a[idx] = stack->a[idx - 1];
		idx--;
	}
	stack->a[idx] = tmp;
	if (check == 0)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_stacks *stack, int check)
{
	int	tmp;
	int	idx;

	if (stack->size_b == 0 || stack->size_b == 1)
		return ;
	idx = stack->size_b - 1;
	tmp = stack->b[idx];
	while (idx)
	{
		stack->b[idx] = stack->b[idx - 1];
		idx--;
	}
	stack->b[idx] = tmp;
	if (check == 0)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_stacks *stack, int check)
{
	int	tmp;
	int	idx;

	if (stack->size_a == 0 || stack->size_a == 1
		|| stack->size_b == 0 || stack->size_b == 1)
		return ;
	idx = stack->size_a - 1;
	tmp = stack->a[idx];
	while (idx)
	{
		stack->a[idx] = stack->a[idx - 1];
		idx--;
	}
	stack->a[idx] = tmp;
	idx = stack->size_b - 1;
	tmp = stack->b[idx];
	while (idx--)
		stack->b[idx] = stack->b[idx - 1];
	if (check == 0)
		write(1, "rrr\n", 4);
}
