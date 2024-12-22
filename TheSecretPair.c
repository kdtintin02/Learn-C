//The secret Pair
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    //proses input data
    int n;
    scanf("%d",&n); getchar();
    char input[256];
    scanf("%[^\n]",input);
    //proses memasukkan data input ke dalam array
    int arr[n];
    char *token = strtok(input," ");
    if (token!=NULL) arr[0]=atoi(token);
    int index=1;
    while (index<n){
        token = strtok(NULL," ");
        if (token!=NULL) arr[index]=atoi(token);
        index++;
    }
    //proses menghitung Pair
    index=0;
    int count=0;
    while (index<n-1){
        if ((arr[index]+arr[index+1])%2==1){
            count++;
            index+=2;
        }else{
            index++;
        }
    }
    printf("%d",count);
    return 0;
}
