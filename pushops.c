/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushops.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:12:02 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/05/31 18:12:42 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stacks *stack, int check)
{
	int	idx;

	if (stack->size_b)
	{
		stack->size_a++;
		idx = stack->size_a;
		while (--idx > 0)
			stack->a[idx] = stack->a[idx - 1];
		stack->a[0] = stack->b[0];
		idx = -1;
		stack->size_b--;
		while (++idx < stack->size_b)
			stack->b[idx] = stack->b[idx + 1];
		if (check == 0)
			write(1, "pa\n", 3);
	}
	else
		return ;
}

void	ft_pb(t_stacks *stack, int check)
{
	int	idx;

	if (stack->size_a)
	{
		stack->size_b++;
		idx = stack->size_b;
		while (--idx > 0)
			stack->b[idx] = stack->b[idx - 1];
		stack->b[0] = stack->a[0];
		idx = -1;
		stack->size_a--;
		while (++idx < stack->size_a)
			stack->a[idx] = stack->a[idx + 1];
		if (check == 0)
			write(1, "pb\n", 3);
	}
	else
		return ;
}
