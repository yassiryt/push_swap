/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:15:40 by yatanagh          #+#    #+#             */
/*   Updated: 2025/04/08 01:56:44 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct stab
{
	int	*tab_a;
	int	*tab_b;
	int	top_a;
	int	top_b;
}t_stab;

void		sb(int *t, int top, char c);
void		sa(int *t, int top, char c);
void		ss(int *t_a, int top_a, int *t_b, int top_b);
void		pb(int *t_a, int *top_a, int *t_b, int *top_b);
void		pa(int *t_a, int *top_a, int *t_b, int *top_b);
void		ra(int *t, int top, char c);
void		rb(int *t, int top, char c);
void		rr(int *t_a, int top_a, int *t_b, int top_b);
void		rra(int *t, int top, char c);
void		rrb(int *t, int top, char c);
void		rrr(int *t_a, int top_a, int *t_b, int top_b);
int			find_j(int *t, int top, int j);
int			check_arg(char **v);
int			check_repeat(int *t, int top);
long long	ft_atoi(char *str, t_stab *var, char **v);
void		indexing(t_stab *var);
void		push_sorted_to_b(t_stab *var);
void		push_sorted_to_a(t_stab *var);
int			check_if_sorted(int *t, int top);
void		sort_3nb(t_stab *var, int c);
int			find_small(int *t, int top);
int			find_i(int *t, int top, int find);
void		push_to_b(t_stab *var);
void		sort_5nb(t_stab *var, int c);
void		ft_putstr(char *s);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strlen(char *s);
char		**ft_split(char *s, char c);
void		qu(int c);
void		quit(t_stab *va, int c, char **v);
int			check_space(char **v);
void		nor(t_stab *var);
void		param_to_var(t_stab *var, char **v, int c);
void		free_string_array(char **v);
#endif
