#include <stdio.h>
#include <stdlib.h>
//大写小写差32
void Cap(char sentence[]){
    sentence[0] -= 32;
    for (int i = 0; sentence[i] != '\0'; i++){
        if(sentence[i]==' '){
            sentence[i + 1] -= 32;
        }
    }
}

int main(){
    printf("TingyangXie 1230019461\n");
    char sentence[500];
    printf("Enter a sentence: ");
    fgets(sentence, 500, stdin);
    Cap(sentence);
    printf("Captilized sentence: %s", sentence);
    system("pause");
    return 0;
}
