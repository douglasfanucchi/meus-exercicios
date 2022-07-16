/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 04:44:45 by dfanucch          #+#    #+#             */
/*   Updated: 2022/07/15 04:44:45 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

#define ARRSIZE 9

int	g_total_comb;
int	g_comb_printed;

void	ft_putnbr(int x);

void	ft_print_comma(void)
{
	if (g_comb_printed != g_total_comb)
		write(1, ", ", 2);
}

void	ft_print_combn_recursive(int n, int i, char *prevn)
{
	char	number;
	int		limit;
	int		j;

	limit = 10 - n;
	while (i <= limit)
	{
		number = i + '0';
		if (n > 1)
		{
			prevn[ARRSIZE - n] = i + '0';
			ft_print_combn_recursive(n - 1, i + 1, prevn);
		}
		else
		{
			j = 0;
			while (j < ARRSIZE)
				write(1, &prevn[j++], 1);
			write(1, &number, 1);
			g_comb_printed++;
			ft_print_comma();
		}
		i++;
	}
}

int	factory(int n)
{
	if (n == 1 || n == 0)
		return (1);
	return (n * factory(n - 1));
}

int	total_comb(int p)
{
	return (factory(10) / (factory(p) * factory(10 - p)));
}

void	ft_print_combn(int n)
{
	char	prevn[ARRSIZE];

	if (n < 1 || n > 9)
		return ;
	g_comb_printed = 0;
	g_total_comb = total_comb(n);
	ft_print_combn_recursive(n, 0, prevn);
}
