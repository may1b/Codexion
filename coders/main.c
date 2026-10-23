/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrass <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 18:52:56 by magrass           #+#    #+#             */
/*   Updated: 2026/10/21 18:53:12 by magrass          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int	error(void)
{
	fprintf(stderr, "Error\nUsage: ./codexion number_of_coders "
		"time_to_burnout time_to_compile time_to_debug time_to_refactor "
		"number_of_compiles_required dongle_cooldown fifo|edf\n");
	return (1);
}

/*
 * Parses a non-negative integer made only of digits (optional leading '+').
 * Rejects empty strings, signs other than '+', non-digit characters
 * and values above INT_MAX.
 */
static bool	parse_uint(const char *str, size_t *out)
{
	size_t	i;
	size_t	value;

	i = 0;
	value = 0;
	if (str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (false);
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = value * 10 + (str[i] - '0');
		if (value > INT_MAX)
			return (false);
		i++;
	}
	if (str[i] != '\0')
		return (false);
	*out = value;
	return (true);
}

static bool	parse_scheduler(const char *str, t_scheduler *out)
{
	if (strcmp(str, "fifo") == 0)
		*out = FIFO;
	else if (strcmp(str, "edf") == 0)
		*out = EDF;
	else
		return (false);
	return (true);
}

static bool	handle_input(int argc, char **argv, t_args *args)
{
	if (argc != 9)
		return (false);
	if (!parse_uint(argv[1], &args->number_of_coders)
		|| !parse_uint(argv[2], &args->time_to_burnout)
		|| !parse_uint(argv[3], &args->time_to_compile)
		|| !parse_uint(argv[4], &args->time_to_debug)
		|| !parse_uint(argv[5], &args->time_to_refactor)
		|| !parse_uint(argv[6], &args->number_of_compiles_required)
		|| !parse_uint(argv[7], &args->dongle_cooldown)
		|| !parse_scheduler(argv[8], &args->scheduler))
		return (false);
	if (args->number_of_coders == 0)
		return (false);
	return (true);
}

int	main(int argc, char *argv[])
{
	t_args	args;

	if (!handle_input(argc, argv, &args))
		return (error());
	return (0);
}
