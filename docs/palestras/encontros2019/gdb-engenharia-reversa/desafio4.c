#include<stdio.h>
#include <stdbool.h>
#include<string.h>

#define TAM 32
char key[] = "g`_";
int offsets[] = {6, -47, -30};

int main(int argc, char const *argv[]) {

  printf("Password:\n");
  char password[TAM];
  scanf(" %s", password);

  for (int i = 0; i < 4; i++) {
    if (password[i] != key[i]+offsets[i]) {
      printf("Access Denied\n");
      return 0;
    }
  }

  printf("ACCESS GRANTED\n");
  return 0;
}
