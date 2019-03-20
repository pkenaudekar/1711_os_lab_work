/*Author: Pratik Kenaudekar
Date Created: 15th March 2018
Date Modified: 15th March 2018
Program: WAP to delete a particular line from the file
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <utime.h>
#include <sys/wait.h>
#include <sys/times.h>

void main()
{
	FILE *file1, *file2;
    char ch;
    int delete_line, temp = 1;
    //open file in read mode
    file1 = fopen("f1.txt", "r");
    ch = getc(file1);
	while (ch != EOF)
    {
        printf("%c", ch);
        ch = getc(file1);
    }
    //rewind
    rewind(file1);
    printf("\nEnter line number of the line to be deleted:");
    scanf("%d", &delete_line);
    //open new file in write mode
    file2 = fopen("temp.txt", "w");
    ch = getc(file1);
    while (ch != EOF)
    {
        ch = getc(file1);
        if (ch == '\n')
		{
            temp++;
            //except the line to be deleted
            if (temp != delete_line)
			{
                //copy all lines in file replica.c
                putc(ch, file2);
            }
		}
    }
    fclose(file1);
    fclose(file2);
    remove("f1.txt");
    //rename the file replica.c to original name
    rename("temp.txt", "f1.txt");
}

