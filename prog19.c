/*Author: Pratik Kenaudekar
Date Created: 17th January 2018
Date Modified: 17th January 2018
Program: WAP to display the size of a given file.

*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include<string.h>

void main(int argc, char *argv[])
{
	int i;
	struct stat sb;
    const char * file_name;
    file_name = argv[1];
    if (stat (file_name, & sb) != 0) 
	{
		fprintf (stderr, "'stat' failed for '%s': %s.\n", file_name, strerror (errno));
		exit (EXIT_FAILURE);
	}
    printf ("%s has %d bytes.\n", argv[1], sb.st_size);
    exit(0);
}
