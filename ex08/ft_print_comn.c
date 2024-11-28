/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*                                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourusername <yourusername@student.42.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:00:00 by yourusername     #+#    #+#              */
/*   Updated: 2024/05/27 10:00:00 by yourusername    ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
}

void	ft_print_comb_recursive(int *tab, int n, int index, int start)
{
	int	i;

	i = start;
	if (index == n)
	{
		ft_print_tab(tab, n);
		if (tab[0] < 10 - n)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
	while (i <= 9)
	{
		tab[index] = i;
		ft_print_comb_recursive(tab, n, index + 1, i + 1);
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	tab[10];
	int	index;
	int	start;
	int	i;

	i = n - 1;
	index = 0;
	start = 0;
	if (n < 2 || n > 9)
		return ;
	tab[i] = '\0';
	ft_print_comb_recursive(tab, n, index, start);
}

int	main(void)
{
	ft_print_combn(5);
}
