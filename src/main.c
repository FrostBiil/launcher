#include <gtk/gtk.h>
#include "ui/window.h"

static void on_activate(GtkApplication *app, gpointer user_data) {
  GtkWidget *win = window_new(app);  // delegate all UI creation
  gtk_window_present(GTK_WINDOW(win));
}

int main(int argc, char **argv) {
  GtkApplication *app = gtk_application_new("org.rly.launcher", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
  int code = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  return code;
}