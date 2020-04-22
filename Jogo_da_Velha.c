#include<stdio.h>
//importação da biblioteca stdio.h
#define max 3
//todas as palavras max vão ser substituidas na pre-programação pelo valor 3
int linha(char v[max][max]){
	//função responsavel pela análise da linha para identificar se ouve algum ganhador 
	int i=0, x=0, prox = 0;
	//declaração das variáveis inteiras e iniciando as com o valor 0
	char a;
	//declaração da variável do tipo char a
	for ( i = 0; i < max; i++){
		//for de análise das colunas, este é responsável pela mudança das colunas
		//obs: nesse sistema de identificação de vencedores a análise é feita percorendo o tabuleiro
		a = v[i][0];
		//marcação da posição do primeiro elemento de cada linha
		//exemplo 1,0 onde o 1 representa a linha e 0 zero a coluna
		//assim a receberá o caractere da coordenada
		if(a == ' '){
			return 0;
			// caso a receba espaço vazio como caractere ele terminará o programa
		}else{
			//caso a não receba um espaço seguirá os comandos a seguir
			for (x = 0; x < max; x++){
				//for de construção das linhas, este é responsável pela mudança das linhas do tabuleiro
				if(x < max){
					prox = v[i][x+1];
					//se x for menor que 3 a variável prox receberá o caractere do próximo item da linha do tabuleiro
					if (prox == ' '){
						x = 4;
						//se o prox for igual a um espaço vazio x receberá o valor 4 para sair da estrutura for da linha 23
					}else if((x == 2) && (v[i][x] != ' ')){
						return 1;
						//senão se x for igual a 2 e a coordenada for diferente de espaço vazio a função retornará 1
						//que quer dizer que ouve uma linha completa neste caso 
						//pois para x chegar ate 2 os caracteres que estão presente em x = 0 e x= 1 são os mesmos
					}else if((prox != a) && (prox != ' ')){
						x = 4;
						//se prox for diferente de a, que no caso é o primeiro caractere da linha, e diferente de espaço 
						//x receberá 4 para terminar o laço for da linha 4
					}	
				}else{
					//se não o programa continuará normalmente 
				}
			}
		}
	}
}
int coluna(char v[max][max]){
	//função responsável pela análise da coluna para identificar se ouve algum ganhador 
	int i=0, x=0, prox = 0;
	//declaração das variáveis inteiras e inicialização delas com o valor 0
	char a;
	//declaração da variável do tipo char a
	for ( x = 0; x < max; x++){
		//for da análise das linhas, este é responsável pela mudança das linhas
		//durante a construção do tabuleiro 
		a = v[0][x];
		//marcação da posição do primeiro elemento de cada coluna
		//exemplo 0,1 onde o 0 representa linha e o 1 representa a coluna
		//assim a receberá o caractere da coordenada
		if(a == ' '){
			return 0;
			// caso a receba espaço como caractere ele terminará o programa
		}else{
			//caso a não receba um espaço seguirá os comandos a seguir
			for (i = 0; i < max; i++){
				//for de contrução das colunas, este é responsável pela mudança das colunas
				if(i < max){
					prox = v[i+1][x];
					//se i for menor que 3 a variavel prox receberá o caractere do próximo item da coluna
					if (prox == ' '){
						i = 4;
						//se o prox for igual a um espaço vazio i receberá o valor 4 para sair da estrutura for da linha 63
					}else if((i == 2) && (v[i][x] != ' ')){
						return 1;
						//senão se i for igual a 2 e a coordenada for diferente de espaço vazio a função retornará 1
						//que quer dizer que ouve uma coluna completa neste caso 
						//pois para i chegar ate 2 os caracteres que estão presente em i = 0 e i= 1 são os mesmos
					}else if((prox != a) && (prox != ' ')){					
						i = 4;
						//se prox for diferente de a, que no caso é o primeiro caractere da coluna, e diferente de espaço 
						//i recebe 4 para terminar o laço for da linha 63
					}	
				}else{
					//se não o codigo continhua normalmente 
				}
			}
		}
	}
}

int diagonal(char v[max][max]){
	//função responsavel pela análise das diagonais para identificar se ouve algum ganhador 
	char a, b;
	//declaração das variaveis do tipo char a e b
	if (v[0][0] != ' '){
		a = v[0][0];
		//se a coordenada 0,0 for diferente de um espaço vazio 
		//a receberá o caractere da coordenada
	}
	if (v[0][2] != ' '){
		b = v[0][2];
		//se a coordenada 0,2 for diferente de um espaço vazio 
		//a receberá o caractere da coordenada
	}
	if ((v[0][0] == a) && (v[1][1] == a) && (v[2][2]==a)){
		return 1;
		// se as cordenadas 0,0 , 1,1 , 2,2 forem todas iguais a o caractere a função retornatá 1 
	}
	if ((v[0][2] == b) && (v[1][1] == b) && (v[2][0]== b)){
		return 1;
		// se as cordenadas 0,2 , 1,1 , 2,0 forem todas iguais a o caractere b  a função retornatá 1 
	}
}

int velha(char v[max][max]){
	int i, j, x, jogador = 1, controle = 0, resultado_coluna= 0, resultado_linha= 0;
	int resultado_diagonal = 0 ;
	//declaração das variáveis inteiras e iniciação de algumas destas
	char ch;
	//declaração da variavel do tipo char ch
	printf("Jogador 1: x\nJogador 2: O\n");
	//escreverá na tela a mensagem entre parenteses
	for (int j = 0; j < 9; j++){
		//j representa as jogadas, enquanto j for menor que 9 será executado os comandos a seguir
		if(jogador == 1){
			ch = 'X';
			//se jogador for igual a 1 ch receberá X
		}else{
			ch = 'O';
			//senão ch receberá O
		}  
		printf("Digite as cordenadas jogador %d: exemplo: 0,0\n", jogador);
			//escreverá na tela a mensagem entre parenteses
		do{
			i = 0;
			x = 0;
			//inicialização das variaveis i e x
			scanf("%d,%d", &i, &x);
			//recebimento das coordenadas digitadas pelo jogador

		}while(i >2 || i<0 || x >2 || x<0);
		//condição para que as coordenas estejam entre 0 e 2

			
		if (v[i][x] == ' '){	
			v[i][x] = ch;
			//se o caractere da coordenada for igual um espaço vazio ch receberá um espaço vazio
			//para que não ocorra sobreposição de caractere
	
		}
		else{
			printf("\nCordenadas ja ocupada.\n\n");
			//se não aparecerá a mensagem entre parenteses na tela
			j--;
			if (jogador == 1){
				jogador = 2;
				//se jogador for igual a 1 ele recebera o valor 2
				//para mudar o caractere 
			}else{
				jogador = 1;
				//se não jogador receberá 1
			}
		}

		//estutura de construção do tabuleiro
		for ( i = 0; i < max; i++){
			//for das colunas
			for (x = 0; x < max; x++){
				//for de construção das linhas
				printf("%c %c", v[i][x], x==max-1?' ':'|');
				//no primeiro %c será colocado o caractere da cordenada
				//se x for igual a 2 ele colocará espaço vazio se não colocará barra no segundo %c
			}
			if (x != max-1){
				printf("\n----------\n");
				//se x for diferente de 2 vai aparecer a sequencia de traços 
			}	
		}
		resultado_linha = linha(v);
		//chamando a função linha com o vetor v como parametro e atribuindo o seu retorno a variavel resultado_linha
		resultado_coluna = coluna(v);
		//chamando a função coluna com o vetor v como parametro e atribuindo o seu retorno a variavel resultado_coluna
		resultado_diagonal = diagonal(v);
		//chamando a função diagonal com o vetor v como parametro e atribuindo o seu retorno a variavel resultado_diagonal
		if ((resultado_linha == 1 )||(resultado_diagonal == 1)||(resultado_coluna == 1)){
			printf("Fim de jogo, vencedor jogador %d\n", jogador);
			return 0;
			//caso o retourn de uma das funções for 1 a mensagem entre paraenteses sera escrita na tela
			//e exerará a função velha
		}else if (j == 8){
			printf("Ninguem ganho, deu velha\n");
			//senão se o numero de jogadas for igual a 8 será escrita a mensagem entre parenteses
		}

		if(jogador == 1){	
			jogador = 2;
			//se jogador for igual a 1 jogador recebe 2
		}
		else{
			jogador = 1;
			//se não jogador recebe 1
		}
	}
}		

int main()
//função principal
{
	char v[max][max] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	//declaração do vetor dimencional do tipo char v
	velha(v);
	//chamando a função velha com o vetor v como parametro
	return 0;
	//fim do programa
}