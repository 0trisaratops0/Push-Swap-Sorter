/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checks.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 17:50:08 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/06/02 20:01:01 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_detector(int *stack)
{
	free(stack);
	write(1, "Error\n", 6);
	exit (1);
}

int	ft_atoi_stack(char *str, int *stack)
{
	unsigned int		idx;
	int					sign;
	unsigned long int	res;

	idx = 0;
	res = 0;
	sign = 1;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == ' ')
		idx++;
	if (str[idx] == '-')
		sign = -1;
	if (str[idx] == '+' || str[idx] == '-')
		idx++;
	while (str[idx])
	{
		if (str[idx] < '0' || str[idx] > '9')
			ft_error_detector(stack);
		res = (str[idx] - '0') + (res * 10);
		idx++;
	}
	if ((res > 2147483648 && sign == -1)
		|| (res > 2147483647 && sign == 1))
		ft_error_detector(stack);
	return (res * sign);
}

int	ft_input_size(char **argv)
{
	int	idx;

	idx = 0;
	while (*argv)
	{
		argv++;
		idx++;
	}
	return (idx);
}

int	ft_correct_order(int *stack, int size, int order)
{
	int	idx;

	if (order == 0)
	{
		idx = 1;
		while (idx < size)
		{
			if (stack[idx - 1] > stack[idx])
				return (0);
			idx++;
		}
		return (1);
	}
	else
	{
		idx = 1;
		while (idx < size)
		{
			if (stack[idx - 1] < stack[idx])
				return (0);
			idx++;
		}
		return (1);
	}
}

void	ft_double_checker(int *stack, int size)
{
	int	idx1;
	int	idx2;

	idx1 = 0;
	idx2 = 1;
	while (idx1 < size)
	{
		while (idx2 < size)
		{
			if (stack[idx1] == stack[idx2])
				ft_error_detector(stack);
			idx2++;
		}
		idx1++;
		idx2 = idx1 + 1;
	}
}
