/*Author: Pratik Kenaudekar
Date Created: 4th October 2017
Date Modified: 4th October 2017
Program: Write a program that prints the 15th character of a file.
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
	int i=0;
	char buff[50],ch[1];
	if(argc != 2)
	{
		write(1,"\nInvalid no of arguments\nusage: ./prog3.exe filename",52);
		exit(-1);
	}
	int file1 = open(argv[1], O_RDONLY);
    if (file1 < 0) 
    {
        perror("error");
        exit(1);
	}
	read(file1, buff, 50);
	while(i<strlen(buff))
	{
		if(i==14)
		{
			ch[0]=buff[i];
			write(1,"The 15th character is:",22);
			write(1, ch,1);
		}
		i++;
	}
	close(file1);
	
}
