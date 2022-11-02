#include "server.h"
#include <stdio.h>
#include <unistd.h>
int checks() {
  // checks if the user is running as themselves (ex: not root)
  int user = getuid();
  int user_priv = geteuid();
  if (user == user_priv) {
    return 0;
  } else {
    return 1;
  }
}
