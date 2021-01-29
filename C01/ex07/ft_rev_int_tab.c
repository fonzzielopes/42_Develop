/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 12:40:15 by alopes            #+#    #+#             */
/*   Updated: 2021/01/14 11:14:11 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp;
	int count;

	count = 0;
	while (count != size / 2)
	{
		temp = tab[count];
		tab[count] = tab[size - (count + 1)];
		tab[size - (count + 1)] = temp;
		count++;
	}
}
