#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define N 11

struct par {int vertice, ordem;};

bool compara(par a, par b){return a.ordem > b.ordem;}

int main(int argc, char const *argv[]) {
      int matriz[N][N] = {
            0,1,0,0,0,0,0,1,0,0,0,
            1,0,0,1,0,0,0,0,0,0,0,
            0,0,0,1,0,0,0,0,0,0,0,
            0,1,1,0,0,0,0,0,1,0,1,
            0,0,0,0,0,1,0,0,0,0,1,
            0,0,0,0,1,0,1,0,0,0,0,
            0,0,0,0,0,1,0,1,0,0,1,
            1,0,0,0,0,0,1,0,1,1,1,
            0,0,0,1,0,0,0,1,0,1,0,
            0,0,0,0,0,0,0,1,1,0,1,
            0,0,0,1,1,0,1,1,0,1,0,
      };

      // Zera o vetor das ordens:
      par vetor[N]; for (auto &i : vetor) i.ordem = 0;

      // Seta as ordens dos vértices:
      for (size_t i = 0; i < N; i++) for (size_t j = 0; j < N; j++) if (matriz[i][j]) vetor[i].ordem++;

      // Numera os vértices antes de ordenar
      for (size_t i = 0; i < N; i++) vetor[i].vertice = i;

      // Ordena
      sort (vetor, vetor + N, compara);

      // Zera o vetor de cores e seta o primeiro com a  cor 1
      int qtdCores = 1, cores[N]; for (auto &i : cores) i = 0; cores[vetor[0].vertice] = qtdCores;

      // Variável para saber quando colorir um vértice
      int colorido = 0;
      // Para cada posição no vértice de cores, se for a primeira posição ou se o vértice não estiver colorido
      for (size_t k = 0; k < N; k++) if (!k || !cores[vetor[k].vertice]) {
            // Para cada coluna da matriz, ordenados pela ordem dos vértices, se não houver adjacência com o vértice K,
            for (size_t i = 0; i < N; i++) if (!matriz[vetor[k].vertice][vetor[i].vertice]) {
                  // Para cada linha da coluna sem adjacência com o vértice K, se houver adjacênia com algum vértice
                  for (size_t j = 0; j < N; j++) if (matriz[vetor[j].vertice][vetor[i].vertice]) {
                        // Se o vértice estiver pintado
                        if (cores[vetor[j].vertice] == qtdCores) {
                              colorido = 0;
                              break;
                        }
                        colorido = 1;
                  }
                  // Se há permisão, pinta
                  if (colorido && !cores[vetor[i].vertice]) cores[vetor[i].vertice] = qtdCores;
            }
            qtdCores++;
      }

      for (int i = 0; i < N; i++) {
            printf("%c:", vetor[i].vertice + 65);
            switch (cores[vetor[i].vertice]) {
                  case 1: printf(" cor 1\n"); break;
                  case 2: printf(" cor 2\n"); break;
                  case 3: printf(" cor 3\n"); break;
                  case 4: printf(" cor 4\n"); break;
                  case 5: printf(" cor 5\n"); break;
                  default: printf(" sem cor\n");
            }

      }

      return 0;
}