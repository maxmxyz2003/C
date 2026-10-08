#include <stdio.h>
#include <stdlib.h>
typedef int TipoDato;
typedef struct nSub {
    TipoDato info;
    struct nSub* sig;  // Corrected the struct name here
}*  SUB;
typedef struct prin {
    TipoDato id;
    struct prin* sig;
    SUB cabSub;
}* Principal;
int creaNSub(SUB n, int num){
    SUB nuevo=(SUB)malloc(sizeof(struct nSub));
    if (nuevo){
        nuevo->info=num;
        nuevo->sig=NULL;
    }else{return 0;}        
    if (!n){
        n=nuevo;
        return 1;
    }else{
        SUB aux=n;
        while (aux->sig)
        {
            aux=aux->sig;
        }
        aux->sig=nuevo;
    }
}
int creaNPrin(Principal cabP, int id, int primer){
    Principal nueva=(Principal)malloc(sizeof(struct prin));
    if (nueva)
    {
        nueva->sig=NULL;
        nueva->id=id;
    }else{return 0;}
    int opc=1, temp;
    while (opc){
        scanf("%d", &temp);
        int xd=creaNSub(nueva->cabSub, temp);
        if(xd){
            printf("Otro?\n");
            scanf("%d", &opc);
        }
    }
    if(!cabP){
        cabP=nueva;
        return 1;
    }else{
        Principal auxP=cabP;
        while (auxP->sig)
        {
            auxP=auxP->sig;
        }auxP->sig=nueva;
        return 1;
    }
}
void imprimeLoL(Principal cab){
    Principal auxP=cab;
    while (auxP){
        printf("Id: %d\n", auxP->id);
        printf("Elementos \n");
        SUB auxTemp=cab->cabSub;
        while (auxTemp)
        {
            printf("%d ", auxTemp->info);
            auxTemp=auxTemp->sig;
        }
        auxP=auxP->sig;
    }
}
