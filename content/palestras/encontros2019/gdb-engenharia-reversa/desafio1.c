#include<stdio.h>
//#include <stdbool.h>
#include<string.h>

#define TAM 9
#define KEY "senharuim"

int main(int argc, char const *argv[]) {

  printf("Password:\n");
  char password[TAM];
  scanf(" %s", password);

  if (strcmp(password,KEY)==0) {
      puts("ACCESS GRANTED!");
  } else {
      puts("Access Denied!");
  }
  return 0;
}
