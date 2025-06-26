/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trisort.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:14:49 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/05/31 18:26:21 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sorter_a(t_stacks *three)
{
	if (three->a[0] > three->a[1] && three->a[0] < three->a[2]
		&& three->a[1] < three->a[2])
		ft_sa(three, 0);
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] > three->a[2])
	{
		ft_sa(three, 0);
		ft_rra(three, 0);
	}
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] < three->a[2])
		ft_ra(three, 0);
	if (three->a[0] < three->a[1] && three->a[0] < three->a[2]
		&& three->a[1] > three->a[2])
	{
		ft_sa(three, 0);
		ft_ra(three, 0);
	}
	if (three->a[0] < three->a[1] && three->a[0] > three->a[2]
		&& three->a[1] > three->a[2])
		ft_rra(three, 0);
}

int	ft_push(t_stacks *stack, int len, int push)
{
	if (push == 0)
		ft_pb(stack, 0);
	else
		ft_pa(stack, 0);
	len--;
	return (len);
}

void	three_sorter_ab(t_stacks *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		three_sorter_a(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack, 0);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack, 0);
			else if (len == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack, 0);
			else if (len++)
				ft_pa(stack, 0);
		}
	}
}

int	three_sorter_b(t_stacks *stack, int len)
{
	if (len == 1)
		ft_pa(stack, 0);
	else if (len == 2)
	{
		if (stack->b[0] < stack->b[1])
			ft_sb(stack, 0);
		while (len--)
			ft_pa(stack, 0);
	}
	else if (len == 3)
	{
		while (len || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (len == 1 && stack->a[0] > stack->a[1])
				ft_sa(stack, 0);
			else if (len == 1 || (len >= 2 && stack->b[0] > stack->b[1])
				|| (len == 3 && stack->b[0] > stack->b[2]))
				len = ft_push(stack, len, 1);
			else
				ft_sb(stack, 0);
		}
	}
	return (0);
}
