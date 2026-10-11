#include <stdio.h>
#include <stdbool.h>
bool isSubset(int set1[], int size1, int set2[], int size2) {
    for (int i = 0; i < size1; i++) {
        bool found = false;
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                found = true;
                break;
            }
        }
        if(!found){
            return false;
        }
    }
    return true;
}
bool isEqual(int set1[], int size1, int set2[], int size2) {
    if (size1 != size2)
        return false;
    for (int i = 0; i < size1; i++) {
        bool found = false;
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                found = true;
                break;
            }
        }
        if (!found)
            return false;
    }
    return true;
}

bool isDifferent(int set1[], int size1, int set2[], int size2) {
    return !(isSubset(set1, size1, set2, size2) || isSubset(set2, size2, set1, size1));
}
bool isUpperset(int set1[], int size1, int set2[], int size2) {
    return isSubset(set2, size2, set1, size1);
}
void compareSets(int sets[][100], int setSizes[], int numSets) {
    for (int i = 0; i < numSets; i++) {
        for (int j = i + 1; j < numSets; j++) {
            if (isEqual(sets[i], setSizes[i], sets[j], setSizes[j])) {
                //printf("Set %d is equal to set %d\n", i, j);
                printf("%c = %c\n", 65+i, 65+j); 
            } else if (isSubset(sets[i], setSizes[i], sets[j], setSizes[j])) {
                //printf("Set %d is a subset of set %d\n", i, j);
                printf("%c < %c\n", 65+i, 65+j);
            } else if (isUpperset(sets[i], setSizes[i], sets[j], setSizes[j])) {
                //printf("Set %d is an upperset of set %d\n", i, j);
                printf("%c > %c\n", 65+i, 65+j);
            } else if (isDifferent(sets[i], setSizes[i], sets[j], setSizes[j])) {
                //printf("Set %d is different from set %d\n", i, j);
                printf("%c != %c\n", 65+i, 65+j);
            }
        }
    }
}
int main() {
    int sets[][100] = {
        {1, 3, 2},
        {1, 4, 2, 3},
        {1, 0},
        {1, 2, 3}
    };
    int setSizes[] = {3, 4, 2, 3};
    int numSets = sizeof(setSizes) / sizeof(setSizes[0]);
    compareSets(sets, setSizes, numSets);
    return 0;
}
