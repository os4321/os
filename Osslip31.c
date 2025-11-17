

#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
 struct stat s;
 if (argc != 2) {
 printf("Usage : %s <filename>\n", argv[0]);
 return 0;
 }
 if (stat(argv[1], &s) == -1) {
 printf("File not found\n");
 return 0;
 }
 printf("Inode Number : %ld\n", s.st_ino);
 if (S_ISREG(s.st_mode))
 printf("Type : Regular File\n");
 else if (S_ISDIR(s.st_mode))
 printf("Type : Directory\n");
 else if (S_ISCHR(s.st_mode))
 printf("Type : Character Device\n");
 else if (S_ISBLK(s.st_mode))
 printf("Type : Block Device\n");
 //else if (S_ISLNK(s.st_mode))
 //printf("Type : Symbolic Link\n");
 else
 
 printf("Type : Other\n");
 return 0;
}
