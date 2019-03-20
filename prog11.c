/*Author: Pratik Kenaudekar
Date Created: 4th October 2017
Date Modified: 4th October 2017
Program: WAP to count the number of vowels.
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <unistd.h>
#include<string.h>

void main(int argc, char *argv[])
{
	int i=0,j,vowels=0,lineno;
	ssize_t bytes_read;
	char buff[1000];
	if(argc !=2)
	{
		write(1,"\nInvalid no of arguments\nusage: ./prog11.exe filename1",69);
		exit(-1);
	}
	int file1 = open(argv[1], O_RDONLY);
	if (file1 < 0) 
	{
		perror("error");
		exit(1);
	}
	bytes_read = read(file1, buff, sizeof(buff)); 
	for (i=0; i<bytes_read; i++)
	{
		if (buff[i] == 'a'||buff[i] == 'e'||buff[i] == 'i'||buff[i] == 'o'||buff[i] == 'u')
		{
			++vowels;
		}
	}
	printf("\nThe number of space in the file are:%d",vowels);
	exit(0);
}
