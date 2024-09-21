#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define TAM 100
char key[] = "oajd]laooei]";
int offset = -4;

int main(int argc, char const *argv[]) {
  char password[TAM];

  printf("Password:\n");
  scanf(" %s", password);

  for (int i = 0; i < 12; i++) {
    password[i] += offset;
  }

  // gerador de numero aleatorio de 0 a 2
  time_t t;
  int seed = (int) time(&t);
  srand(seed);
  int num_aleatorio = rand()%3;

  if (strcmp(password,key)!=0 && num_aleatorio == 0) {
    printf("Access Denied!\nMuitos if's nesse código!\n");
  } else if (strcmp(password,key)!=0 && num_aleatorio != 0) {
    printf("Access Denied!\nQual é o trecho correto?\n");
  } else {
    puts("ACCESS GRANTED!");
  }
  return 0;
}
