/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 11:31:21 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/05 14:08:47 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		length;
}

int main(void)
{
    char str[] = "Yeah,This-is,notzcool";
    char charset [] = ",-z";
	char** blocks;

    blocks = ft_split(str, charset);
}
