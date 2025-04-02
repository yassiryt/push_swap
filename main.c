#include "push_swap.h"

static void	free_string_array(char **v)
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

void	quit(t_stab *va, int c, char **v)
{
	if (c == 1 || c == 5)
		ft_putstr("Error\n");
	if (c != 2 && c != 5)
	{
		if (va->tab_a)
			free(va->tab_a);
		if (va->tab_b)
			free(va->tab_b);
		if (v)
			free_string_array(v);
	}
	exit(0);
}

void	param_to_var(t_stab *var, char **v, int c)
{
	long long	n;
	int			i;

	i = 0;
	var->top_b = -1;
	var->tab_a = (int *)malloc(sizeof(int) * c);
	var->tab_b = (int *)malloc(sizeof(int) * c);
	if (!var->tab_a || !var->tab_b)
		quit(var, 1, v);
	while (v[i])
	{
		n = ft_atoi(v[i], var, v);
		if (n > 2147483647 || n < -2147483648)
			quit(var, 1, v);
		var->tab_a[c - i - 1] = (int)n;
		i++;
	}
	var->top_a = i - 1;
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
		exit(0);
	i = 0;
	while (tmp[i])
		i++;
	*c = i;
	return (tmp);
}

static void	handle_small_sort(t_stab *var, int c)
{
	if (c <= 4)
		sort_3nb(var, c);
	else if (c > 4)
		sort_5nb(var, c);
	quit(var, 0, 0);
}

static void	init_and_validate(t_stab *var, char ***tmp, int *c, char **v)
{
	*tmp = parc(v, *tmp, c);
	if (check_arg(*tmp) == 0)
		quit(var, 1, *tmp);
	param_to_var(var, *tmp, (*c)++);
	if (check_repeat(var->tab_a, var->top_a) == 0)
		quit(var, 1, 0);
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
		quit(&var, 0, 0);
	if (argc >= 3 && argc <= 6)
		handle_small_sort(&var, argc);
	nor(&var);
	quit(&var, 2, tmp);
}