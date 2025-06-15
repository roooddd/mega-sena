#include "megasena.h"
#include <stdlib.h>
#include <time.h>

int main() {
    //faz com que em cada execução, as dezenas aleatórios mudem
    srand(time(NULL));

    //pede o número de dezenas  
    int numero_dezenas = pedir_dezenas();

    //pede o número de apostas manuais
    int numero_manuais = qtd_manuais();

    //entrada das apostas manuais feitas pelo usuário
    int apostas[numero_manuais][numero_dezenas];
    solicitar_apostas_manuais(numero_manuais, numero_dezenas, apostas);
    
    //pede o número de apostas surpresinhas
    int numero_surpresinhas = qtd_surpresinhas();
    
    //gera as surpresinhas aleatórias
    int surpresinhas[numero_surpresinhas][numero_dezenas];
    gerador_de_surpresinhas(numero_surpresinhas, numero_dezenas, surpresinhas);

    //pede o número de teimosinhas
    int numero_teimosinhas = qtd_teimosinhas();

    //mostra as apostas feitas
    mostra_apostas(numero_manuais, numero_dezenas, apostas, numero_surpresinhas, numero_dezenas, surpresinhas, numero_teimosinhas);

    //declara o valor total das apostas
    float valor_total = valor_das_apostas(numero_teimosinhas, numero_dezenas, numero_manuais, numero_surpresinhas);

    //exibe os valores referentes as apostas e suas dezenas
    exibir_valores(numero_teimosinhas, numero_dezenas, numero_manuais, numero_surpresinhas);

    //faz o sorteio e exibe os resultados finais
    sorteio_e_resultados(numero_teimosinhas, numero_dezenas, numero_manuais, apostas, numero_surpresinhas, surpresinhas ,valor_total);

    return 0;
}