#include <stdio.h>
#include <stdlib.h>

//Estrutura para salvar os dados dos jogadores
typedef struct {
	char nome[21];
	int nVitorias;
	int pontos;
}Jogador;

// Fun��o que preenche todos os lugares da matriz com -
void inicia(char matriz[3][3]){
	int i ,j;
	for(i = 0; i<3; i++){
		for(j = 0; j<3; j++){
			matriz[i][j] = '-';
		}
	}
}
//Fun��o menu
void menu(){
	system("cls");
	printf("\n\t\tBem vindo ao JOGO DA VELHA ");
	printf("\n\tEscolha as opcoes de jogo:");
	printf("\n\t 1 - SinglePlayer");
	printf("\n\t 2 - MultiPlayer");
	printf("\n\t 3 - Modo Campeonato");
	printf("\n\t 0 - Sair :  ");
	
}
// Fun��o para imprimir o tabuleiro na tela
void tabuleiro(char Matriz[3][3]){
	
	printf("\n  X\t 0 \t|\t 1 \t|\t 2 \tX  \n");
	printf("\n\nY\n0 \t %c \t|\t %c \t|\t %c",Matriz[0][0],Matriz[0][1], Matriz[0][2]);
	printf("\n \t------------------------------------");
	printf("\n1 \t %c \t|\t %c \t|\t %c",Matriz[1][0],Matriz[1][1], Matriz[1][2]);
	printf("\n \t------------------------------------");
	printf("\n2 \t %c \t|\t %c \t|\t %c",Matriz[2][0],Matriz[2][1], Matriz[2][2]);
	printf("\nY\n\n");
	printf("\t Y sao as linhas do jogo da velha\n");
	printf("\t X sao as colunas do jogo da velha\n");
}
// Fun��o para verificar se a posi��o existe ou se ja esta ocupada
int verificaPosicao(char matriz[3][3],int x, int y){
	
	if(matriz[y][x] != '-'){
		return 0;
	}
	return 1;
}
// Fun��o para inserir X ou O na posi��o escolhida
int inserirNaPosicao(char matriz[3][3],int x, int y, char v){
	int valida;
	system("cls");
	if(x>2||x<0||y>2||y<0){
		printf("\n Posicao Invalida");
		return 1;
	}
	
	valida = verificaPosicao(matriz,x,y);
	
	if(valida == 1){
		matriz[y][x] = v;
		return 0;
	}
	return 1;
}
//Fun��o para Receber a posi��o do jogador e inserir no local
void jogador1(char posicaoMatriz[3][3]){
	int ret,X,Y;
	do{
		system("cls");
		tabuleiro(posicaoMatriz);
		printf("\n Jogador 1 entre com a posicao Y Linha : ");
		scanf("%d", &Y);
		printf("\n Jogador 1 entre com a posicao X Coluna: ");
		scanf("%d", &X);
		ret = inserirNaPosicao(posicaoMatriz, X, Y, 'X');
	}while(ret != 0);
}
//Fun��o para Receber a posi��o do jogador e inserir no local
void jogador2(char posicaoMatriz[3][3]){
	int ret,X,Y;
	do{
		system("cls");
		tabuleiro(posicaoMatriz);
		printf("\n Jogador 2 entre com a posicao Y: ");
		scanf("%d", &Y);
		printf("\n Jogador 2 entre com a posicao X: ");
		scanf("%d", &X);
		ret  = inserirNaPosicao(posicaoMatriz, X, Y, 'O');
	}while(ret != 0);
}
//Fun��o para gerar de forma aleatoria a posi��o do jogadorPC e inserir no local
void jogadorPC(char posicaoMatriz[3][3]){
	int ret,X,Y;
	do{
		system("cls");
		X = rand()%3;
		Y = rand()%3;
		ret  = inserirNaPosicao(posicaoMatriz, X, Y, 'O');
	}while(ret != 0);
}
// Fun��o para verificar se existe um jogador, com todas as possibilidades de Vitoria
char verificaGanhador(char posicaoMatriz[3][3]){
	
	if(posicaoMatriz[0][0] == posicaoMatriz[0][1] && posicaoMatriz[0][1] == posicaoMatriz[0][2])
		return posicaoMatriz[0][0];
	if(posicaoMatriz[1][0] == posicaoMatriz[1][1] && posicaoMatriz[1][1] == posicaoMatriz[1][2])
		return posicaoMatriz[1][0];
	if(posicaoMatriz[2][0] == posicaoMatriz[2][1] && posicaoMatriz[2][1] == posicaoMatriz[2][2])
		return posicaoMatriz[2][0];
	if(posicaoMatriz[0][0] == posicaoMatriz[1][0] && posicaoMatriz[1][0] == posicaoMatriz[2][0])
		return posicaoMatriz[0][0];
	if(posicaoMatriz[0][1] == posicaoMatriz[1][1] && posicaoMatriz[1][1] == posicaoMatriz[2][1])
		return posicaoMatriz[0][1];
	if(posicaoMatriz[0][2] == posicaoMatriz[1][2] && posicaoMatriz[1][2] == posicaoMatriz[2][2])
		return posicaoMatriz[0][2];
	if(posicaoMatriz[0][0] == posicaoMatriz[1][1] && posicaoMatriz[1][1] == posicaoMatriz[2][2])
		return posicaoMatriz[0][0];
	if(posicaoMatriz[0][2] == posicaoMatriz[1][1] && posicaoMatriz[1][1] == posicaoMatriz[2][0])
		return posicaoMatriz[0][2];
	
	return '-';
}
// Fun��o para o modo multiplayer funcionar
void multiPlayer(char posicaoMatriz[3][3]){
	system("cls");
	int velha = 0;
	char vitoria;
	do{
		jogador1(posicaoMatriz);
		vitoria = verificaGanhador(posicaoMatriz);
		if(vitoria == 'X'){
			system("cls");
			printf("\n \tVencedor Jogador 1\n");
			tabuleiro(posicaoMatriz);
			system("pause");
			exit(1);
		}
		
		velha++;
		if(velha == 9){
			system("cls");
			tabuleiro(posicaoMatriz);
			printf("\n \tEmpate. O jogo deu Velha \n");
			system("pause");
			exit(1);
		}
		
		jogador2(posicaoMatriz);
		vitoria = verificaGanhador(posicaoMatriz);
		if(vitoria == 'O'){
			system("cls");
			printf("\n \tVencedor Jogador 2 \n");
			tabuleiro(posicaoMatriz);
			system("pause");
			exit(1);
		}
		velha++;
	}while(velha != 9 || vitoria != 'X' || vitoria != 'O');
	
}
//Fun��o para o modo Singleplayer funcionar
void singlePlayer(char posicaoMatriz[3][3]){
	system("cls");
	int velha = 0;
	char vitoria;
	do{
		jogador1(posicaoMatriz);
		vitoria = verificaGanhador(posicaoMatriz);
		if(vitoria == 'X'){
			system("cls");
			printf("\n \tVencedor Jogador 1\n");
			tabuleiro(posicaoMatriz);
			system("pause");
			exit(1);
		}
		
		velha++;
		if(velha == 9){
			system("cls");
			tabuleiro(posicaoMatriz);
			printf("\n \tEmpate. O jogo deu Velha \n");
			system("pause");
			exit(1);
		}
		
		jogadorPC(posicaoMatriz);
		vitoria = verificaGanhador(posicaoMatriz);
		if(vitoria == 'O'){
			system("cls");
			printf("\n \t A Maquina Venceu \n");
			tabuleiro(posicaoMatriz);
			system("pause");
			exit(1);
		}
		velha++;
	}while(velha != 9 || vitoria != 'X' || vitoria != 'O');
}

// Fun��o para o modo multiplayer do campeonato funcionar
int multiPlayerCamp(char posicaoMatriz[3][3], Jogador *p , int player1, int player2){
	system("cls");
	int velha = 0;
	char vitoria;
	do{
		jogador1(posicaoMatriz);
		vitoria = verificaGanhador(posicaoMatriz);
		if(vitoria == 'X'){
			system("cls");
			printf("\n \tVencedor %s\n", p[player1].nome);
			p[player1].nVitorias = p[player1].nVitorias + 1;
			p[player1].pontos = p[player1].pontos + 3;
			tabuleiro(posicaoMatriz);
			system("pause");
			return 1;
		}
		
		velha++;
		if(velha == 9){
			system("cls");
			tabuleiro(posicaoMatriz);
			printf("\n \tEmpate. O jogo deu Velha \n");
			p[player1].pontos = p[player1].pontos + 1;
			p[player2].pontos = p[player2].pontos + 1;
			system("pause");
			return 1;
		}
		
		jogador2(posicaoMatriz);
		vitoria = verificaGanhador(posicaoMatriz);
		if(vitoria == 'O'){
			system("cls");
			printf("\n \tVencedor %s\n", p[player2].nome);
			p[player2].nVitorias = p[player2].nVitorias + 1;
			p[player2].pontos = p[player2].pontos + 3;
			tabuleiro(posicaoMatriz);
			system("pause");
			return 1;
		}
		velha++;
	}while(velha != 9 || vitoria != 'X' || vitoria != 'O');
}
//Funcao para cadastro dos dados e inicializa��o de variaveis
Jogador cadastro(){
	Jogador player;
	fflush(stdin);
	printf("\nEntre com o nome o jogador: ");
	gets(player.nome);
	player.nVitorias = 0;
	player.pontos = 0;
	return player;
}
//Fun��o para imprimir os elementos dos Players
void imprimirClassificacao(Jogador *p, int i, int colocacao){
	printf("\n %d lugar %s com %d pontos e %d vitorias \n ",colocacao, p[i].nome, p[i].pontos, p[i].nVitorias);
}

//Fun��o recursiva para imprimir a ordem final do campeonato
void classificacaoFinal(Jogador *p, int *lista ,int i, int num, int colocacao){
	if(i<num){
		classificacaoFinal(p , lista,i+1,num, colocacao-1);
		imprimirClassificacao(p ,lista[i],colocacao);	
	}
}
// Fun��o que decorre o campeonato e suas chamadas
void campeonato(char posicaoMatriz[3][3]){
	system("cls");
	Jogador *player;
	int numPlayer, i,j,k, ultimo, passa;
	int menor;
	int result;
	
	printf("Entre com a quantidade e jogadores: ");
	printf("\nNumero minimo sao jogadores 3: ");
	scanf("%d",&numPlayer);
	
	if(numPlayer < 3){
		printf("\n O numero minimo e players sao 3, reinicie o jogo: ");
		exit(0);
	}
	
	int *vetorVencedor, vetorAux[numPlayer];
	vetorVencedor = (int*)malloc(numPlayer*sizeof(int));
	player = (Jogador*)malloc(numPlayer*sizeof(Jogador));
	
	if(player == NULL){
		printf("\n Erro de memoria");
		exit(1);
	}
	
	for(i=0; i<numPlayer; i++){
		player[i] = cadastro();
	}
	ultimo = numPlayer-1;
	for(i=0; i<ultimo; i++){
		k = i+1;
		for(j = k; j<numPlayer; j++){
			system("cls");
			printf("\nJogador1 = %s VS Jogador2 = %s \n", &player[i].nome, &player[j].nome);
			system("pause");
			inicia(posicaoMatriz);
			result = multiPlayerCamp(posicaoMatriz, player,i, j);
			if(result == 1){
				system("cls");
			}
		}
	}
	// vetor auxiliar para orenacao
	for(i=0; i<numPlayer ;i++){
		vetorAux[i] = player[i].pontos;
	}
	
	menor = player[0].pontos + 1; // Para garantir que pelo menos o primeiro numero seja menor e garanta a ordena��o
	for(i=0; i<numPlayer; i++){
		for(j = 0; j<numPlayer; j++){
			if(vetorAux[j] < menor){
				menor = vetorAux[j];
				passa = j;
			}
		}
		vetorVencedor[i] = passa;
		vetorAux[passa] = 9999;
		menor = 9999;
	}
	
	printf("Classificacao Final do Campeonato");
	classificacaoFinal(player,vetorVencedor,0,numPlayer,numPlayer);
	system("pause");
	
}

//Fun��o principal do jogo

int main (){
	char posicaoMatriz[3][3];
	inicia(posicaoMatriz);
	int entrada;
	
	do{
		menu();
		scanf("%d", &entrada);
		switch(entrada){
			case 0:{
				exit(1);
				break;
			}
			case 1:{
				singlePlayer(posicaoMatriz);
				break;
			}
			case 2:{
				multiPlayer(posicaoMatriz);
				break;
			}
			case 3:{
				campeonato(posicaoMatriz);
				break;
			}
			default:{
				printf("Entrada Invalida");
				break;
			}
		}
	
	}while(entrada != 0);
	
	return 0;
}
