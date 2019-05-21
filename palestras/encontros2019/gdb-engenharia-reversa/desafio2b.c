#include<stdio.h>
//#include<stdbool.h>
#include<string.h>

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

  if (strcmp(password,key)!=0) {
    puts("Access Denied!");
  } else {
    puts("ACCESS GRANTED!");
  }
  return 0;
}
