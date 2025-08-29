#include <gtk/gtk.h>
#include "ui/window.h"
#include "data/db.h"
#include "data/stmt.h"
#include "data/game_repo.h"
#include "models/game.h"

static void on_activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *win = window_new(app);  // delegate all UI creation
  gtk_window_present(GTK_WINDOW(win));
}

//Temporary for manual testing
Game g = {
  .id = "example_game_1",
  .name = "Example Game 1",
  .exec = "C:/dirpath.exe",
  .args = "",
  .workdir = "C:/dirpath",
  .icon = NULL,
  .enabled = true
};


int main(int argc, char **argv) {
  sqlite3 *db = setupDB();

  game_upsert(db, &g);

  sqlite3_stmt *stmt = NULL;

  if (stmt_prepare(db, "SELECT id, name FROM game", &stmt) == SQLITE_OK) {
    while (stmt_step(stmt) == SQLITE_ROW) {
      const char *id = stmt_col_text(stmt, 0);
      const char *name = stmt_col_text(stmt, 1);
      printf("Game: %s (%s)\n", id, name);
    }
  }
  stmt_finalize(stmt);

  GtkApplication *app = gtk_application_new("org.rly.launcher", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
  int code = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  return code;
}
