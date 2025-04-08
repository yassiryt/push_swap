/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yatanagh <yatanagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 02:51:50 by yatanagh          #+#    #+#             */
/*   Updated: 2025/04/08 03:06:33 by yatanagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_string_array(char **v)
{
	int	i;

	i = 0;
	if (v)
	{
		while (v[i])
		{
			free(v[i]);
			i++;
		}
		free(v);
	}
}

char	**parc(char **v, char **tmp, int *c)
{
	int		i;
	char	*tab;

	i = 1;
	tab = NULL;
	if (check_space(v) == 0)
		quit(0, 5, 0);
	while (v[i])
	{
		tab = ft_strjoin(tab, v[i++]);
		tab = ft_strjoin(tab, "  ");
	}
	tmp = ft_split(tab, ' ');
	free(tab);
	if (!tmp)
	{
		write(1, "error\n", 6);
		exit (1);
	}
	i = 0;
	while (tmp[i])
		i++;
	*c = i;
	return (tmp);
}

static void	handle_small_sort(t_stab *var, int c, char **v_tmp)
{
	if (c <= 4)
		sort_3nb(var, c);
	else if (c > 4)
		sort_5nb(var, c);
	quit(var, 0, v_tmp);
}

static void	init_and_validate(t_stab *var, char ***tmp, int *c, char **v)
{
	*tmp = parc(v, *tmp, c);
	if (check_arg(*tmp) == 0)
		quit(var, 1, *tmp);
	param_to_var(var, *tmp, (*c)++);
	if (check_repeat(var->tab_a, var->top_a) == 0)
		quit(var, 1, *tmp);
}

int	main(int argc, char **argv)
{
	t_stab	var;
	char	**tmp;

	var = (t_stab){0};
	tmp = NULL;
	qu(argc);
	init_and_validate(&var, &tmp, &argc, argv);
	if (check_if_sorted(var.tab_a, var.top_a) == 0)
		quit(&var, 0, tmp);
	if (argc >= 3 && argc <= 6)
		handle_small_sort(&var, argc, tmp);
	nor(&var);
	quit(&var, 2, tmp);
}
