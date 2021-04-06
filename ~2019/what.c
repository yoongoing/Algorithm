#include <stdio.h>
#include <string.h>
/// record = 동물소리 전채
/// animal = 그냥 스캔받을 동물소리 
/// animal_save1 = 스캔받은 동물소리 배열로 저장(something goes something)
/// animal_save2 = 동물소리만 저장해놓기
int main(){
  int Testcase;
  int t,i,num = 0;
  int count = 0;
  char record[100001] = {0};
  char animal;
  char animal_save1[10000] = {0};
  char animal_save2[10000] = {0};
  scanf("%d",&Testcase);
  getchar();
  gets(record);
  while((animal = getchar())!= '?'){
    animal_save1[num] = animal;
    if(animal == '\n'){
      animal_save1[num] = ' ';
    }
    ++num;
  }
  int length1 = strlen(record);
  int length2 = strlen(animal_save1);
  int num2 = 0;
  for(i=0; i<length2; i++){
    if(animal_save1[i] == 'w'){
      if(animal_save1[i+1] == 'h'){
        if(animal_save1[i+2] == 'a'){
          if(animal_save1[i+3] == 't'){
            if(animal_save1[i+4] == ' '){
              break;
            }
          }
        }
      }
    }
    if(count == 2){
      count = 0;
      while (animal_save1[i] != ' '){
        animal_save2[num2] = animal_save1[i];
        num2++;
        i++;
      }
    }
    else if(animal_save1[i] == ' '){
      count++;
      animal_save2[num2++] = ' ';
    }
  }
  printf("%s\n",animal_save2);
}