/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:28:16 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/06/02 23:56:08 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_action(char **argv)
{
	t_stacks		stack;
	int				size;
	int				i;

	i = -1;
	size = ft_input_size(argv);
	stack.a = malloc(sizeof(int) * size);
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = malloc(sizeof(int) * size);
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.size_b = 0;
	while (++i < size)
		stack.a[i] = ft_atoi_stack(argv[i], stack.a);
	ft_double_checker(stack.a, size);
	sort(&stack, size);
	free(stack.a);
	free(stack.b);
}

static void	ft_free_array(char **split_arr)
{
	int	i;

	i = 0;
	while (split_arr[i])
	{
		free(split_arr[i]);
		i++;
	}
	free(split_arr);
}

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (0);
	argv++;
	if (argc > 1)
	{
		if (argc == 2)
		{
			argv = ft_split(*argv, ' ');
			ft_action(argv);
			ft_free_array(argv);
		}
		else
			ft_action(argv);
		return (0);
	}
}
