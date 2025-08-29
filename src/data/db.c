#include "db.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

sqlite3 *setupDB() {
  sqlite3 *db;
  int rc = sqlite3_open("database.db", &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    return NULL;
  }
  printf("Database works");
  return db;
}
