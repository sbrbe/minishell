/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omfelk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:56:27 by omfelk            #+#    #+#             */
/*   Updated: 2024/03/26 15:56:29 by omfelk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

long long int	f_atoi(const char *nptr)
{
	long long int	retur;
	long long int	i;
	long long int	signe;

	retur = 0;
	i = 0;
	signe = 1;
	if (!nptr)
		return (0);
	while ((nptr[i] >= 9 && nptr[i] <= 13)
		|| (nptr[i] == 32 && nptr[i] != '\0'))
		i++;
	if (nptr[i] == '-' || (nptr[i] == '+' && nptr[i] != '\0'))
	{
		if (nptr[i] == '-')
			signe = signe * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		retur = retur * 10 + (nptr[i] - '0');
		i++;
	}
	retur = retur * signe;
	return (retur);
}

size_t	f(const char *s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[i + j] != '\0')
	{
		if (s[i + j] == ' ')
			j++;
		else
			i++;
	}
	return (i);
}

void	ft_count(char **str)
{
	printf("exit\n");
	if (str[0] && str[1] && str[1][0] != 0)
	{
		if (str[0] && str[1] && str[1][0] != 0)
		{
			printf("minishelle: exit: too many arguments\n");
			fre(str);
			exit (1);
		}
	}
}

void	ft_numeric(char **argv, int *i, long long int *j)
{
	if ((argv[0][*i] < '0' || argv[0][*i] > '9'))
	{
		if ((argv[0][*i] == '+' || argv[0][*i] == '-'))
		{
			(*j)++;
			(*i)++;
		}
		if (*j >= 2 || ((argv[0][*i] < '0' || argv[0][*i] > '9')))
		{
			printf("minishelle: exit: %s: numeric argument required\n", argv[0]);
			fre(argv);
			exit (2);
		}
	}
}

void	ft_exit(t_data *env, char **str_reel)
{
	long long int	j;
	int				i;
	char			*t;
	char			**argv;

	t = dollars_parsing_bis(no_space(str_reel[env->i]), env);
	argv = ft_calloc(sizeof(char *), 3);
	argv = ft_cd_temp(t, argv, 0);
	fre(str_reel);
	freeverithing(env);
	ft_count(argv);
	i = -1;
	j = 0;
	while (argv[0] && argv[0][++i])
		ft_numeric(argv, &i, &j);
	j = f_atoi(argv[0]);
	if (f(argv[0]) > 20 || j > 9223372036854775807 || j < -9223372036854775807)
	{
		printf("minishelle: exit: %s: numeric argument required\n", argv[0]);
		j = 2;
	}
	if (argv[0] && argv[0][0] == '\0')
		j = 0;
	fre(argv);
	exit (j);
}
