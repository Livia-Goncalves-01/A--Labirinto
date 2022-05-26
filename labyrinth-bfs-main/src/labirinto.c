#include "labirinto.h"

void Inicializar(Labirinto *lab, int l, int c) {
    lab->coluna = c;
    lab->linha = l;
    lab->map = malloc(l * sizeof(Cell*));

    for(int i=0; i<l; i++) {
        lab->map[i] = malloc(c *sizeof(Cell));
    }
}

void Finalizar(Labirinto *lab) {
    for(int i=0; i<lab->linha; i++) {
        free(lab->map[i]);
    }
    free(lab->map);
}

void ImprimirLab(Labirinto *lab) {
    printf("\n");
    for(int i=0; i<lab->linha; i++) {
        for(int j=0; j<lab->coluna; j++) {
            printf("%c ", lab->map[i][j].value);
        }
        printf("\n");
    }
    printf("\n");
}

int BFS(Labirinto *lab, Fila *f, int n) {
    bool cont=true;
    int count = 1, x=0, y=0;
    Item aux, tmp;

    while (cont)
    {
        Desenfileira(f, &aux);
        x = aux.x;
        y = aux.y;
        if((x+1) < lab->linha && lab->map[x+1][y].value != '#' && !lab->map[x+1][y].added && cont) {
            tmp.x = x+1;
            tmp.y = y;
            Opcao(n, lab, &tmp);
            lab->map[tmp.x][tmp.y].added = true;
            Enfileira(f, tmp);
            count++;
            if(checkLast(lab, f))
                cont = false;
        }
        if((y+1) < lab->coluna && lab->map[x][y+1].value != '#' && !lab->map[x][y+1].added && cont) {
            tmp.x = x;
            tmp.y = y+1;
            Opcao(n, lab, &tmp);
            lab->map[tmp.x][tmp.y].added = true;
            Enfileira(f, tmp);
            count++;
            if(checkLast(lab, f))
                cont = false;
        }
        if((y-1) >= 0 && lab->map[x][y-1].value != '#' && !lab->map[x][y-1].added && cont) {
            tmp.x = x;
            tmp.y = y-1;
            Opcao(n, lab, &tmp);
            lab->map[tmp.x][tmp.y].added = true;
            Enfileira(f, tmp);
            count++;
            if(checkLast(lab, f))
                cont = false;
        }
        if((x-1) >= 0 && lab->map[x-1][y].value != '#' && !lab->map[x-1][y].added && cont) {
            tmp.x = x-1;
            tmp.y = y;
            Opcao(n, lab, &tmp);
            lab->map[tmp.x][tmp.y].added = true;
            Enfileira(f, tmp);
            count++;
            if(checkLast(lab, f))
                cont = false;
        }
        if(n == 1 || n == 2){
            OrdenaBubble(f);
        }
        
        lab->map[x][y].value = 'o';
    }
    return count;
}

bool checkLast(Labirinto *lab, Fila *f) {
    if(f->U->data.x == (lab->linha-1) && f->U->data.y == (lab->coluna-1)){
        lab->map[f->U->data.x][f->U->data.y].value = 'o';
        return true;
    }
        
    return false;
}

bool LerArquivo(Labirinto *lab) {
    FILE *fp;
    char arquivo[ARQ_MAXTAM];
    char cell;
    int i=0, j=0;

    scanf("%c", (char *) stdin);
    printf("Nome do arquivo onde esta o  labirinto(com extensao): ");
	fgets(arquivo, ARQ_MAXTAM, stdin);
	strtok(arquivo, "\n");

    fp = fopen(arquivo, "r");
    if (fp == NULL) {
        printf("\nErro!Nao foi possivel abrir o arquivo!\n");
        exit(1);
    } else {
        while((cell = (char)fgetc(fp)) != EOF) {
            if(cell == '\n') {
                i++;
                j = 0;
            }
            else {
                lab->map[i][j].value = cell;
                lab->map[i][j].added = false;
                lab->map[i][j].left = false;
                lab->map[i][j].right = false;
                lab->map[i][j].bottom = false;
                j++;
            }
        }
    }
    fclose(fp);

    return true;
}

void Manhattan(Labirinto *lab, Item *tmp){
    tmp->calculo = abs (tmp->x - (lab->linha-1)+ tmp->y - (lab->coluna-1));
}

void Euclidiana(Labirinto *lab, Item *tmp){
    int variavel1, variavel2;
    variavel1 = tmp->x - lab->linha-1;
    variavel2 = tmp->y - lab->coluna-1;
    tmp->calculo = sqrt((pow(variavel1,2)) + (pow(variavel2,2)));
}

int EscolhaA(){
    int n;
    printf("Escolha de acordo com a heurística desejada: \n1-Euclidiâna.\n2-Manhattan.");
    scanf("%d", &n);
    
    return n;
}

void Opcao( int n, Labirinto *lab , Item *tmp){
    if(n == 1){
        Euclidiana(lab, tmp);
    }else if( n == 2){
        Manhattan(lab, tmp);
    }
}

int DFS(Labirinto *lab, Pilha *p) {
    bool cont = true;
    Pos aux, tmp;
    int count = 1;
    int x=0, y=0;

    while (cont) {
        aux = POP(p);
        x = aux.x;
        y = aux.y;

        if(x == (lab->linha - 1) && y == (lab->coluna - 1)) {
            cont = false;
        } else {
            if((x+1) < lab->linha && lab->map[x+1][y].value != '#' && !lab->map[x][y].bottom) {
                lab->map[x][y].bottom = true;
                tmp.x = x;
                tmp.y = y;
                PUSH(p, tmp);
                if((x+1) < lab->linha && lab->map[x+1][y].value != '#') {
                    tmp.x = x+1;
                    tmp.y = y;
                    PUSH(p, tmp);
                    count++;
                }
            } else if((y+1) < lab->coluna && lab->map[x][y+1].value != '#' && !lab->map[x][y].right) {
                lab->map[x][y].right = true;
                tmp.x = x;
                tmp.y = y;
                PUSH(p, aux);
                if((y+1) < lab->coluna && lab->map[x][y+1].value != '#') {
                    tmp.x = x;
                    tmp.y = y+1;
                    PUSH(p, tmp);
                    count++;
                }
            } else if((y-1) > 0 && lab->map[x][y-1].value != '#' && !lab->map[x][y].left) {
                lab->map[x][y].left = true;
                tmp.x = x;
                tmp.y = y;
                PUSH(p, aux);
                if((y-1) > 0 && lab->map[x][y-1].value != '#') {
                    tmp.x = x;
                    tmp.y = y-1;
                    PUSH(p, tmp);
                    count++;
                }
            } else {
                lab->map[x][y].bottom = true;
                lab->map[x][y].right = true;
                lab->map[x][y].left = true;   
            }
        }

        lab->map[x][y].value = 'o';
    }

    return count;
}

void FazDFS(){
    Labirinto L;
    Pilha P;
    Pos I;
    int iteracoes=0, l=0, c=0;

    I.x = 0;
    I.y = 0;
    FPVazia(&P);
    PUSH(&P, I);

    printf("Quantidade de linhas do labirinto: ");
    scanf("%d", &l);
    printf("Quantidade de colunas do labirinto: ");
    scanf("%d", &c);
    
    Inicializar(&L, l, c);

    LerArquivo(&L);

    printf("\n");
    ImprimirLab(&L);

    iteracoes = DFS(&L, &P);

    printf("\nNumero de interacoes: %d\n", iteracoes);

    ImprimirLab(&L);

    Finalizar(&L);

}

void FazA(){
    Labirinto L;
    Fila F;
    Item I;
    int iteracoes=0, l=0, c=0, n =0;

    I.x = 0;
    I.y = 0;
    n = EscolhaA();
    FFVazia(&F);
    
    printf("Quantidade de linhas do labirinto: ");
    scanf("%d", &l);
    printf("Quantidade de colunas do labirinto: ");
    scanf("%d", &c);
    
    Inicializar(&L, l, c);

    LerArquivo(&L);
    Enfileira(&F, I);
    L.map[I.x][I.y].added = true;

    printf("\n");
    ImprimirLab(&L);

  
    iteracoes = BFS(&L, &F, n);
    

    printf("\nNumero de interacoes: %d\n", iteracoes);

    ImprimirLab(&L);

    Finalizar(&L);
}
void FazBFS(){
    Labirinto L;
    Fila F;
    Item I;
    int iteracoes=0, l=0, c=0, n =0;

    I.x = 0;
    I.y = 0;
    n = 0;
    FFVazia(&F);
    
    printf("Quantidade de linhas do labirinto: ");
    scanf("%d", &l);
    printf("Quantidade de colunas do labirinto: ");
    scanf("%d", &c);
    
    Inicializar(&L, l, c);

    LerArquivo(&L);
    Enfileira(&F, I);
    L.map[I.x][I.y].added = true;

    printf("\n");
    ImprimirLab(&L);

  
    iteracoes = BFS(&L, &F, n);
    

    printf("\nNumero de interacoes: %d\n", iteracoes);

    ImprimirLab(&L);

    Finalizar(&L);
}
