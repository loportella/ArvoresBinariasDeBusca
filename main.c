#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"
int main(int argc, char *argv[]) {
	arv a;
	int op,val;
	do{
printf("MENU:\n1-Criar\n2-Inserir\n3-Excluir\n4-Mostrar\n5-Altura\n6-Liberar\n0-Fechar \t");
		scanf("%d",&op);
		switch(op){
			case 1:a=cria();break;
			case 2:;val=dados();
			a=ins(a,val);break;
			case 3:
			printf("Exclui: ");scanf("%d",&val);
			a=remo(a,val);break;
			case 4:
			printf("Pre-fixada a esquerda:\n");prefes(a);
			printf("\nCentral a esquerda:\n");cenesq(a);
			printf("\nPos-fixada a esquerda:\n");posfes(a);
			printf("\n");break;
			case 5: printf("Altura %d\n",altura(a));break;
			case 6:a=libera(a);break;
			default: printf("Opcao invalida\n");break;
		}
	}while(op!=0);
	system("pause");return 0;
}
