#include "game_repo.h"
#include "stmt.h"
#include <stdio.h>



void game_upsert(sqlite3 *db, const Game *g) {
  sqlite3_stmt *stmt = NULL;

  const char *sql =
    "INSERT INTO game(id, name, exec, args, workdir, icon, enabled) "
    "VALUES (?, ?, ?, ?, ?, ?, ?) "
    "ON CONFLICT(id) DO UPDATE SET "
    " name=excluded.name, "
    " exec=excluded.exec, "
    " args=excluded.args, "
    " workdir=excluded.workdir, "
    " icon=excluded.icon, "
    " enabled=excluded.enabled;";

  if (stmt_prepare(db, sql, &stmt) == SQLITE_OK) {
    stmt_bind_text(stmt, 1, g->id);
    stmt_bind_text(stmt, 2, g->name);
    stmt_bind_text(stmt, 3, g->exec);
    stmt_bind_text(stmt, 4, g->args);
    stmt_bind_text(stmt, 5, g->workdir);
    stmt_bind_text(stmt, 6, g->icon);
    stmt_bind_int(stmt, 7, g->enabled ? 1 : 0);

    int rc = stmt_step(stmt);
    if (rc != SQLITE_DONE) {
      fprintf(stderr, "game_upsert failed %s\n", sqlite3_errmsg(db));
    }
  }
  else {
    fprintf(stderr, "Prepare failed: %s\n", sqlite3_errmsg(db));
  }

  stmt_finalize(stmt);
}
