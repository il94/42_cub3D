/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilandols <ilandols@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 23:37:37 by ilyes             #+#    #+#             */
/*   Updated: 2022/11/30 17:15:06 by ilandols         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_nbr(void *arg, char flag, char flag_b, int fd)
{
	int		size;
	char	*result;

	if (flag == 'd' || flag == 'i')
		result = convert_flag((int)(long long)(arg), flag, flag_b);
	else if (flag == 'u' || flag == 'x' || flag == 'X')
		result = convert_flag((unsigned int)(long long)(arg), flag, flag_b);
	else if (flag == 'p')
	{
		if (arg == NULL)
			result = ft_strdup("(nil)");
		else
			result = p_convert_flag((unsigned long long)(arg), flag_b);
	}
	size = ft_strlen(result);
	write(fd, result, size);
	free(result);
	return (size);
}

int	print_ascii(void *arg, char flag, char flag_b, int fd)
{
	int	size;

	flag_b = flag_b;
	if (flag == 'c')
	{
		size = 1;
		write(fd, &arg, 1);
	}
	else if (arg == NULL)
	{
		size = 6;
		write(fd, "(null)", 6);
	}
	else
	{
		size = ft_strlen(arg);
		write(fd, arg, ft_strlen(arg));
	}
	return (size);
}

int	print_flag(va_list args, char flag, char flag_b, int fd)
{
	if (flag == '%')
	{
		write(fd, &flag, 1);
		return (0);
	}
	else if (flag == 'c' || flag == 's')
		return (print_ascii(va_arg(args, void *), flag, flag_b, fd) - 1);
	else
		return (print_nbr(va_arg(args, void *), flag, flag_b, fd) - 1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;
	char	flag;
	char	flag_b;

	va_start(args, str);
	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (get_flag(str[i], str[i + 1], str[i + 2]))
		{
			flag = get_flag(str[i], str[i + 1], str[i + 2]);
			flag_b = get_second_flag(str[i + 1]);
			size += print_flag(args, flag, flag_b, 1);
			i += 2;
			if (flag_b != 0)
				i += 1;
		}
		else
			write(1, &str[i++], 1);
		size++;
	}
	return (size);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	va_list	args;
	int		i;
	int		size;
	char	flag;
	char	flag_b;

	va_start(args, str);
	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		if (get_flag(str[i], str[i + 1], str[i + 2]))
		{
			flag = get_flag(str[i], str[i + 1], str[i + 2]);
			flag_b = get_second_flag(str[i + 1]);
			size += print_flag(args, flag, flag_b, fd);
			i += 2;
			if (flag_b != 0)
				i += 1;
		}
		else
			write(fd, &str[i++], 1);
		size++;
	}
	return (size);
}
