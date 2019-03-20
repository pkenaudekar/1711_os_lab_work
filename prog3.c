/*Author: Pratik Kenaudekar
Date Created: 4th October 2017
Date Modified: 4th October 2017
Program: Write a program to copy first 10 characters of f1.txt into f2.txt
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include <malloc.h>
#include <fcntl.h>
#include <unistd.h>

void main()
{
	char buff[10];
	int file1 = open("f1.txt", O_RDONLY);
    if (file1 < 0) 
    {
        perror("Error");
        exit(1);
    }
	int file2 = open("f2.txt", O_WRONLY | O_CREAT);
	read(file1, buff, 10);
	write(file2, buff, 10);
	close(file1);
    close(file2);
}
