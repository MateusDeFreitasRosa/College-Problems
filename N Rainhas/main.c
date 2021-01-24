#include <stdio.h>
#include <stdlib.h>

//Variaveis locais;
    int N = 10,sol = 0;

//Imprime o estado do tabuleiro.
void ImprimeTabuleiro(int tab[N][N], FILE *file) {
    int vetI[8], vetJ[8];
    int k=0;
    int i;
    for (i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            if (tab[i][j] == 1) {
                printf("R\t");
                vetI[k] = i;
                vetJ[k++] = j;
                fprintf(file,"R\t");
            }
            else {
                printf(".\t");
                fprintf(file,".\t");
            }
        }
        printf("\n");
        fprintf(file,"\n");
    }

    printf("Posicoes das Rainhas: \n" );
    fprintf(file,"Posicoes das Rainhas: \n");
    for (i=0; i<N; i++) {
        printf("%dº: %d,%d\n",i+1,vetI[i], vetJ[i]);
        fprintf(file,"%dº: %d,%d\n",i+1,vetI[i],vetJ[i]);
    }
}

//Verifica se é seguro tal posição, para adicionar uma Rainha.
int Safe(int tabuleiro[N][N], int linha, int coluna) {
    int i,j;
    //Verifica a coluna tabuleiro.
    for (i=0; i<N; i++) {
        if (tabuleiro[linha][i] == 1) {
            return 0;
        }
    }

    //Verifica a linha do tabuleiro.
    for (i=0; i<N; i++) {
        if (tabuleiro[i][coluna] == 1) {
            return 0;
        }
    }

    //Verifica diagonais.

    //Diagonal pricipal cima.
    for (i=linha,j=coluna; i>=0 && j>=0; i--,j--) {
        if (tabuleiro[i][j] == 1) {
            return 0;
        }
    }

    //Diagonal princila abaixo.
    for(i = linha, j = coluna; i < N && j < N; i++, j++)
	{
		if(tabuleiro[i][j] == 1) {
			return 0;
		}
	}

	//Verifica diagonal secundaria acima.
	for(i = linha, j = coluna; i >= 0 && j < N; i--, j++)
	{
		if(tabuleiro[i][j] == 1) {
			return 0;
		}
	}

	//Verifica diagonal secundaria abaixo
	for(i = linha, j = coluna; i < N && j >= 0; i++, j--)
	{
		if(tabuleiro[i][j] == 1) {
			return 0;
		}
	}
    return 1;
}

void executar(int tab[N][N], int col, FILE *file)
{
	if(col == N)
	{
		printf("Solucao:%d\n\n",sol+1);
		ImprimeTabuleiro(tab,file);
		sol++;
		return;
	}
	for(int i = 0; i < N; i++)
	{
		// verifica se é seguro colocar a rainha naquela coluna
		if(Safe(tab, i, col) == 1)
		{
			// insere a rainha (marca com 1)
			tab[i][col] = 1;

			// chamada recursiva
			executar(tab,col + 1, file);

			// remove a rainha (backtracking)
			tab[i][col] = 0;
		}
	}
}


int main()
{
    FILE *file;
    file = fopen("Output.txt", "w");
    int i=0;
    int tabuleiro[N][N];
    if (file != NULL) {
        for (i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                tabuleiro[i][j] = 0;
            }
        }

        executar(tabuleiro,0,file);
        printf("Solucao: %d\n",sol);
        fprintf(file,"Solucao: %d\n",sol);
    }
    else {
        printf("Arquivo não aberto");
    }
    fclose(file);
    return 0;
}
