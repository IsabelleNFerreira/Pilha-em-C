// PILHA

#include <stdio.h>
#include <locale.h>
#define VETOR 10 		  // limite do tamanho do vetor

int pilha[VETOR];
int P_ini = 0, P_fim = 0;  		 // começa com 0 pois nada foi digitado ainda

void imprimir(int pilha[VETOR]){
	int x;
	for(x=P_fim; x>P_ini; x--){
		printf(" %d\n", pilha[x-1]); 		 // os elementos do vetor serão impressos do ultimo para o primeiro
	}
}

int pilha_cheia(){
	return (P_fim == VETOR);		  // verifica se a posição final ocupada é igual o tamanho limite do VETOR, 10
}

int pilha_vazia(){
	return (P_ini == P_fim); 	 // verifica se o fim é 0, igual o inicio
}

void inclusao (int x){
	if(!pilha_cheia()){  	 // verifica se o final do vetor ainda não é 10, ou seja, não está cheia
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
	printf("  > Você pode escolher se quer incluir ou excluir o elemento\n");
	printf("  > É possível ver os numeros armazenados depois de cada ação\n");
	do{
		printf("\n >> Digite a opção desejada: \n");
		printf("\n > 1 - INCLUIR");
    	printf("\n > 2 - EXCLUIR");
   		printf("\n > 3 - SAIR: ");  // menu de controle
    	scanf("%d", &opcao);
    	
    	switch(opcao)
    	{
    		case 1:   			// se a escolha foi incluir
    			if(!pilha_cheia()){    
    			printf("Digite um número: ");
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
    				printf("\nNúmero excluído: %d\n", exclusao());   
    				if(P_fim != P_ini){    				 // só será exibido quando houver elementos na pilha
    				printf("\n................................");
    				printf("\n > Elementos registrados <\n");
    				imprimir(pilha);
    				printf("................................\n");	
    			}
				}
				else{
					printf("\n\n !! PILHA VAZIA !!\n\n");   // se não tiver, exibe a mensagem
				}
		}
    }
	while(opcao != 3);   		 // looping até o usuario escolher sair
	printf("Saindo...\n");
	return 0;
}
