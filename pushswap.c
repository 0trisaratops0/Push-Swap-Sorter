/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:36:32 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/05/31 19:42:24 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	temp_sort(int *temp_stack, int size)
{
	int	idx1;
	int	idx2;
	int	tmp;

	idx1 = 0;
	while (idx1 < size)
	{
		idx2 = idx1 + 1;
		while (idx2 < size)
		{
			if (temp_stack[idx1] > temp_stack[idx2])
			{
				tmp = temp_stack[idx1];
				temp_stack[idx1] = temp_stack[idx2];
				temp_stack[idx2] = tmp;
			}
			idx2++;
		}
		idx1++;
	}
}

int	ft_median(int *pivot, int *stack, int size)
{
	int		*tmp_stack;
	int		idx;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (0);
	idx = 0;
	while (idx < size)
	{
		tmp_stack[idx] = stack[idx];
		idx++;
	}
	temp_sort(tmp_stack, size);
	*pivot = tmp_stack[size / 2];
	free(tmp_stack);
	return (1);
}

int	ft_sort_a(t_stacks *stack, int len, int counter)
{
	int	pivot;
	int	nbrs;

	if (ft_correct_order(stack->a, len, 0) == 1)
		return (1);
	nbrs = len;
	if (len <= 3)
	{
		three_sorter_ab(stack, len);
		return (1);
	}
	if (!ft_median(&pivot, stack->a, len))
		return (0);
	while (len != nbrs / 2 + nbrs % 2)
	{
		if (stack->a[0] < pivot && (len--))
			ft_pb(stack, 0);
		else if (++counter)
			ft_ra(stack, 0);
	}
	while (nbrs / 2 + nbrs % 2 != stack->size_a && counter--)
		ft_rra(stack, 0);
	return (ft_sort_a(stack, nbrs / 2 + nbrs % 2, 0)
		&& ft_sort_b(stack, nbrs / 2, 0));
	return (1);
}

int	ft_sort_b(t_stacks *stack, int len, int counter)
{
	int	pivot;
	int	nbrs;

	if (ft_correct_order(stack->b, len, 1) == 1)
		while (len--)
			ft_pa(stack, 0);
	if (len <= 3)
	{
		three_sorter_b(stack, len);
		return (1);
	}
	nbrs = len;
	if (!ft_median(&pivot, stack->b, len))
		return (0);
	while (len != nbrs / 2)
	{
		if (stack->b[0] >= pivot && len--)
			ft_pa(stack, 0);
		else if (++counter)
			ft_rb(stack, 0);
	}
	while (nbrs / 2 != stack->size_b && counter--)
		ft_rrb(stack, 0);
	return (ft_sort_a(stack, nbrs / 2 + nbrs % 2, 0)
		&& ft_sort_b(stack, nbrs / 2, 0));
}

int	sort(t_stacks *stack, int size)
{
	if (ft_correct_order(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			ft_sa(stack, 0);
		else if (size == 3)
			three_sorter_a(stack);
		else
			ft_sort_a(stack, size, 0);
	}
	return (0);
}
