#include "stmt.h"
#include <stdio.h>

int stmt_prepare(sqlite3 *db, const char *sql, sqlite3_stmt **out) {
  return sqlite3_prepare_v2(db, sql, -1, out, NULL);
}

void stmt_bind_text(sqlite3_stmt *stmt, int idx, const char *v) {
  sqlite3_bind_text(stmt, idx, v, -1, SQLITE_TRANSIENT);
}

void stmt_bind_int(sqlite3_stmt *stmt, int idx, int v) {
  sqlite3_bind_int(stmt, idx, v);
}

int stmt_step(sqlite3_stmt *stmt) {
  return sqlite3_step(stmt);
}

const char* stmt_col_text(sqlite3_stmt *stmt, int idx) {
  return (const char*) sqlite3_column_text(stmt, idx);
}

int stmt_col_int(sqlite3_stmt *stmt, int idx) {
  return sqlite3_column_int(stmt, idx);
}

void stmt_finalize(sqlite3_stmt *stmt) {
  if (stmt) sqlite3_finalize(stmt);
}
