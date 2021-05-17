// PILHA

#include <stdio.h>
#include <locale.h>
#define VETOR 10 		  // limite do tamanho do vetor

int pilha[VETOR];
int P_ini = 0, P_fim = 0;  		 // come�a com 0 pois nada foi digitado ainda

void imprimir(int pilha[VETOR]){
	int x;
	for(x=P_fim; x>P_ini; x--){
		printf(" %d\n", pilha[x-1]); 		 // os elementos do vetor ser�o impressos do ultimo para o primeiro
	}
}

int pilha_cheia(){
	return (P_fim == VETOR);		  // verifica se a posi��o final ocupada � igual o tamanho limite do VETOR, 10
}

int pilha_vazia(){
	return (P_ini == P_fim); 	 // verifica se o fim � 0, igual o inicio
}

void inclusao (int x){
	if(!pilha_cheia()){  	 // verifica se o final do vetor ainda n�o � 10, ou seja, n�o est� cheia
		pilha[P_fim++] = x; 
	}
}

int exclusao (){
	int aux;
	if(!pilha_vazia()){
		aux = pilha[P_fim-1];
		P_fim--;
		return aux; 		// a aux retorna no main o numero que foi excluido
	}
}

main(){
	setlocale(LC_ALL, "");
	int opcao, numero;
	printf("\n*~*~* Processo para registrar uma pilha *~*~*\n");
	printf("  > Essa pilha tem a capacidade de 10 numeros\n");
	printf("  > Voc� pode escolher se quer incluir ou excluir o elemento\n");
	printf("  > � poss�vel ver os numeros armazenados depois de cada a��o\n");
	do{
		printf("\n >> Digite a op��o desejada: \n");
		printf("\n > 1 - INCLUIR");
    	printf("\n > 2 - EXCLUIR");
   		printf("\n > 3 - SAIR: ");  // menu de controle
    	scanf("%d", &opcao);
    	
    	switch(opcao)
    	{
    		case 1:   			// se a escolha foi incluir
    			if(!pilha_cheia()){    
    			printf("Digite um n�mero: ");
    			scanf("%d", &numero);
    			inclusao(numero);
    			printf("\n................................");
    			printf("\n > Elementos registrados <\n");
    			imprimir(pilha);
    			printf("................................\n");
    			}
    			else{
    			printf("\n\n !! PILHA CHEIA !!\n\n");   // se pilha estiver cheia, exibe a mensagem
    			}
    			break;
    		case 2:  				 // se a escolha foi excluir
    			if(!pilha_vazia()){
    				printf("\nN�mero exclu�do: %d\n", exclusao());   
    				if(P_fim != P_ini){    				 // s� ser� exibido quando houver elementos na pilha
    				printf("\n................................");
    				printf("\n > Elementos registrados <\n");
    				imprimir(pilha);
    				printf("................................\n");	
    			}
				}
				else{
					printf("\n\n !! PILHA VAZIA !!\n\n");   // se n�o tiver, exibe a mensagem
				}
		}
    }
	while(opcao != 3);   		 // looping at� o usuario escolher sair
	printf("Saindo...\n");
	return 0;
}
