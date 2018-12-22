#include <stdio.h>
#include <stdlib.h>

typedef struct grafo{
   int nV;
   int nA;
   int matrizAdj[11000][11000];
   int grau[11000];
} Grafo;

Grafo grafo;
int visitados[11000];
int ciclo;

void DFS(int vi) {
  int w;
  visitados[vi]=1;
  if(ciclo)return;
  for (w = 0; w < grafo.grau[vi]; w++) {
      if (visitados[grafo.matrizAdj[vi][w]]==1) {
        ciclo=1;
        return;
      }else if(visitados[grafo.matrizAdj[vi][w]]==0){
        DFS(grafo.matrizAdj[vi][w]);
      }

  }
  visitados[vi]=1;
}

int main(int argc, char const *argv[]) {

  int Ncasos,numV,numA;
  int v,u;
  int i,j,k;

  //quantidade de casos de teste
  scanf("%d\n",&Ncasos );
  for (i = 0; i < Ncasos; i++) {
    scanf("%d %d\n",&numV,&numA);
    ciclo=0;
  //  criaGrafo(numV,numA);

    for (j = 0; j < numA; j++) {
      scanf("%d %d\n",&u,&v);
      grafo.matrizAdj[u-1][grafo.grau[u-1]]=v;
      grafo.grau[u-1]++;
    }

    for (int ii = 0; ii < numV; ++ii) {
      for (int jj = 0; jj < grafo.grau[ii]; ++jj) {
        printf("[%d][%d]\n", grafo.matrizAdj[ii][jj]);
      }
      /* code */
    }

    //zera os marcados
    for (k = 0; k < numV; k++) {
      if (!visitados[k])
				DFS(k);
			if (ciclo) break;
    }
    if (ciclo) {
      printf("SIM\n");
    }else{
      printf("NAO\n");
    }

  }
  printf("\n");
  return 0;
}

