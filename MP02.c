//Central de Comunicacoes Alienigenas

#include <stdio.h>

//Funcao que retorna o tamanho da string
int tamanhoString(char *s){
    int tamanho = 0;
    int i = 0;
    
    while(*(s + i) != '\0'){
        tamanho++;
        i++;
    }

    return tamanho;
}

//Funcao que copia uma string para outra usando ponteiros
void copiarString(char *atual, char *destino){
    int i = 0;

    while(*(atual + i) != '\0'){
        *(destino + i) = *(atual + i);
        i++;
    }

    *(destino + i) = '\0';
}

void inverter(char *s){
    int i = 0;
    int tamanho = tamanhoString(s);
    char invertida[10001];
    
    int x = tamanho - 1;

    for(i = 0; i < tamanho; i++){
        invertida[x] = *(s + i);
        x--;
    }
    invertida[tamanho] = '\0';

    copiarString(invertida, s);
}

void deslocar(char *s, int n){
    int i = 0, j = 0;
    int tamanho = 0;

    tamanho = tamanhoString(s);

    //Desloca para positivos
    if(n > 0){
        for(i = 0; i < tamanho; i++){
            //Se for letra
            if((*(s + i) >= 'A' && *(s + i) <= 'Z') || (*(s + i) >= 'a' && *(s + i) <= 'z')){
                for(j = 1; j <= n; j++){
                    if(*(s + i) == 90 || *(s + i) == 122){
                        *(s + i) = *(s + i) - 25;
                        continue;
                    }

                    *(s + i) = *(s + i) + 1;
                }
            //Se for numero
            }else if(*(s + i) >= '0' && *(s + i) <= '9'){
                for(j = 1; j <= n; j++){
                    if(*(s + i) == 57){
                        *(s + i) = *(s + i) - 9;
                        continue;
                    }

                    *(s + i) = *(s + i) + 1;
                }
            }
        }
    //Desloca para negativos
    }else{
        int positivo = -n; //Transforma n em positivo para o for
        for(i = 0; i < tamanho; i++){
            //Se for letra
            if((*(s + i) >= 'A' && *(s + i) <= 'Z') || (*(s + i) >= 'a' && *(s + i) <= 'z')){
                for(j = 1; j <= positivo; j++){
                    if(*(s + i) == 65 || *(s + i) == 97){
                        *(s + i) = *(s + i) + 25;
                        continue;
                    }

                    *(s + i) = *(s + i) - 1;
                }
            //Se for numero
            }else if(*(s + i) >= '0' && *(s + i) <= '9'){
                for(j = 1; j <= positivo; j++){
                    if(*(s + i) == 48){
                        *(s + i) = *(s + i) + 9;
                        continue;
                    }

                    *(s + i) = *(s + i) - 1;
                }
            }
        }
    }
}

void trocarParesImpares(char *s){
    int tamanho = 0;
    int i = 0;
    char temp;

    tamanho = tamanhoString(s);

    for(i = 0; i < tamanho; i = i + 2){
        if(i < tamanho - 1){
            temp = *(s + i);
            *(s + i) = *(s + i + 1);
            *(s + i + 1) = temp;
        }
    }
}

void inverterCaixa(char *s){
    int i = 0;
    int tamanho = 0;

    tamanho = tamanhoString(s);

    for(i = 0; i < tamanho; i++){
            if(*(s + i) >= 'A' && *(s + i) <= 'Z'){
                *(s + i) = *(s + i) + 32;
            }else if(*(s + i) >= 'a' && *(s + i) <= 'z'){
                *(s + i) = *(s + i) - 32;
            }
    }
}

void rotacionar(char *s, int n){
    int i = 0;
    int tamanho = 0;
    int diferenca = 0;
    char copia[10001];

    //Cria uma copia da string atual para usar durante a rotacao
    copiarString(s, copia);

    tamanho = tamanhoString(s);

    //Se a rotacao for maior que o tamanho, transforma n para valor menor q a string
    if(n > tamanho){
        n = n % tamanho;
    }

    //Caso n for negativo
    if(n < 0){
        n = -n;

        if(n > tamanho){
            n = n % tamanho;
        }
        
        n = tamanho - n;
    }

    for(i = 0; i < tamanho; i ++){
        //Se o elemento ultrapassar a extremidade da string
        if((i + n) >= tamanho){
            diferenca = tamanho - i - n;

            if(diferenca < 0){
                diferenca = -diferenca;
            }

            *(s + diferenca) = copia[i];
        
        //Caso nao ultrapassar a extremidade
        }else{
            *(s + i + n) = copia[i];
        }
    }
}

void trocarMetades(char *s){
    int i = 0, j = 0;
    int tamanho = 0;
    char atual[10001];

    tamanho = tamanhoString(s);
    copiarString(s, atual);

    i = tamanho / 2 -1;
    //Se o tamanho for impar
    if(tamanho % 2 != 0){
        //Primeira metade
        j = tamanho - 1;

        for(i = tamanho / 2 -1; i >= 0; i--){
            *(s + i) = atual[j];
            j--;
        }
        
        //Segunda metade
        j = 0;

        for(i = tamanho / 2 + 1; i < tamanho; i++){
            *(s + i) = atual[j];
            j++;
        }
    //Se o tamanho for par
    }else{
        //Primeira metade
        j = tamanho - 1;

        for(i = tamanho / 2 - 1; i >= 0; i--){
            *(s + i) = atual[j];
            j--;
        }

        //Segunda metade
        j = 0;

        for(i = tamanho / 2; i < tamanho; i++){
            *(s + i) = atual[j];
            j++;
        }
    }
}

int main(){
    char string[10001];
    int operacao = -1;
    int n = 0;
    int i = 0;

    scanf(" %[^\n]", string);
    char *s = string;

    int tamanho = tamanhoString(s);

    //Teste q imprime tamanho da string
    //printf("%d\n", tamanho); 

    while(operacao != 0){

        scanf("%d", &operacao);
        
        if(operacao == 0){
            printf("%s\n", string);
            return 0;
        }

        if(operacao == 1){
            inverter(s);

        }else if(operacao == 2){
            scanf("%d", &n);
            deslocar(s, n);

        }else if(operacao == 3){
            trocarParesImpares(s);

        }else if(operacao == 4){
            inverterCaixa(s);

        }else if(operacao == 5){
            scanf("%d", &n);
            rotacionar(s, n);

        }else if(operacao == 6){
            trocarMetades(s);

        }
    }

    return 0;
}