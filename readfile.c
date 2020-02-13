#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <errno.h>
#define BUFFER_SIZE 1000
int countOccurrences(char *fname, char *ward);
int main()
{
    DIR* dir;
    FILE *entry_file;
    struct dirent *in_file;
    char files[1000];
    int i;
    FILE *fp,*fp2;
    char filename[100];
    char temp[30];
    char word[50];
    char word2[50];
    char line[10];
    int wcount,wcount2;

    dir = opendir("/home/dhaval/main2");
    printf("Enter the first word");
	scanf("%s",word);

      	printf("Enter the second word");
         scanf("%s",word2);

    if(dir==NULL) {
        printf("Error! Unable to read directory");
        exit(1);
    }

    while((in_file=readdir(dir)) != NULL) {
        if (!strcmp (in_file->d_name, "."))
            continue;
        if (!strcmp (in_file->d_name, ".."))
            continue;
        printf("\nFileName= %s\n", in_file->d_name);
        entry_file = fopen(in_file->d_name, "r");
        if (entry_file != NULL) {
            fscanf(entry_file, "%s", files);
            /* whatever you want to do with files */
	wcount=countOccurrences(in_file->d_name,word);
	printf("\n'%s' is found  '%d' times ",word,wcount);

	wcount2=countOccurrences(in_file->d_name,word2);
                printf("\n'%s' is found  '%d' times ",word2,wcount2);
	if(wcount!=wcount2)
  { 
         
	 printf("\nPotential Memory Leak Found\n");
 }
}
fclose(entry_file);
}
closedir(dir);
}  
int countOccurrences(char *fname, char *ward)
{
	char str[512];
	char *pos;
	int index ,count=0;
	FILE *fp2;
if((fp2 = fopen(fname, "r")) == NULL) {
		return(-1);
	}
	
while((fgets(str,512,fp2))!=NULL)
	{
			index=0;
				while((pos=strstr(str+index,ward))!=NULL)
						{
									index=(pos-str)+1;
											count++;
												}
				}

	//Close the file if still open.
	if(fp2) {
		fclose(fp2);
	}
  return count;
}
