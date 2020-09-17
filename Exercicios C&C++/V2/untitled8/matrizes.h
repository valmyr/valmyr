//
// Created by valmy on 06/06/2020.
//

#ifndef UNTITLED8_MATRIZES_H
#define UNTITLED8_MATRIZES_H

#endif //UNTITLED8_MATRIZES_H
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>

float **alocar_matriz(int linhas, int colunas);
void tanh_(float **m, int linhas, int colunas);
float **Multiplicacao_de_Matrizes(float **M1, float **M2, int Linhas_M1,int Comum_M1_e_M2,int Colunas_M2);
float **alocar_matriz(int linhas, int colunas){
    float **m;
    m = (float**)malloc(sizeof(float*)*linhas);
    for(int i = 0; i < linhas; i++){
        m[i] = (float*)malloc(sizeof(float)*colunas);
        for(int  j = 0; j < colunas; j++){
            m[i][j] = 0;
        }
    }
    return m;
}
float **Multiplicacao_de_Matrizes(float **M1, float **M2, int Linhas_M1,int Comum_M1_e_M2,int Colunas_M2){
    float **m = alocar_matriz(Linhas_M1,Colunas_M2);
    for(int i = 0; i < Linhas_M1; i++){
        for(int j = 0; j < Colunas_M2; j++){
            float Somatorio = 0;
            for(int k = 0; k < Comum_M1_e_M2; k++){
                Somatorio += M1[i][k]*M2[k][j];
            }
            m[i][j] = Somatorio;
        }
    }
    return m;
}
void tanh_(float **m, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            m[i][j] = (float)(exp(m[i][j]) - exp(-m[i][j]))/(exp(m[i][j])+exp(-m[i][j]));
        }
    }
}
