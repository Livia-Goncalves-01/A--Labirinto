# Labrinto por Busca em Largura(BFS)

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/Language-C-blue"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20in-VSCode-red"/> 
</div>

<p align="justify">
Busca em largura é um algoritmo normalmente ultilizado para realizar busca ou travessia em árvores, mas pode ser aplicado em outros casos também. Um desses casos é em matrizes, que podem ser labirintos, para chegar de uma determinada posição inicial até uma determindada posição final. Em labirintos essas posições seriam a entrada e saída dele. Para este algoritmo há duas estruturas importantes a matriz que é o labirinto e a Fila dinâmica que guarda o caminho percorrido.
</p>

<p align="justify">
  A estrutua da matriz possui um tamanho, uma largura, o dado de cada posição da matriz e se esta posição já esteve na fila anteriormente. Esta irá representar um labirinto de tamanho n e largura m em que cada posição pode ter um dos tipos de dado a seguir:
  <ul>
    <li>"." - Simboliza um caminho passável no labirinto.</li>
    <li>"#" - Simboliza uma parede no labirinto.</li>
  </ul>
  E para um labirinto ser válido tem que exister pelo menos um caminho da entrada para o final. O labirinto a seguir é um labirinto 3x3 válido de exemplo:
</p>
<p align="center">
  <img src="imgs/matrizlabirintoBFS.png" width="400px">
</p>

<p align="justify">
  A estrutura fila dinâmica, [vide git](<a href="https://github.com/mpiress/dynamic_queue">https://github.com/mpiress/dynamic_queue</a>), será utilizada para guardar o caminho tomado da entrada para chegar na saída. A fila dinâmica é uma variante do modelo de fila estática, onde há um ponteiro que aponta para o início da fila, um ponteiro que aponta para o fim da fila e os dados que possuem um valor que é passado para chegar nele. A estrutura pode ser vista pela visualização gráfica abaixo:  
</p>
<p align="center">
  <img src="imgs/filaestrutura.png">
</p>

<p align="justify">
  Com as estruturas explicadas agora vamos entender como o método BFS funciona. Primeiro a posição inicial é adicionada a fila, depois o algoritmo retira a primeira posição da fila e olha seus "vizinhos" conferindo as posições possíveis, sendo abaixo, à direita, à esquerda ou acima nesta ordem. Quando essa verificação se torna possível, essa posição é adicionada a fila.  Após isto, o algoritmo vai pegar a novamente a primeira posição da fila e verificar os "vizinhos" desta posição adicionando os que forem possível de passar na fila, se alguma "vizinho" já estiver na lista ele não é adicionado de novo. Esta operação será repetida até a última posição adicionada à fila for a posição final do labirinto.
</p>
<p align="justify">
  Verificação das posições "vizinhas" da primiera posiçao da fila para as adicionar na fila, no exemplo o algoritmo primeiramente irá adicionar primiero o de baixo, depois o da direita, depois o daa esquerda e por último o de cima:
</p>
<p align="center">
  <img src="imgs/adicionar.png">
</p>


<p align="justify">
  Conclusão do labirinto e sua fila:
</p>
<p align="center">
  <img src="imgs/conclusaofila.png">
</p>

# Algoritmo
<h3>fila.h e fila.c</h3>
<p align="justify">Nessa estrutura temos a função Enfilera e Desenfilera, a função FFVazia, que inicializa a fila com valores nulos, e a função imprime, que imprime os valores obtidos na fila. </p>

<h3>labirinto.h e labirinto.c</h3>
<p align="justify"> Utilizou-se as estruturas Cell e Fila para a criação da matriz e fila e análise das posições ao caminhar no labirinto. As funções inicializar e finalizar se refere a inicialização e finalização do labirinto. Com isso, é possivel imprimir o mesmo ultilizando a função ImprimirLab.</p>

<p align="justify">A função LerArquivo permite a leitura de arquivo em que está inserido o labirinto. Para a realização da leitura correta é necessário que o labirinto seja descrito no formato de matriz e considerando "." como passagem/caminho livre e "#" como a parede que impede de seguir o caminho, além disso é preciso inserir o nome do arquivo com sua extensão para evitar erros. Veja o exemplo a seguir: </p>

<p align="center">
  <img src="imgs/exemplolabirintotxt.png">
</p>

<p align="justify">A função checkLast verifica se a ultima posição da fila é a última da matriz definida pelo labirinto.</p>

    Interações

    As interações são definidas pela função BFS, sendo tratadas através das inserções(enfileiramento) dentro da fila, desconsiderando a desenfileração dos valores.

<h3>main.c</h3>

<p align="justify">No main, inicializamos a fila vazia e em seguida pedimos ao usuário o número de linhas e colunas do labirinto disponível no arquivo e consequentemente pedimos o nome do arquivo com a extensão. Inicializamos o labirinto e a leitura do arquivo, para conferir se a leitura esta correta, imprimos o labirinto - para questões de comparação (caso o usuário queira conferir o resultado) e atribuimos a variavél iteracoes a função BFS e mostramos o resultado final de interações. Finalizamos a fila e o labirinto no final.</p>

# Compilação e Execução

O algoritmo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


<p>Trabalho realizado Gabriel Teixeira Júlio e Lívia Gonçalves - Maio/2022</p>
