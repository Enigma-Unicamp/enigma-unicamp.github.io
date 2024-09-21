#include<stdio.h>

void restricted_access() {
  puts ("ACCESS GRANTED!");
};

int main(int argc, char const *argv[]) {
  puts ("Access Denied!");
  return 0;
}
