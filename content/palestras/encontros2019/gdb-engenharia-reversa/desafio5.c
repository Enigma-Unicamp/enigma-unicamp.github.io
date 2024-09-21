#include<stdio.h>
//#include<stdbool.h>
#include<string.h>

#define TAM 32
#define PASS "]TRj0"
int offsets[] = {6, 20, 15, 12, 53};

void try_to_login(char *password) {
    for (int i = 0; i < strlen(password); i++) {
      password[i] -= offsets[i];
    }
    if (strcmp(password,PASS)==0)
      puts ("ACCESS GRANTED!");
    else
      puts ("Access Denied!");
};

int main(int argc, char const *argv[]) {

  printf("Password:\n");
  char password[TAM];
  scanf(" %s", password);

  try_to_login(password);
  return 0;
}
