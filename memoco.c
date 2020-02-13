#include<stdio.h>
#include<stdlib.h>
int *ivar;
char *cvar;
float *fvar;



void allocate(){
	ivar=(int*)malloc(1*sizeof(int));
	cvar=(char*)malloc(1*sizeof(char));
	fvar=(float*)malloc(1*sizeof(float));
}
void deallocate()
{
	free(ivar);
	free(cvar);
        free(fvar);
}

int main()
{
  allocate();
	printf("Enter any Integer Value");
	scanf("%d",ivar);
 
	printf("\nEnter any character");
	scanf("%c",cvar);

	printf("\nEnter any float number");
	scanf("%f",fvar);

	printf("Values are: %d,%c,%.2f",*ivar,*cvar,*fvar);
	deallocate();
	
	return 0;
}
