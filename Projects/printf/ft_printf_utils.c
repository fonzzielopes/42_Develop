/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopes <alopes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:24:06 by alopes            #+#    #+#             */
/*   Updated: 2021/03/26 16:35:15 by alopes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags flag;

	flag.precision = 0;
	flag.dot = 0;
	flag.width = 0;
	flag.minus = 0;
	flag.zero = 0;
	flag.type = 0;
	flag.hash = 0;
	flag.space = 0;
	flag.plus = 0;
	return (flag);
}

int		check_var(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int		get_width(const char **format, va_list args)
{
	int width;

	width = 0;
	if (**format == '*')
		width = va_arg(args, int); //caso encontre *, vai buscar o valor directo aos args
	if (ft_isdigit(**format)) // caso seja um digit
	{
		width = ft_atoi(*format); //precisa de passar o digit para int caso contrario vai buscar o valor ASCII
		while (ft_isdigit(**format)) //tem de percorrer a quantidade de digitos
			(*format)++;
		(*format)--; // apos leitura tem voltar a ler as flags ou conteudo, pois pode ter precision, etc
	}
	return (width);
}

int		get_precision(const char **format, va_list args)
{
	int		precision;

	precision = 0;
	if (*(*format + 1) == '*') //caso o valor a seguir ao . seja *
	{
		(*format)++; // passamos ao valor em si
		precision = va_arg(args, int); // vai buscar o valor aos args
	}
	if (ft_isdigit(*(*format + 1))) // o valor caso seja um digit
	{
		(*format)++; // passamos ao valor em si
		precision = ft_atoi(*format); //faz a conversao
		while (ft_isdigit(*(*format + 1))) // enquanto for digit, percorre a quantidade
			(*format)++;
	} // nao precisa de voltar atras pois apos precision so tem a flag e char para ler
	return (precision);
}

/*
Diferença do width para o precision é que o valor para o width é sempre definido ou no format
ou nos argumentos, portanto vamos sempre buscar la o valor.
Enquanto no precision o valor será sempre definido apos o '.'

Nota que mesmo que o width seja menor que o arg, o arg toma prioridade e tem de ser impresso na totalidade.
Mesma coisa com o precision, toma prioridade de tamanho perante a width.
*/
