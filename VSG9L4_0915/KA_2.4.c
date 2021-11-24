#include <stdio.h>
#include <stdlib.h>

struct  Auto {
        char rendszam[6];
        char tipus[20];
        double ar;
    };

int main () {
    int poz = beol();
    felvisz();
    olvas(poz);
    return 0;
    }

void felvisz(){
    struct Auto autok[3];
    FILE *fdata;
    int i = 0;


    for (i=0; i< 3; i++) {
        printf("rsz:");
        scanf("%s",&autok[i].rendszam);
        printf("tipus:");
        scanf("%s",&autok[i].tipus);
        printf("ar:");
        scanf("%d",&autok[i].ar);

    }

    fdata = fopen("Autok.dat", "wb");

    for (i=0; i< 3; i++) {
        fwrite(&(autok[i]), sizeof(struct Auto),1, fdata);
    }

    fclose(fdata);

}

int beol(int *szam){
int ok;
do {
        ok = 1;
        if (scanf("%d", &szam)!=1 || 1>szam || szam > 3) {
        printf("Rossz input\n");
        ok = 0;
        fflush(stdin);
        }
    }while (!ok);
return szam;
 }

void olvas(int poz){

    FILE *fdata;

    fdata = fopen("Autok.dat", "rb");
    struct Auto aurek;

    if (fdata == NULL) {
        printf ("file hiba\n");
        return;
    }

    fseek(fdata, (poz-1)* sizeof(struct Auto),0 );
    fread(&aurek, sizeof(struct Auto),1, fdata);

    printf ("rsz: %s\n", aurek.rendszam);
    printf ("tip: %s\n", aurek.tipus);
    printf ("ar: %d\n", aurek.ar);

    fclose(fdata);

}
