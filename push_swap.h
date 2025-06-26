/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sjeddi <marvin@codam.nl>                     +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 18:59:00 by sjeddi        #+#    #+#                 */
/*   Updated: 2023/06/02 17:41:13 by sjeddi        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_count_word(char const*s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
char	**ft_split(char const *s, char c);
void	ft_error_detector(int *stack);
int		ft_atoi_stack(char *str, int *stack);
int		ft_input_size(char **argv);
int		ft_correct_order(int *stack, int size, int order);
void	ft_double_checker(int *stack, int size);
void	ft_action(char **argv);
int		main(int argc, char **argv);
void	ft_pa(t_stacks *stack, int check);
void	ft_pb(t_stacks *stack, int check);
void	temp_sort(int *temp_stack, int size);
int		ft_median(int *pivot, int *stack, int size);
int		ft_sort_a(t_stacks *stack, int len, int counter);
int		ft_sort_b(t_stacks *stack, int len, int counter);
int		sort(t_stacks *stack, int size);
void	ft_rra(t_stacks *stack, int check);
void	ft_rrb(t_stacks *stack, int check);
void	ft_rrr(t_stacks *stack, int check);
void	ft_ra(t_stacks *stack, int check);
void	ft_rb(t_stacks *stack, int check);
void	ft_rr(t_stacks *stack, int check);
void	ft_sa(t_stacks *stack, int check);
void	ft_sb(t_stacks *stack, int check);
void	ft_ss(t_stacks *stack, int check);
void	three_sorter_a(t_stacks *three);
int		ft_push(t_stacks *stack, int len, int push);
void	three_sorter_ab(t_stacks *stack, int len);
int		three_sorter_b(t_stacks *stack, int len);
#endif
