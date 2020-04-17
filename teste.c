#include<stdio.h>
#define max 3
//o programa não esta aceitando fim quando se completa uma liha com um unico caracter presente
//ou seja nao a vencedores ele continua executando o codigo ate o fim
int resultado_linha(char v[max][max]){
	int i=0, x=0, prox = 0;
	char a;
	for ( i = 0; i < max; i++){
		
		a = v[i][0];
		printf("aqui 0 x: %d\n", x);
		if(a == ' '){
			return 0;
		}else{

			for (x = 0; x < max; x++){
				printf("aqui 1 x: %d\n", x);
				printf("aqui 1 i: %d\n", i);
				
				if(x+1 < max){
					printf("aqui 2 x: %d\n", x);
					printf("aqui 2 i: %d\n", i);
					prox = v[i][x+1]; 
				
					if((prox != a) && (prox != ' ')){
						
						printf("nao e a linha horizontal\n");
						x = 4;
						printf("aqui 3 x: %d\n", x);
					}else if((x == 2) && (v[i][x] != ' ')){
						printf("aqui 4 x: %d\n", x);
						return 1;
					}else{
						return 0;
					}
				}
			}
		}
	}
}
//função velha esta correta não a erro
int velha(char v[max][max]){
	int i, j, x, jogador = 1, controle =0, resultado=0;
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
		resultado = resultado_linha(v);
		if (resultado == 1){
			printf("fim de jogo, vencedor jogador %d\n", jogador);
			return 0;
		}

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