/*Author: Pratik Kenaudekar
Date Created: 4th October 2017
Date Modified: 4th October 2017
Program: Write a C program that takes 2 file names as arguments and 2 possible options
Split or concat
Eg 
filcon [s/c] f1 f2  
-s splits the file f1 
-c  concats f1 and f2 

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
	int i=0,j,lines=1,lineno;
	ssize_t bytes_read;
	char buff[1000],trans1[1000],trans2[1000];
	if(argc < 3 || argc > 4)
	{
		write(1,"\nInvalid no of arguments\nusage: ./prog8.exe [s/c] filename1 filename2",69);
		exit(-1);
	}
	if(strcmp(argv[1],"s")==0)
	{
		int file1 = open(argv[2], O_RDONLY);
		if (file1 < 0) 
		{
			perror("error");
			exit(1);
		}
		int file2 = open(argv[3], O_WRONLY | O_CREAT, 0644);
		int file3 = open("temp.txt", O_WRONLY | O_CREAT | O_TRUNC);
		bytes_read = read(file1, buff, sizeof(buff)); 
		for (i=0; i<bytes_read; i++)
		{
			if (buff[i] == '\n')
			{
				++lines;
			}
		}
		lineno=lines/2;
		lines=0;
		i=j=0;
		
		while(i<strlen(buff))
		{
			if (buff[i] == '\n')
			{
				lines++;
			}
			if(lines<lineno)
			{
				trans1[i]=buff[i];
			}	
			else
			{
				trans2[j]=buff[i];
				j++;
			}
			i++;
		}
		write(file2, trans2,strlen(trans2));	
		close(file2);
		write(file3, trans1,strlen(trans1));	
		close(file3);
		remove(argv[2]);
		rename("temp.txt", argv[2]);
		write(1, "\nFile split successfully",24);		
		exit(0);
	}
	else if(strcmp(argv[1],"c")==0)
	{
		int file1 = open(argv[2], O_RDWR | O_APPEND);
		if (file1 < 0) 
		{
			perror("error");
			exit(1);
		}
		int file2 = open(argv[3], O_RDONLY);
		if (file2 < 0) 
		{
			perror("error");
			exit(1);
		}
		bytes_read = read(file2, buff, sizeof(buff)); 
		write(file1, "\r\n", 2);
		write(file1, buff,bytes_read);	
		close(file2);
		close(file1);
		remove(argv[3]);
		write(1, "\nFile combined successfully",27);		
		exit(0);
	}
	else
	{
		write(1,"\nInvalid input\nusage: ./prog8.exe [s/c] filename1 filename2",60);
		exit(-1);
	}
}
