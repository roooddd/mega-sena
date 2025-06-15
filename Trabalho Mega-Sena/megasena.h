#ifndef MEGASENA_H
#define MEGASENA_H
#include <stdbool.h>

int pedir_dezenas();

int qtd_manuais();

int qtd_surpresinhas();

void solicitar_apostas_manuais(int quantas_apostas, int quantas_dezenas, int apostas_feitas[quantas_apostas][quantas_dezenas]);

void escanear_dezenas(int quantas_dezenas, int lista_dezenas[quantas_dezenas], int n_aposta);

bool valida_dezenas(int dezenas[], int tamanho);

bool tem_numero_repetido(int dezenas[], int tamanho);

void gerador_de_surpresinhas(int quantas_surpresinhas, int quantas_dezenas, int surpresinhas_geradas[quantas_surpresinhas][quantas_dezenas]);

int gerar_numero_aleatorio(int min, int max);

int qtd_teimosinhas();

void mostra_apostas(int posicao_manuais, int apostadas_manuais, int apostas_manuais[posicao_manuais][apostadas_manuais],int posicao_surpresinhas, int apostadas_surpresinhas ,int apostas_surpresinhas[posicao_surpresinhas][apostadas_surpresinhas], int quantas_teimosinhas);

float valor_das_apostas(int teimosinhas, int dezenas, int manuais, int surpresinhas);

void exibir_valores(int teimosinhas, int dezenas, int manuais, int surpresinhas);

void sorteio_e_resultados(int concursos, int num_dezenas, int num_apostas, int apostas[num_apostas][num_dezenas], int num_surpresinhas, int apostas_surpresinhas[num_surpresinhas][num_dezenas], float valor_total);

#endif