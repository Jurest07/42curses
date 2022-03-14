/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slight <slight@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 23:44:37 by slight            #+#    #+#             */
/*   Updated: 2022/03/14 21:24:03 by slight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stddef.h>
# include "../libft/libft.h"
# define FALSE 0
# define TRUE 1
# define DIGITS "+-0123456789"
# define MAXINT 2147483647 // INT_MAX
# define MININT -2147483648 // INT_MIN

typedef int	t_bool;

typedef struct s_list_swap
{
	int					data;
	int					a_source;
	int					b_source;
	struct s_list_swap	*next;
}				t_list_swap;

typedef struct s_score_a
{
	int	a_score;
	int	pred;
	int	flag;
	int	ff;
}				t_score_a;

typedef struct s_mainst
{
	int	c_ints;
	int	c_ints_in_param;
	int	mediana;
	int	iter;
}				t_mainst;

typedef struct s_lists
{
	t_list_swap	*a;
	t_list_swap	*b;
	int			max_score_of_sort;
	int			pos_of_first;
	int			pos_of_end;
	int			val_of_first;
	int			val_of_end;
	int			all_numbers_count;
	int			iter;
	int			numbers_in_a;
	int			numbers_in_b;
	int			mediana;
	int			iters_with_a;
	int			iters_with_b;
}				t_lists;

void		push(t_list_swap **head, int data);
int			pop(t_list_swap **head);
t_list_swap	*getnth(t_list_swap *head, int n);
t_list_swap	*getlast(t_list_swap *head);
t_list_swap	*getlastlast(t_list_swap *head);
void		pushback(t_list_swap *head, int data);

void		init_mainst(t_mainst *ps);
void		init_score_a(t_score_a *sca);

void		sa(t_list_swap **a, int flag);
void		sb(t_list_swap **b, int flag);
void		ss(t_list_swap **a, t_list_swap **b, int flag);
void		pa(t_list_swap **a, t_list_swap **b, int flag);
void		pb(t_list_swap **a, t_list_swap **b, int flag);
void		ra(t_list_swap **a, int flag);
void		rb(t_list_swap **b, int flag);
void		rr(t_list_swap **a, t_list_swap **b, int flag);
void		rra(t_list_swap **a, int flag);
void		rrb(t_list_swap **b, int flag);
void		rrr(t_list_swap **a, t_list_swap **b, int flag);

t_bool		check_inputs(int coll, char *inputs[], t_mainst *ps);
t_bool		check_on_ints(int coll, char *inputs[], t_mainst *ps);
void		die(char *mes, int fd);
char		*skip_spases_begin_end(char *s);
t_bool		check_maxmin_and_equal(int coll, char *inputs[], t_mainst *ps);
void		init_lists(t_lists *lists, int argc, char *argv[], t_mainst *ps);
t_bool		check_string(char *s, long tmp[], int *t);
void		find_max_sort(t_lists *lists);
void		sort_iteration(t_lists *lists);
int			calc_med(long numbers[], int coll);
void		find_scores(t_lists *lists);
int			calc_sum_iters(int a, int b);
void		do_operations(t_lists *lists);
void		find_min_iters(t_lists *lists);
int			find_score_iters_a(t_lists *lists, int val);
int			find_score_iters_b(t_lists *lists, int *b_score);
void		final_reverse(t_lists *lists);
int			find_min_num(t_lists *lists);
int			ft_abs(int num);
void		clounada_with_do_operations(t_lists *lists);
void		clounada_with_do_operations2(t_lists *lists);
void		clounada_with_check_min(t_lists *lists, int val, int *flag);
t_bool		check_str(char *str);
void		free_lists(t_lists *lists);
#endif