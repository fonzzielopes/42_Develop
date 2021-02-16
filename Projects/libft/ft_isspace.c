/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 14:41:38 by alopes            #+#    #+#             */
/*   Updated: 2021/02/16 14:43:44 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_isspace(int c)
{
    return (c == '\f' || c == '\n' || c == '\r' \
    || c == '\t' || c == '\v' || c == ' ');
}