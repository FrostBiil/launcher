#include "sidebar.h"
#include "../app/catalog.h"

GtkWidget* sidebar_new(void) {
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
  gtk_widget_set_size_request(box, 240, -1);

  GtkWidget *logo = gtk_label_new("LOGO"); // Replace with actual logo
  gtk_widget_add_css_class(logo, "title-1");
  gtk_box_append(GTK_BOX(box), logo);

  GtkWidget *list = gtk_list_box_new();

  size_t count;
  const Game *games = catalog_get_all(&count);
  for (size_t i = 0; i < count; i++) {
    gtk_list_box_append(GTK_LIST_BOX(list), gtk_label_new(games[i].name));
  }

  gtk_box_append(GTK_BOX(box), list);
  return box;
}
