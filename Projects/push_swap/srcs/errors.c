/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 12:09:32 by alopes            #+#    #+#             */
/*   Updated: 2021/06/09 12:36:46 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_isdigit (char *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if(str[i] < '0' || str [i] >'9')
			return (0);
		i++;
	}
	return(1);
}

/*int		*check_error(char *argv, t_stack_overflow)
{
	int num;

}*/
