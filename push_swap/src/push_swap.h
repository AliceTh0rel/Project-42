/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: althorel <althorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:46:06 by althorel          #+#    #+#             */
/*   Updated: 2025/08/13 12:28:45 by althorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
//ft_printf
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
//parsing
# include <stdlib.h>

typedef struct s_stack
{
	int					nbr;
	int					index;
	int					index_value;
	struct s_stack		*target;
	struct s_stack		*next;
}	t_stack;

typedef struct s_action
{
	int		best_cost;
	int		which_one;
	int		ra;
	int		rra;
	int		ra_target;
	int		rra_target;
}	t_action;

typedef struct s_move
{
	int		best_cost;
	int		first;
	int		current_cost;
}	t_move;

//cost
t_stack	*best_move(t_stack **a, t_stack **b);
int		cost_ra(t_stack *stack);
int		cost_rra(t_stack *stack, t_stack *head);
int		cost_for_one(t_stack *stack, t_stack **a, t_stack **b);

//ft_printf
int		ft_check_letter(char c, va_list *ap, int *len);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putnbr_long(long int n, int *len);
void	ft_putnbr_unsigned(unsigned int n, int *len);

//init_stack
t_stack	*ft_lstlast(t_stack *lst);
void	init_stack_a(t_stack **a, int nb);
int		ft_lstsize(t_stack *lst);

//instructions
void	ss(t_stack **head_a, t_stack **head_b);
void	rr(t_stack **lst_a, t_stack **lst_b);
void	rrr(t_stack **lst_a, t_stack **lst_b);
void	sa(t_stack **head);
void	pa(t_stack **src, t_stack **dest);
void	ra(t_stack **lst);
void	rra(t_stack **lst);
void	sb(t_stack **head);
void	pb(t_stack **src, t_stack **dest);
void	rb(t_stack **lst);
void	rrb(t_stack **lst);
void	ft_swap(t_stack **head);
void	ft_push(t_stack **src, t_stack **dest);
void	ft_rotate(t_stack **lst);
void	ft_reverse_rotate(t_stack **lst);
t_stack	*ft_last(t_stack *lst);

//move
void	do_one(t_stack **a, t_stack **b, t_stack *best);
void	do_two(t_stack **a, t_stack **b, t_stack *best);
void	do_three(t_stack **a, t_stack **b, t_stack *best);
void	do_four(t_stack **a, t_stack **b, t_stack *best);
void	move_stack(t_stack **a, t_stack **b);

//parsing
void	error(char **av, int split_y, int i, t_stack **a);
void	check(char **av, t_stack **a, int split_y);
int		ft_atol_check(char *str);
int		syntaxe(char *str);
int		ft_atol(char *str);

//sort
t_stack	*find_min(t_stack *a);
t_stack	*find_min_value(t_stack *a);
int		stack_sorted(t_stack *a);
int		which_action(int ra, int rra, int ra_target, int rra_target);
int		action(t_stack *stack, t_stack **a, t_stack **b);
void	sort_two(t_stack **a);
void	sort_three(t_stack **a);
void	end_of_sort(t_stack **a);
void	sort_all(t_stack **a, t_stack **b);
void	sort_five_move(t_stack**a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);

//split
int		is_space(char c);
char	**split(char *str);
char	*substr(char *str, int i, int len);
void	free_split(char **str);
int		count_word(char *str);

//target
void	give_index(t_stack *stack);
void	choose_target(t_stack *tmp_a, t_stack *tmp_b,
			t_stack **target_min, t_stack **target_max);
void	find_target(t_stack *a, t_stack *b);

//main
void	free_stack(t_stack **stack);

#endif