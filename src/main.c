#include "labirinto.h"

int main() {
    int menu;
    printf("Escolha uma opção:\n1 - DFS\n2 - BFS\n3 - A*\n0 - Sair do programa\n");
    scanf("%d", &menu);
    while(menu != 0){
        switch(menu){
            case 1:
                FazDFS();
            break;
            case 2:
                FazBFS();
            break;
            case 3:
                FazA();
            break;
            default: printf("\nNúmero inválido\n");
        }
    
        printf("Escolha uma opção:\n1 - DFS\n2 - BFS\n3 - A*\n0 - Sair do programa\n");
        scanf("%d", &menu);
    }
    
    return 0;
}