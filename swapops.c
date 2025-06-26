/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swapops.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:13:14 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/05/31 19:10:33 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stacks *stack, int check)
{
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	if (check == 0)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stacks *stack, int check)
{
	int	tmp;

	if (stack->size_b == 0 || stack->size_b == 0)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (check == 0)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stacks *stack, int check)
{
	int	tmp;

	if (stack->size_a == 0 || stack->size_a == 1
		|| stack->size_b == 0 || stack->size_b == 1)
		return ;
	tmp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = tmp;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	if (check == 0)
		write(1, "ss\n", 3);
}
