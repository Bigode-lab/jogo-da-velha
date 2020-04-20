#include<stdio.h>
#define max 3
int linha(char v[max][max]){
	int i=0, x=0, prox = 0;
	char a;
	for ( i = 0; i < max; i++){
		a = v[i][0];
		if(a == ' '){
			return 0;
		}else{
			for (x = 0; x < max; x++){
				if(x < max){
					prox = v[i][x+1];
					if (prox == ' '){
						x = 4;
					}else if((x == 2) && (v[i][x] != ' ')){
						return 1;
					}else if((prox != a) && (prox != ' ')){
						x = 4;
					}	
				}else{
				}
			}
		}
	}
}
int coluna(char v[max][max]){
	int i=0, x=0, prox = 0;
	char a;
	for ( x = 0; x < max; x++){
		a = v[0][x];
		if(a == ' '){
			return 0;
		}else{
			for (i = 0; i < max; i++){
				if(i < max){
					prox = v[i+1][x];
					if (prox == ' '){
						i = 4;
					}else if((i == 2) && (v[i][x] != ' ')){
						return 1;
					}else if((prox != a) && (prox != ' ')){					
						i = 4;
					}	
				}else{
				}
			}
		}
	}
}

int diagonal(char v[max][max]){
	char a, b;
	if (v[0][0] != ' '){
		a = v[0][0];
	}
	if (v[0][2] != ' '){
		b = v[0][2];
	}
	if ((v[0][0] == a) && (v[1][1] == a) && (v[2][2]==a)){
		return 1;
	}
	if ((v[0][2] == b) && (v[1][1] == b) && (v[2][0]== b)){
		return 1;
	}
}

//função velha esta correta, não a erro
int velha(char v[max][max]){
	int i, j, x, jogador = 1, controle = 0, resultado_coluna= 0, resultado_linha= 0;
	int resultado_diagonal = 0 ;
	char ch;
	printf("jogador 1: x\njogador 2: O\n");
	for (int j = 0; j < 9; j++){

		if(jogador == 1){
			ch = 'X';
		}else{
			ch = 'O';
		}  
		printf("digite as cordenadas jogador %d:\n", jogador);
		
		do{
			i = 0;
			x = 0;
			scanf("%d,%d", &i, &x);
		}while(i >2 || i<0 || x >2 || x<0);

			
		if (v[i][x] == ' '){	
			v[i][x] = ch;
	
		}
		else{
			printf("\nCordenadas ja ocupada.\n\n");
	
			j--;
			if (jogador == 1){
				jogador = 2;
			}else{
				jogador = 1;
			}
		}

		for ( i = 0; i < max; i++){
			for (x = 0; x < max; x++){
				printf("%c %c", v[i][x], x==max-1?' ':'|');
			}
			if (x != max-1){
				printf("\n----------\n");
			}	
		}
		resultado_linha = linha(v);
		resultado_coluna = coluna(v);
		resultado_diagonal = diagonal(v);
		if ((resultado_linha == 1 )||(resultado_diagonal == 1)||(resultado_coluna == 1)){
			printf("fim de jogo, vencedor jogador %d\n", jogador);
			return 0;
		}else if (j == 8){
			printf("ninguem ganho, deu velha\n");
		}
		printf("%d\n", j);	
		if(jogador == 1){	
			jogador = 2;
		}
		else{
			jogador = 1;
		}
	}
}		

int main()
{
	char v[max][max] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
	velha(v);
	return 0;
}