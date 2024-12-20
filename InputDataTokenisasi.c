//Pembacaan data dengan fgets dan strtok
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
     char name[20];
     double score;
}students;
int main()
{
    int n, index=0, duplikat;
    scanf("%d",&n);
    getchar();
    students murid[n];
    char input[40], nama[20];
    double nilai;
    for (int i=0; i<n; i++){
         fgets(input, sizeof(input), stdin);
         char *tokenData = strtok(input, "$");
         duplikat=0;
         if (tokenData != NULL) strcpy(nama,tokenData);
         tokenData = strtok(NULL,"$");
         if (tokenData != NULL) nilai = atoi(tokenData);
         
         for (int j=0; j<index; j++){
              if (strcmp(murid[j].name, nama)==0){
                   murid[j].score = (murid[j].score+nilai)/2;
                   duplikat=1;
                   break;
              }
         }
         if (!duplikat && index<n){
              strcpy(murid[index].name,nama);
              murid[index].score = nilai;
              index++;
         }
    }
    printf("HASIL INPUT DATA:\n");
    for (int i=0; i<index; i++){
         printf("%s nilai: %.1lf\n",murid[i].name, murid[i].score);
    }
    return 0;
}
