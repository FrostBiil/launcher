#include "window.h"
#include "sidebar.h"
#include "main_view.h"

GtkWidget* window_new(GtkApplication *app)
{
  GtkWidget *win = gtk_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(win), "Launcher");
  gtk_window_set_default_size(GTK_WINDOW(win), 1100, 700);

  GtkWidget *root = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_window_set_child(GTK_WINDOW(win), root);

  gtk_box_append(GTK_BOX(root), sidebar_new());
  gtk_box_append(GTK_BOX(root), main_view_new());

  return win;
}
