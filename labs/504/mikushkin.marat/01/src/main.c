#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#include "constants.h"
#include "parse_input.h"
#include "execute.h"
#include "kill_by_pid.h"
#include "handler.h"

int main() {
	signal(SIGINT, handler);

	char * arguments[MAX_USER_COMMAND_LEN];

	while (1) {
		printf("$ ");
		int number_of_arguments = parse_input(arguments);
		execute(number_of_arguments, arguments);

		for (int i = 0; i < number_of_arguments; ++i) {
			free(arguments[i]);
		}
	}

	return 0;
}
