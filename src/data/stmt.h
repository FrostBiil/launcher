#pragma once
#include <sqlite3.h>

int stmt_prepare(sqlite3 *db, const char *sql, sqlite3_stmt **out);
void stmt_bind_text(sqlite3_stmt *stmt, int idx, const char *v);
void stmt_bind_int(sqlite3_stmt *stmt, int idx, int v);
int stmt_step(sqlite3_stmt *stmt);
const char* stmt_col_text(sqlite3_stmt *stmt, int idx);
int stmt_col_int(sqlite3_stmt *stmt, int idx);
void stmt_finalize(sqlite3_stmt *stmt);
