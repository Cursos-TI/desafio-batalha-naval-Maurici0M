#include <stdio.h>

//para gerar numeros aleatorios
#include <time.h>
#include <stdlib.h>

//irá ter o tabuleiro sem os navios (para ser printado no início)
void printTabuleiroInicial(){

    char * tabuleiroNaval[10][10] = {
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
    };

    printf("\n\n"); //para pular linhas antes das letras serem impressas;
    printf(" "); //para que as letras sejam impressas aqui (de um espaço para as letras se alinharem);
    for (char colunas = 'A'; colunas <= 'J'; colunas++){
        //ira imprimir as letras das colunas (horizontal ->)
        printf(" %c", colunas);
    }
    
    printf("\n");
    for (int x = 0; x < 10; x++){
        //ira imprimir os numeros das linhas (vertical)
        printf("%d", x);
        for (int y = 0; y < 10; y++){
            //imprimira o tabuleiro
            printf("%s", tabuleiroNaval[x][y]);
        }
        printf("\n");
    }
    
}

//irá ter o tabuleiro com os navios (para ser printado depois da escolha do jogador para comparar)
void tabuleiroResposta(char x, int y){
    //o x representa a coluna:   ➡️
    //o y representa a linha:    ⬇️

    int 
    coluna; 

    srand(time(0)); //inicializa a geracao de numeros aleatorios com base na hora

    //irá adicionar um valor a var coluna, a depender do valor recebido no char x;
    switch (x){
        case 'A':
        case 'a':
            coluna = 0;
            break;

        case 'B':
        case 'b':
            coluna = 1;
            break;

        case 'C':
        case 'c':
            coluna = 2;
            break;

        case 'D':
        case 'd':
            coluna = 3;
            break;

        case 'E':
        case 'e':
            coluna = 4;
            break;

        case 'F':
        case 'f':
            coluna = 5;
            break;

        case 'G':
        case 'g':
            coluna = 6;
            break;

        case 'H':
        case 'h':
            coluna = 7;
            break;

        case 'I':
        case 'i':
            coluna = 8;
            break;

        case 'J':
        case 'j':
            coluna = 9;
            break;
    
        default:
            coluna = rand() %10; //gerara um numero aleatorio de 0 a 9 caso caia no default
            break;
    }
    
    if (y < 0 && y > 9){
        y = rand() % 10;

        printf("\n*** Número inválido! Gerando escolha aleatória do computador... ***");
    }
    

    char * tabuleiroNaval[10][10] = {
        {"🚢", "🌊", "🌊","🌊", "🌊", "🚢","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🚢"},
        {"🌊", "🌊", "🌊","🚢", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🚢", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🚢", "🌊", "🌊", "🌊"},
        {"🌊", "🌊", "🌊","🌊", "🌊", "🌊","🌊", "🌊", "🌊", "🌊"},
    };
    

    //ira verificar se os valores estao sendo capturados corretamente
    printf("\n\nLOG de CONTROLE -> x = %d y = %d\n\n", coluna, y);

    printf("\n\nResultado: %s", tabuleiroNaval[coluna][y]);
}

//mensagens para escolher onde atacar (x '->' e y '⬆️')
void mensagemAtaqueColuna(){
    printf(
        "\n\nPretende atacar em qual COLUNA (de A até J)? \n"
        "\nEscolha: "
    );
}

void mensagemAtaqueLinha(){
    printf(
        "\n\nPretende atacar em qual LINHA (de 0 até 9)? \n"
        "\nEscolha: "
    );
}

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    char
    coluna; 

    unsigned int
    linha = 0;

    printTabuleiroInicial();

    mensagemAtaqueColuna();
    scanf("%c", &coluna);

    mensagemAtaqueLinha();
    scanf("%d", &linha);

    tabuleiroResposta(coluna, linha);

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
