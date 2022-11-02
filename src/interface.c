#include "server.h"
#include <stdio.h>
int main(int argc, char *argv[]) {
  int painLevel;
  painLevel = 0;
  int check_status;
  check_status = checks();
  if (check_status == 1) {
    printf("Checks were failed");
    return 1;
  }
  printf("Hello");
  return 0;
}
