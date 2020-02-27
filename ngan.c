#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    char input[1000];
    fgets(input, 1000, stdin);
    int columnw;
    scanf("%d", &columnw);

    //Alignment
    char align[6];
    scanf("%s", align);

    //printf("Autocorrect");
    char ans1[4];
    scanf("%s", ans1);

    char ans[]="yes";
    if(strcmp(ans1, ans)==0){
      for(int i=0; i<strlen(input); i++){
        if(input[i]=='3') input[i]='e';
        if(input[i]=='1') input[i]='l';
        if(input[i]=='0') input[i]='o';
        if(input[i]=='7') input[i]='t';
        if(input[0]>=97&&input[0]<=122) input[0]=input[0]-32;
      }
      //Capitalize 1st word
      if(input[0]>=97&&input[0]<=122) input[0]=input[0]-32;

    //Captialize after period and space

      for(int i=0; i<strlen(input); i++){
        if(input[i]=='.' && input[i+1]==' '){
          if(isalpha(input[i+2])) input[i+2]=input[i+2]-32;
        }
      }

      //End output with period
      char end='.';
      if(!(input[strlen(input)-1]=='.')){
        strncat(input, &end, 1);
        columnw=columnw+1;
      }
    }
    //Output
    if(columnw>=strlen(input)){
      for(int i=0; i<columnw; i++){
        printf("-");
      }
        printf("\n");
      }
    /*else {
        printf("Invalid column width");
        return 1;
    }*/

    if(strcmp(align, "left")==0){
        printf("%s", input);
    }
    if(strcmp(align, "right")==0){

        int c=columnw-strlen(input)+1;
        for(int i=0; i<c; i++){
          printf(" ");
        }
        printf("%s", input);
    }
    if(strcmp(align, "center")==0){
        if(columnw%2==0){
            int a=((columnw/2)-(strlen(input)-1)/2);
            for(int i=0; i<a; i++){
                printf(" ");
            }
            printf("%s", input);
        }
        else{
            int b=((columnw/2)-(strlen(input)-1)/2)+1;
            for(int i=0; i<b; i++){
                printf(" ");
            }
            printf("%s", input);
        }
    }

    //Word count
    int spacen=1;
    for(int i=0; i<strlen(input); i++){
        if(input[i]==' ') {
            if(i!=strlen(input-1)) spacen++;
        }
    }
    printf("\n");
    printf("Words: %d\n", spacen);

    //Avg word length
    double avg;
    int words = 0;
    for(int i=0; i<strlen(input)-1; i++){
        if((input[i]>=65&&input[i]<=90)||(input[i]>=97&&input[i]<=122))
        words++;
    }
    if(spacen==1) avg = (double)words;
    else{
        avg=(double)words/spacen;
        }
    printf("Avg word length: %lf\n", avg);

    return 0;
}
