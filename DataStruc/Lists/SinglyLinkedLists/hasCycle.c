#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct nodo2{
    int dato;
    struct nodo2 * sig;    
}* NODO2;
typedef struct list{
    NODO2 head;
}* LIST;
NODO2 insert(NODO2 cab, int Ndato){
    NODO2 nuevo=(NODO2)malloc(sizeof(struct nodo2));
    if (!nuevo)
    {
        exit(1);
    }

}
int hasCycle(NODO2 cab){
    NODO2 slow = cab;
    NODO2 fast = cab->sig;
    while (fast && fast->sig) {
        if (slow == fast)
            return 1;
        slow = slow->sig;
        fast = fast->sig->sig;
    }
    return 0;
}
void detectCycleDetails(NODO2 cab, int *startOfCycle, int *cycleLength) {
    NODO2 slow = cab;
    NODO2 fast = cab->sig;
    while (fast && fast->sig) {
        if (slow == fast){
            // Cycle detected, find the start and length
            slow = cab;
            int length = 0;
            while (slow != fast) {
                slow = slow->sig;
                fast = fast->sig;
                length++;
            }
            *startOfCycle = slow->dato;
            *cycleLength = length;
            return;
        }
        slow = slow->sig;
        fast = fast->sig->sig;
    }
    // If no cycle
    *startOfCycle = -1;
    *cycleLength = 0;
}
