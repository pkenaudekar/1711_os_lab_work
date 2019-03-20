/*Author: Pratik Kenaudekar
Date Created: 4th October 2017
Date Modified: 4th October 2017
Program: Write a program to print first 10 characters of a given file (user inputs the file name) to the standard output.

*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <malloc.h>
#include <fcntl.h>
#include <unistd.h>

void main(int argc, char *argv[])
{
	char buff[10];
	if(argc != 2)
	{
		write(1,"\nInvalid no of arguments",30);
		write(1,"\nusage: ./prog2.exe filename",30);
		exit(-1);
	}
	int file1 = open(argv[1], O_RDONLY);
    if (file1 < 0) 
    {
        perror("error");
        exit(1);
	}
	int file2 = open("f2.txt", O_WRONLY | O_CREAT);
	read(file1, buff, 10);
	write(file2, buff, 10);
	close(file2);
	close(file1);
	
}
