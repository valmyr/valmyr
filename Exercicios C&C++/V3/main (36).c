#include<stdlib.h>
#include<stdio.h>
#include <math.h>
#include <time.h>


float **Alocar_Matriz(int linhas, int colunas);
float **Mult(float **M1,float **M2,int linhas ,int comum, int colunas);
void Pesos_Aleatorios(float **m, int linhas, int colunas);
void tanh_(float **m,int linhas,int colunas);
float **Erro_Derivado(float **M1,float **M2,int linhas, int colunas);
void Atualizacao_pesos(float **e, float **M2, int linhas, int colunas);
float **converter_matriz_erro(float **e, int linhas, int colunas);
void Exibir(float **m, int linhas, int colunas);

int main(){
  float **x, **w,**s,**y,**e;
  x = Alocar_Matriz(1, 2);//x = entradas
  w = Alocar_Matriz(2, 2);//w = pesos
  y = Alocar_Matriz(1, 2);//y = saida || alvo
  y[0][0] = .5;//alvos
  y[0][1] = .3;//alvos
  Pesos_Aleatorios(w, 2, 2);//pesos iniciados aleatoriamente
  x[0][0] = 0.5;//entradas
  x[0][1] = .1;
  for(int i = 0; i < 100; i++){//treinamento
    s = Mult(x, w, 1, 2, 2);//EntradasXPesos
    tanh_(s,1,2);//função tangente hiperbolica
    e = Erro_Derivado(y,s,1,2);//erro = alvo - saida da rede
    e = converter_matriz_erro(e,1,2);//
    e = Mult(e,x,2,1,2);
    Atualizacao_pesos(e, w, 2,2);//atualização de pesos
    printf("epocas [%d] >> ",i);
    Exibir(s,1,2);//exibir saida

  }

  return 0;
}
float **Alocar_Matriz(int linhas, int colunas){
  float **m;
  m = malloc(sizeof(float*)*linhas);
  for(int i = 0; i < linhas; i++){
    m[i] = malloc(sizeof(float)*colunas);
    for(int j = 0; j < colunas; j++){
      m[i][j] = 0;
    }
  }
  return m;
}
float **Mult(float **M1,float **M2,int linhas ,int comum, int colunas){
  float **m = Alocar_Matriz(linhas, colunas);
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      float soma = 0;
      for(int k = 0; k < comum; k++){
        soma+= M1[i][k]*M2[k][j];
      }
      m[i][j] = soma;
    }
  }
  return m;
}

void Pesos_Aleatorios(float **m, int linhas, int colunas){
  for(int i = 0;i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      m[i][j] = (float)(rand()%101)/100;
    }
  }
}
void tanh_(float **m,int linhas,int colunas){
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
        m[i][j] = tanh(m[i][j]);
    }
  }
}

float **Erro_Derivado(float **M1,float **M2,int linhas, int colunas){
  float **m;
  m = Alocar_Matriz(linhas, colunas);
  for(int i = 0; i < linhas; i++){
    for(int j = 0; j < colunas; j++){
      m[i][j] = (M1[i][j] - M2[i][j])*(1-(M1[i][j] - M2[i][j]));
    }
  }
  return m;
}
void Atualizacao_pesos(float **e, float **M2, int linhas, int colunas){
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            M2[i][j]+=e[i][j];
        }
    }

}
float **converter_matriz_erro(float **e, int linhas, int colunas){
  float **m;
  m = Alocar_Matriz(colunas, linhas);
  for(int i = 0; i < colunas; i++){
      for(int j = 0;j < linhas; j++){
          m[i][j]=e[j][i];
      }
  }
  return m;
}
void Exibir(float **m, int linhas, int colunas){
    for(int i = 0; i< linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("[   %.9f    ]",m[i][j]);
        }
        printf("\n");
    }
}