#pragma once
#include <stdbool.h>

typedef struct {
  const char *id;      // unique id (e.g. a UUID or name)
  const char *name;    // display name
  const char *exec;    // path to exe
  const char *args;    // launch args
  const char *workdir; // working directory
  bool enabled;        // show/launchable
} Game;
