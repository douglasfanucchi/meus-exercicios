/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dfanucch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 11:20:43 by dfanucch          #+#    #+#             */
/*   Updated: 2022/07/14 11:20:44 by dfanucch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putnbr_recursive(int n)
{
	char	nchar;

	if (n / 10 == 0)
	{
		nchar = (n % 10) + '0';
		write(1, &nchar, 1);
		return ;
	}
	ft_putnbr_recursive(n / 10);
	nchar = (n % 10) + '0';
	write(1, &nchar, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			nb += 2000000000;
			write(1, "2", 1);
		}
		nb *= -1;
	}
	ft_putnbr_recursive(nb);
}
