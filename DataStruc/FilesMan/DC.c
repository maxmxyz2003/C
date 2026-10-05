#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
  char Name[30];
  int ID;
  int Rarity;
  char Elements[4];
}Dragon;

int insertDragon(char *nFile, Dragon newDragon){
  FILE *fr = fopen(nFile, "ab");
  if (!fr){
    return 0;
  }
  else{
    fwrite(&newDragon, sizeof(Dragon), 1, fr);
    fclose(fr);
    return 1;
  }
}
int DeleteData(char *nFile, int id){
  FILE *fr = fopen(nFile, "rb");
  FILE *fw = fopen("Temp.bin", "ab");
  int res = 0;
  if (!fr || !fw){
    fclose(fr);
    return res;
  }
  else{
    Dragon TempDr;
    while (fread(&TempDr, sizeof(Dragon), 1, fr) == 1){
      if (TempDr.ID != id){
        fwrite(&TempDr, sizeof(Dragon), 1, fw);
      }
      else{
        res = 1;
      }
    }
    fclose(fr);
    fclose(fw);
    remove(nFile);
    rename("Temp.bin", nFile);
    return res;
  }
}
int ReplaceData(char *nFile, int id, Dragon newData){
  FILE *fr = fopen(nFile, "rb");
  FILE *fw = fopen("Temp.bin", "ab");
  int res = 0;
  if (!fr || !fw){
    fclose(fr);
    return res;
  }
  else{
    Dragon TempDr;
    while (fread(&TempDr, sizeof(Dragon), 1, fr) == 1){
      if (TempDr.ID != id){
        fwrite(&TempDr, sizeof(Dragon), 1, fw);
      }
      else{
        fwrite(&newData, sizeof(Dragon), 1, fw);
        res = 1;
      }
    }
    fclose(fr);
    fclose(fw);
    remove(nFile);
    rename("Temp.bin", nFile);
    return res;
  }
}
void Stadisctics(char *nFile, char *Obj){
  FILE *fr = fopen(nFile, "rb");
  if (!fr){
    return;
  }
  else{
    Dragon d;
    while (fread(&d, sizeof(Dragon), 1, fr) == 1){
      if (strcmp(Obj, d.Name) == 0){
        break;
      }
    }
    if (strcmp(Obj, d.Name) == 0){
      int V = 0;
      int Vt = 0;
      int E = 0;
      int D = 0;
      int Dt = 0;
      fseek(fr, 0, SEEK_SET);
      Dragon Temp;
      while (fread(&Temp, sizeof(Dragon), 1, fr) == 1){
        for (int i = 0; i < 4 && d.Elements[i] != '\0'; i++){
          if (Temp.Rarity == d.Rarity){
            if (d.Elements[i] == 'V' && Temp.Elements[0] == 'T'){
              Vt = 1;
            }else if (d.Elements[i] == 't' &&(Temp.Elements[0] == 'R' || Temp.Elements[0] == 'F'))
              Vt = 1;
            else if (d.Elements[i] == 'F' &&(Temp.Elements[0] == 'N' || Temp.Elements[0] == 'H'))
              Vt = 1;
            else if (d.Elements[i] == 'A' &&(Temp.Elements[0] == 'B' || Temp.Elements[0] == 'F'))
              Vt = 1;
            else if (d.Elements[i] == 'N' &&(Temp.Elements[0] == 'l' || Temp.Elements[0] == 'A'))
              Vt = 1;
            else if (d.Elements[i] == 'R' &&(Temp.Elements[0] == 'M' || Temp.Elements[0] == 'A'))
              Vt = 1;
            else if (d.Elements[i] == 'H' &&(Temp.Elements[0] == 'B' || Temp.Elements[0] == 'N'))
              Vt = 1;
            else if (d.Elements[i] == 'M' && (Temp.Elements[0] == 't' || Temp.Elements[0] == 'H'))
              Vt = 1;        
            else if (d.Elements[i] == 'B' &&(Temp.Elements[0] == 't' || Temp.Elements[0] == 'O'))  
              Vt = 1;
            else if (d.Elements[i] == 'O' &&(Temp.Elements[0] == 'l' || Temp.Elements[0] == 'M'))
              Vt = 1;
            else if (d.Elements[i] == 'l' &&(Temp.Elements[0] == 'O' || Temp.Elements[0] == 'R'))
              Vt = 1;
            else if (d.Elements[i] == 'P' && Temp.Elements[0] == 'V')
              Vt = 1;
            else if (d.Elements[i] == 'p' && Temp.Elements[0] == 'P')
              Vt = 1;
            else if (d.Elements[i] == 'L' && Temp.Elements[0] == 'p')
              Vt = 1;
            else if (d.Elements[i] == 'T' && Temp.Elements[0] == 'L')
              Vt = 1;
            else if (d.Elements[i] == 'f' &&(Temp.Elements[0] == 'c' || Temp.Elements[0] == 'm'))
              Vt = 1;
            else if (d.Elements[i] == 'c' &&(Temp.Elements[0] == 'm' || Temp.Elements[0] == 'a'))
              Vt = 1;
            else if (d.Elements[i] == 'm' &&(Temp.Elements[0] == 'a' || Temp.Elements[0] == 'b'))
              Vt = 1;
            else if (d.Elements[i] == 'a' &&(Temp.Elements[0] == 's' || Temp.Elements[0] == 'b'))
              Vt = 1;
            else if (d.Elements[i] == 'b' &&(Temp.Elements[0] == 's' || Temp.Elements[0] == 'f'))
              Vt = 1;
            else if (d.Elements[i] == 's' &&(Temp.Elements[0] == 'f' || Temp.Elements[0] == 'c'))
              Vt = 1;
            else
              continue;  
          } // fin if rareza
        }   // fin for verifica Superioridad
        for (int i = 0; i < 4 && Temp.Elements[i] != '\0'; i++){
          if (Temp.Rarity == d.Rarity){
            if (Temp.Elements[i] == 'V' && d.Elements[0] == 'T')
              Dt = 1;
            else if (Temp.Elements[i] == 't' &&(d.Elements[0] == 'R' || d.Elements[0] == 'F'))
              Dt = 1;
            else if (Temp.Elements[i] == 'F' &&(d.Elements[0] == 'N' || d.Elements[0] == 'H'))
              Dt=1;
            else if (Temp.Elements[i] == 'A' &&(d.Elements[0] == 'B' || d.Elements[0] == 'F'))
              Dt=1;
            else if (Temp.Elements[i] == 'N' &&(d.Elements[0] == 'l' || d.Elements[0] == 'A'))
              Dt = 1;
            else if (Temp.Elements[i] == 'R' &&(d.Elements[0] == 'M' || d.Elements[0] == 'A'))
              Dt = 1;
            else if (Temp.Elements[i] == 'H' &&(d.Elements[0] == 'B' || d.Elements[0] == 'N'))
              Dt = 1;
            else if (Temp.Elements[i] == 'M' &&(d.Elements[0] == 't' || d.Elements[0] == 'H'))
              Dt = 1;
            else if (Temp.Elements[i] == 'B' &&(d.Elements[0] == 't' || d.Elements[0] == 'O'))
              Dt = 1;
            else if (Temp.Elements[i] == 'O' &&(d.Elements[0] == 'l' || d.Elements[0] == 'M'))
              Dt = 1;
            else if (Temp.Elements[i] == 'l' &&(d.Elements[0] == 'O' || d.Elements[0] == 'R'))
              Dt = 1;
            else if (Temp.Elements[i] == 'P' && d.Elements[0] == 'V')
              Dt = 1;
            else if (Temp.Elements[i] == 'p' && d.Elements[0] == 'P')
              Dt = 1;
            else if (Temp.Elements[i] == 'L' && d.Elements[0] == 'p')
              Dt = 1;
            else if (Temp.Elements[i] == 'T' && d.Elements[0] == 'L')
              Dt = 1;
            else if (Temp.Elements[i] == 'f' &&(d.Elements[0] == 'c' || d.Elements[0] == 'm'))
              Dt = 1;
            else if (Temp.Elements[i] == 'c' &&(d.Elements[0] == 'm' || d.Elements[0] == 'a'))
              Dt = 1;
            else if (Temp.Elements[i] == 'm' &&(d.Elements[0] == 'a' || d.Elements[0] == 'b'))
              Dt = 1;
            else if (Temp.Elements[i] == 'a' &&(d.Elements[0] == 's' || d.Elements[0] == 'b'))
              Dt = 1;
            else if (Temp.Elements[i] == 'b' &&(d.Elements[0] == 's' || d.Elements[0] == 'f'))
              Dt = 1;
            else if (Temp.Elements[i] == 's' &&(d.Elements[0] == 'f' || d.Elements[0] == 'c'))
              Dt = 1;
            else
              continue;
          }
        }
        if (Vt == Dt)
          E++;
        else if (Vt > Dt)
          V++;
        else if (Vt < Dt)
          D++;
        
        //Restart the flags
        Vt = 0;
        Dt = 0;
      } // fin while
      printf("\n-----\n%s{\nVictories:%d\nDefeats:%d\nDraws:%d\n}\n", Obj, V, D,E);
    }else
      printf("\nNot found '%s'\n", Obj);
    fclose(fr);
    return;
  }
}
void FilterDataByElem(char *nFile, char Elemmt){
  FILE *fr = fopen(nFile, "rb");
  if (!fr){
    fclose(fr);
    return;
  }
  else{
    Dragon TempDr;
    while (fread(&TempDr, sizeof(Dragon), 1, fr) == 1){
      for (int i = 0; i < 4 && TempDr.Elements[i] != '\0'; i++){
        if (TempDr.Elements[i] == Elemmt){
          printf("%s\t%d\t%d\t%s\n", TempDr.Name, TempDr.ID, TempDr.Rarity,TempDr.Elements);
        }
      }
    }
    fclose(fr);
    return;
  }
}
void FilterDataByRar(char *nFile, int Rar){
  FILE *fr = fopen(nFile, "rb");
  if (!fr){
    fclose(fr);
    return;
  }else{
    Dragon TempDr;
    while (fread(&TempDr, sizeof(Dragon), 1, fr) == 1){
      if (TempDr.Rarity == Rar){
        printf("%s\t%d\t%d\t%s\n", TempDr.Name, TempDr.ID, TempDr.Rarity,TempDr.Elements);
      }
    }
    fclose(fr);
    return;
  }
}
void PrintData(char *nFile){
  FILE *fr = fopen(nFile, "rb");
  if (!fr){
    fclose(fr);
    return;
  }else{
    Dragon TempDr;
    printf("| Name | ID | Rarity| Elements| \n");
    while (fread(&TempDr, sizeof(Dragon), 1, fr) == 1){
      printf("%s\t%d\t%d\t%s\n", TempDr.Name, TempDr.ID, TempDr.Rarity,TempDr.Elements);
    }
    fclose(fr);
    return;
  }
}

int main(void){
  Dragon TempDr;
  int xd = 1; // Change this to the number of dragons you want to input
  int end = 0;
  int opt;
  int *ptr;
  int optFilter = 0;
  while (!end){
    printf("What do you wan to do?\n(0)Print data\n(1)Insert Dragon\n(2)Specific Dragon Stadistics\n(3)Replace Data\n(4) Filter Data\n(5) Delete Data\n");
    scanf("%d", &opt);
    switch (opt){
    case 0:
      PrintData("Dragons.bin");
      printf("\n");
      break;
    case 1:
      printf("Enter dragon name: ");
      scanf("%s", TempDr.Name);
      printf("Enter dragon ID: ");
      scanf("%d", &TempDr.ID);
      printf("Enter dragon rarity: ");
      scanf("%d", &TempDr.Rarity);
      printf("Enter dragon element: ");
      scanf("%s", TempDr.Elements);
      if (insertDragon("Dragons.bin", TempDr)){
        printf("Success\n");
      }
      break;
    case 2:
      printf("Enter dragon's name: ");
      scanf("%s", TempDr.Name);
      Stadisctics("Dragons.bin", TempDr.Name);
      break;
    case 3:
      printf("Enter dragon's ID: ");
      scanf("%d", &TempDr.ID);
      printf("Enter dragon new name: ");
      scanf("%s", TempDr.Name);
      printf("Enter dragon new rarity: ");
      scanf("%d", &TempDr.Rarity);
      printf("Enter dragon new elements: ");
      scanf("%s", TempDr.Elements);
      ReplaceData("Dragons.bin", TempDr.ID, TempDr);
      break;
    case 4:
      printf("By Element(0)\nRarity(1)\n");
      scanf("%d", &optFilter);
      if (optFilter == 0){
        printf("Select element(s): ");
        scanf("%s", TempDr.Elements);
      }
      else if (optFilter == 1){
        printf("Select rarity: ");
        scanf("%d", &TempDr.Rarity);
        FilterDataByRar("Dragons.bin", TempDr.Rarity);
      }
      break;
    case 5:
      printf("Enter dragon's ID: ");
      scanf("%d", &TempDr.ID);
      DeleteData("Dragons.bin", TempDr.ID);
      break;
    default:
      printf("Not valid \n");
      break;
    }
    printf("End? ");
    scanf("%d", &end);
  }
  return 0;
}
