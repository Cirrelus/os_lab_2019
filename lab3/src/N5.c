#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>

#include <getopt.h>

int main( void ) {
	char *argv[3] = {"5", "10", "2"};

	pid_t pid = fork();

	if ( pid == 0 ) {
		execlp( "parallel_min_max", *argv , NULL);
	}

	/* Put the parent to sleep for 2 seconds--let the child finished executing */
	sleep(2);

	printf( "Finished executing the parent process\n"
	        " - the child won't get here--you will only see this once\n" );

	return 0;
}