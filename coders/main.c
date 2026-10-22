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

#include <stdio.h>
#include <stdint.h>

typedef t_ms size_t;

typedef enum e_scheduler {
	FIFO,
	EDF,
}	t_scheduler;

typedef struct s_args {
	size_t		number_of_coders;
	t_ms		time_to_burnout;
	t_ms		time_to_compile;
	t_ms		time_to_debug;
	size_t		number_of_compiles_required;
	t_ms		dongle_cooldown;
	t_scheduler	scheduler;
}	t_args;


static int error()
{
	printf("ERROR");
	return 1;
}

int main(int arc, char* argv[])
{
	t_args	args;

	if (argc != 9)
		return error();
	args.number_of_coders = atoi(argv[1]);
	args.time_to_burnout = atoi(argv[2]);
	args.time_to_compile = atoi(argv[3]);

}
