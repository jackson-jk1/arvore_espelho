#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define espaco 10
 
/* Estrutura de um nó, com o valor do nó e 
	um ponteiro para o nó da esquerda e outro para o da direitateita */
struct Node
{
    int valor;
    Node* esquerda, *direita;
};

/* Aloca memória para um novo nó */
Node * novoNode(int valor)
{
    Node* node = new Node;
    node->valor  = valor;
    node->esquerda  =  node->direita  = NULL;
    return(node);
}
 
/* Dado duas árvores, retorna 1 caso sejam iguais, 0 caso contrário*/
int eh_espelho(Node* arvoreA, Node* arvoreB)
{
    /* Caso base : ambas vazias */
    if (arvoreA == NULL && arvoreB == NULL)
        return 1;
 
    // Apenas uma é vazia
    if (arvoreA == NULL || arvoreB == NULL)
        return 0;
 
    /* Ambas não vazias, comparação entre elas recursivamente
     Alternando o valor da esquerda e direita entre eles */
    return  arvoreA->valor == arvoreB->valor &&
            eh_espelho(arvoreA->esquerda, arvoreB->direita) &&
            eh_espelho(arvoreA->direita, arvoreB->esquerda);
}

/* Dado duas árvores, retorna 1 caso sejam iguais, 0 caso contrário*/
Node * cria_espelho(Node* arvore)
{
	if (arvore == NULL) {
        Node *raiz = NULL;
        return raiz;
    }
	
    Node *raiz = novoNode(arvore->valor);
    
    if(arvore->esquerda != NULL){
    	raiz->direita = cria_espelho(arvore->esquerda);
	}
	if(arvore->direita != NULL){
    	raiz->esquerda = cria_espelho(arvore->direita);
	}	
	return raiz;
}

 void desenha_arvore_horiz(Node *arvore, int depth, char *path, int direita)
{
   
    if (arvore== NULL)
        return;

  
    depth++;

   
    desenha_arvore_horiz(arvore->direita, depth, path, 1);


    path[depth-2] = 0;

    if(direita)
        path[depth-2] = 1;

    if(arvore->esquerda)
        path[depth-1] = 1;

    printf("\n");

    for(int i=0; i<depth-1; i++)
    {
      if(i == depth-2)
          printf("+");
      else if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
      if(i < depth-2)
          printf(" ");
      else
          printf("-");
    }

    printf("%d\n", arvore->valor);


    for(int i=0; i<depth; i++)
    {
      if(path[i])
          printf("|");
      else
          printf(" ");

      for(int j=1; j<espaco; j++)
          printf(" ");
    }

    
    desenha_arvore_horiz(arvore->esquerda, depth, path, 0);
}

void draw_arvore_hor(Node *arvore)
{
  
    char path[255] = {};

   
    desenha_arvore_horiz(arvore, 0, path, 0);
}
 
int main()
{
    Node *raiz1 = novoNode(25);
    Node *raiz2 = novoNode(25);						
    raiz1->esquerda = novoNode(36);					
    raiz1->direita = novoNode(20);	

    raiz1->direita->esquerda  = novoNode(22);		
    raiz1->direita->direita = novoNode(10);	

    raiz1->esquerda->direita = novoNode(30);	
    raiz1->esquerda->esquerda = novoNode(40);

    raiz1->esquerda->direita->direita = novoNode(28);	
    raiz1->esquerda->esquerda->esquerda = novoNode(48);
    raiz1->esquerda->esquerda->direita = novoNode(38);

    raiz1->esquerda->esquerda->esquerda->direita = novoNode(45);
    raiz1->esquerda->esquerda->esquerda->esquerda = novoNode(50);
    
    raiz1->direita->direita->direita = novoNode(5);
    raiz1->direita->direita->direita->direita = novoNode(1);
    raiz1->direita->direita->direita->esquerda = novoNode(8);
    raiz1->direita->direita->esquerda = novoNode(12);	
    raiz1->direita->direita->esquerda->esquerda = novoNode(15);		
    
 							
    raiz2->esquerda = novoNode(20);				
    raiz2->direita = novoNode(36);	

    raiz2->esquerda->esquerda = novoNode(10);	
    raiz2->esquerda->direita = novoNode(22);

    raiz2->direita->direita = novoNode(40);	
    raiz2->direita->esquerda = novoNode(30);	

    raiz2->direita->direita->direita = novoNode(48);	
    raiz2->direita->esquerda->esquerda = novoNode(28);	
    raiz2->direita->direita->esquerda= novoNode(38);

    raiz2->direita->direita->direita->direita = novoNode(50);
    raiz2->direita->direita->direita->esquerda = novoNode(45);	  

    raiz2->esquerda->esquerda->direita = novoNode(12);
    raiz2->esquerda->esquerda->direita->direita = novoNode(15);
    raiz2->esquerda->esquerda->esquerda = novoNode(5);
    raiz2->esquerda->esquerda->esquerda->direita = novoNode(8);	
    raiz2->esquerda->esquerda->esquerda->esquerda = novoNode(1);		 	  		
 	
 	int retorno = eh_espelho(raiz1, raiz2);
 	printf("O retorno da funcao eh_espelho eh : ");
 	printf("%d", retorno);
 
 	printf("\n----------------------------\n");
 
 	Node *espelho = cria_espelho(raiz1);
 	printf("O retorno da arvore eh_espelho:\n");
 	draw_arvore_hor(espelho);
    return 0;
}
