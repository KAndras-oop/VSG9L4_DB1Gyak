#include <stdio.h>
#include <stdlib.h>

int main()
{
    char fnev1[50], fnev2[50];
    beker(fnev1, fnev2);
    masolas(fnev1, fnev2);
    return 0;
}

void beker(char *fnev1, char *fnev2){
    printf("Filenev: ");
    scanf("%s", fnev1);
    printf("Filenev: ");
    scanf("%s", fnev2);
}

void masolas(char *fnev1, char *fnev2){

    FILE *fp1, *fp2;
    char ch;
    int pos;
    if ((fp1 = fopen(fnev1, "r")) == NULL)
{
       printf("\nNem lehet megnyitni a fajlt.");
       return;
}
    else
{
        printf("\nFajl megnyitva masolasra...\n ");
}
    fp2 = fopen(fnev2, "w");
    fseek(fp1, 0L, SEEK_END);
    pos = ftell(fp1);
    fseek(fp1, 0L, SEEK_SET);
    while (pos--)
{
      ch = fgetc(fp1);
      fputc(ch, fp2);
}
    fclose(fp1);
    fclose(fp2);
}
