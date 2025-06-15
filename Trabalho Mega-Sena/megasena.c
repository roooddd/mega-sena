#include "megasena.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

//pede quantas dezenas serão jogadas
int pedir_dezenas() {
    printf("\n=============================================================\n                      M E G A - S E N A                      \n=============================================================\n");
    
    int dezenas;
    
    do {
        printf("\n--> Digite quantas dezenas deseja apostar (6 a 15): ");
        scanf("%d", &dezenas);
        
        if (dezenas < 6 || dezenas > 15) {
            printf("\nERRO! O numero de dezenas deve ser de 6 a 15. Tente novamente.\n");
        }

    } while (dezenas < 6 || dezenas > 15);

    return dezenas;
}

//pede a quantidade de apostas manuais
int qtd_manuais() {
    int manuais;
    
    do{ 
        printf("\n--> Digite quantas apostas manuais deseja fazer (0 a 3): ");
        scanf("%d", &manuais);

        if (manuais < 0 || manuais > 3){
            printf("\nERRO! A quantidade de apostas manuais deve ser de 0 a 3. Tente novamente.\n");
        }

    } while (manuais < 0 || manuais > 3);

    return manuais;
}

//pede a quantidade de surpresinhas
int qtd_surpresinhas() {
    int surpresinhas;
    
    do{ 
        printf("\n--> Digite a quantidade de surpresinhas que deseja apostar (0 a 7): ");
        scanf("%d", &surpresinhas);

        if (surpresinhas < 0 || surpresinhas > 7){
            printf("\nERRO! A quantidade de surpresinhas deve ser de 0 a 7. Tente novamente.\n");
        }

    } while (surpresinhas < 0 || surpresinhas > 7);

    return surpresinhas;
}

//solicita as apostas manuais
void solicitar_apostas_manuais(int quantas_apostas, int quantas_dezenas, int matriz_de_apostas[quantas_apostas][quantas_dezenas]) {
    if (quantas_apostas == 0) {
        return;
    }

    int i, contador = 0;
    
    while (contador < quantas_apostas) {
        escanear_dezenas(quantas_dezenas, matriz_de_apostas[contador], contador + 1);
        contador++;
    }
    
    return;
}

//usuario digita as dezenas e verificação das dezenas digitadas
void escanear_dezenas(int quantas_dezenas, int lista_dezenas[quantas_dezenas], int n_aposta) {
    printf("\n--> Digite a Aposta %d (%d dezenas de 01 a 60): ", n_aposta, quantas_dezenas);
    
    int dezenas[quantas_dezenas];
    
    for (int i = 0; i < quantas_dezenas; i++) {
        scanf("%d", &dezenas[i]);
    }

    //verifica as dezenas repetidas
    if (tem_numero_repetido(dezenas, quantas_dezenas)) {
        printf("\nERRO! A aposta nao deve conter numeros repetidos. Tente novamente.\n");
        escanear_dezenas(quantas_dezenas, lista_dezenas, n_aposta);
        return;
    }
    
    //verifica o erro de dezenas entre 01 e 60
    if (!valida_dezenas(dezenas, quantas_dezenas)) {
        printf("\nERRO! A aposta so pode ter numeros entre 01 e 60. Tente novamente.\n");
        escanear_dezenas(quantas_dezenas, lista_dezenas, n_aposta);
        return;
    }
    
    for (int i = 0; i < quantas_dezenas; i++) {
        lista_dezenas[i] = dezenas[i];
    }

    return;
}      

//confere se tem números repetidos na aposta
bool tem_numero_repetido(int dezenas[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (dezenas[i] == dezenas[j]) {
                return true;
            }
        }
    }

    return false;
}

//confere se as dezenas estão entre 01 e 60
bool valida_dezenas(int dezenas[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        if (dezenas[i] < 1 || dezenas[i] > 60) {
            return false;
        }
    }

    return true;
}

//gera as surpresinhas aleatórias
void gerador_de_surpresinhas(int quantas_surpresinhas, int quantas_dezenas, int surpresinhas_geradas[quantas_surpresinhas][quantas_dezenas]) {
    for (int i = 0; i < quantas_surpresinhas; i++) {
        bool surpresinhas_repetidas[61] = {false};

        for (int j = 0; j < quantas_dezenas; j++) {
            int dezenas;
            
            do {
                dezenas = gerar_numero_aleatorio(1, 60);
            } while (surpresinhas_repetidas[dezenas]);

            surpresinhas_repetidas[dezenas] = true;
            surpresinhas_geradas[i][j] = dezenas;
        }
    }

    return;
}

//gera dezenas aleatórias para as surpresinhas e sorteio
int gerar_numero_aleatorio(int min, int max) {
    return min + rand() % (max - min + 1);
}


//pede a quantidade de teimosinhas ao usuário
int qtd_teimosinhas() {
    int teimosinhas;
    do {
        printf("\n--> Digite a quantidade de teimosinhas (2, 4 ou 8): ");
        scanf("%d", &teimosinhas);
        
        if (teimosinhas != 0 && teimosinhas != 2 && teimosinhas != 4 && teimosinhas != 8) {
            printf("\nERRO! A quantidade de teimosinhas deve ser 2, 4 ou 8. Tente novamente.\n");
        }

    } while (teimosinhas != 0 && teimosinhas != 2 && teimosinhas != 4 && teimosinhas != 8);

    if (teimosinhas == 0) {
        teimosinhas = 1;
    }
    printf("\n");
    return teimosinhas;
}

//mostra as apostas manuais e surpresinhas e quantas teimosinhas para o usuário conferir 
void mostra_apostas(int posicao_manuais, int apostadas_manuais, int apostas_manuais[posicao_manuais][apostadas_manuais],int posicao_surpresinhas, int apostadas_surpresinhas ,int apostas_surpresinhas[posicao_surpresinhas][apostadas_surpresinhas], int quantas_teimosinhas) {
    int contador = 1;
    
    //exibe as apostas manuais
    for (int i = 0; i < posicao_manuais; i++) {
        printf("Aposta %d (manual): \n", contador);
        contador++; 
        for (int j = 0; j < apostadas_manuais; j++) {
            printf("%02d ", apostas_manuais[i][j]);
        }
        printf("\n\n");
    }

    //exibe as surpresinhas
    for (int i = 0; i < posicao_surpresinhas; i++) {
        printf("Aposta %d (surpresinha): \n", contador);
        contador++; 
        for (int j = 0; j < apostadas_surpresinhas; j++) {
            printf("%02d ", apostas_surpresinhas[i][j]);
        }
        printf("\n\n");
    }

    //exibe as teimosinhas
    printf("Teimosinhas: %d\n", quantas_teimosinhas);

    return;
}

//calcula o valor total das apostas
float valor_das_apostas(int teimosinhas, int dezenas, int manuais, int surpresinhas) {
    float valores[] = {0, 0, 0, 0, 0, 0, 5.0, 35.0, 140.0, 420.0, 1050.0, 2310.0, 4620.0, 6580.0, 15015.0, 25025.0};

    if (dezenas < 6 || dezenas > 15) {
        return 0.0;
    }

    float valor_dezenas = valores[dezenas];
    float valor_total = teimosinhas * (valor_dezenas * (manuais + surpresinhas));

    return valor_total;
}

//exibe o valor total e pergunta se o usuário deseja continuar
void exibir_valores(int teimosinhas, int dezenas, int manuais, int surpresinhas) {
    float valor_total = valor_das_apostas(teimosinhas, dezenas, manuais, surpresinhas);
    char resposta;
    
    printf("\nValor total das apostas: R$%.2f\n", valor_total);
    
    printf("\n--> Deseja continuar (S/N)? ");
    scanf(" %c", &resposta);
    
    if (resposta == 'S' || resposta == 's') {
            printf("\n=============================================================\n                Continuando para o sorteio...                \n=============================================================\n");           
       }

    else if (resposta == 'N' || resposta == 'n') {
        printf("\n=============================================================\n         Obrigado por participar das Loterias Caixa!         \n=============================================================\n");
        exit(0);
    }
   
    else {
        printf("\nERRO! Opcao invalida. Tente novamente.");
        return;
    }
    
    return;
}

//gera os sorteios e processa os resultados finais
void sorteio_e_resultados(int concursos, int num_dezenas, int num_apostas, int apostas[num_apostas][num_dezenas], int num_surpresinhas, int apostas_surpresinhas[num_surpresinhas][num_dezenas], float valor_total) {
    float quadra = 834.93;
    float quina = 32797.02;
    float sena = 118265926.76;
    float premio_total = 0.0;
    
    
    //repete os concursos de acordo com as teimosinhas
    for (int c = 1; c <= concursos; c++) {
        int contador = 0;

        int dezenas_sorteadas[6];
        
        bool ja_sorteadas[61] = {false};

        //gera os sorteios
        for (int i = 0; i < 6; i++) {
            int dezenas;
            
            do {
                dezenas = gerar_numero_aleatorio(1, 60);
            } while (ja_sorteadas[dezenas]);
            
            ja_sorteadas[dezenas] = true;
            dezenas_sorteadas[i] = dezenas;
        }

        //coloca o sorteio em ordem crescente
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 6; j++) {
                if (dezenas_sorteadas[i] > dezenas_sorteadas[j]) {
                    int aux = dezenas_sorteadas[i];
                    
                    dezenas_sorteadas[i] = dezenas_sorteadas[j];
                    dezenas_sorteadas[j] = aux;
                }
            }
        }

        //exibe qual concurso e quais as dezenas sorteadas
        printf("\nConcurso %04d:\n\n", c);
        printf("Dezenas sorteadas:\n");
        
        for (int i = 0; i < 6; i++) {
            printf("%02d ", dezenas_sorteadas[i]);
        }

        //compara e exibe os acertos
        for (int i = 0; i < num_apostas; i++) {
            int acertos = 0;
            
            for (int j = 0; j < num_dezenas; j++) {
                for (int k = 0; k < 6; k++) {
                    if (apostas[i][j] == dezenas_sorteadas[k]) {
                        acertos++;
                        break;
                    }
                }
            }
           
            printf("\n\nAposta %d: %d/%d acertos", contador + 1, acertos, num_dezenas);

            if (acertos == 4) {
                printf("\nQUADRA!");
                premio_total += quadra;
            } 
            else if (acertos == 5) {
                printf("\nQUINA!");
                premio_total += quina;
            } 
            else if (acertos == 6) {
                printf("\nSENA!");
                premio_total += sena;
            }
            contador++;
        }

        for (int i = 0; i < num_surpresinhas; i++) {
            int acertos = 0;
            
            for (int j = 0; j < num_dezenas; j++) {
                for (int k = 0; k < 6; k++) {
                    if (apostas_surpresinhas[i][j] == dezenas_sorteadas[k]) {
                        acertos++;
                        break;
                    }
                }
            }
            
            printf("\n\nAposta %d: %d/%d acertos", contador + 1, acertos, num_dezenas);

            if (acertos == 4) {
                printf("\nQUADRA!");
                premio_total += quadra;
            } 
            else if (acertos == 5) {
                printf("\nQUINA!");
                premio_total += quina;
            } 
            else if (acertos == 6) {
                printf("\nSENA!");
                premio_total += sena;
            }
            contador++;
        }

        
        printf("\n\n----------------------------------------\n");
    }
    
    //calcula o prêmio líquido e mostra o valor gasto, ganho, e o resultado da diferença entre eles
    float premio_liquido = premio_total - valor_total;

    printf("\n\nTotal da aposta:\nR$%.2f\n\n", valor_total);
    printf("Total dos premios:\nR$%.2f\n\n", premio_total);
    printf("Valor liquido:\nR$%.2f\n\n", premio_liquido);

    printf("\n=============================================================\n         Obrigado por participar das Loterias Caixa!         \n=============================================================\n");
    printf("\n");
}