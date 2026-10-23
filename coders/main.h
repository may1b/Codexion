//
// Created by magrass on 10/22/26.
//

#ifndef CODEXION_MAIN_H
#define CODEXION_MAIN_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

typedef size_t t_ms;

typedef enum e_scheduler {
	FIFO,
	EDF,
}	t_scheduler;

typedef struct s_args {
	size_t		number_of_coders;
	t_ms		time_to_burnout;
	t_ms		time_to_compile;
	t_ms		time_to_debug;
	t_ms		time_to_refactor;
	size_t		number_of_compiles_required;
	t_ms		dongle_cooldown;
	t_scheduler	scheduler;
}	t_args;


#endif //CODEXION_MAIN_H
