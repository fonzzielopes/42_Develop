/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes- <alopes-@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 20:22:27 by alopes-           #+#    #+#             */
/*   Updated: 2021/02/10 16:22:59 by alopes-          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int i;
	int j;
	int size_backup;

	i = 0;
	j = 0;
	size_backup = size;
	while (size > 1 && (dest[i] = src[i]) != 0)
	{
		dest[i] = src[i];
		--size;
		++i;
	}
	if (size_backup != 0)
	{
		dest[i] = '\0';
		while (src[j])
			++j;
	}
	return (j);
}
