
#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
 int i;
 struct stat s;
 if (argc < 2) {
 printf("No files given\n");
 return 0;
 }
 for (i = 1; i < argc; i++) {
 if (stat(argv[i], &s) == 0) {
 printf("File : %s\n", argv[i]);
 printf("Inode : %ld\n\n", s.st_ino);
 } else {
 printf("Cannot open %s\n\n", argv[i]);
 }
 }
 return 0;
}
