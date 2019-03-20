/*Author: Pratik Kenaudekar
Date Created: 4th October 2017
Date Modified: 4th October 2017
Program: Write a program to read a file (an argument to your program) and copy the content to new file having 10 characters (ie a newline has to be added after the 10
 character)

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
	char buff[100],ch[1];
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
	read(file1, buff, 100);
	int file2 = open("f2.txt", O_WRONLY | O_CREAT);
	printf("%d",strlen(buff));
	while(i<(strlen(buff)-2))
	{
		if(i%10==0 && i!=0)
		{			
			write(file2, "\r\n",2);
		}
		ch[0]=buff[i];
		write(file2, ch,1);
		i++;
	}
	close(file1);
	close(file2);
	
}
