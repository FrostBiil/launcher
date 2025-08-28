#include "main_view.h"

GtkWidget* main_view_new(void) {
  GtkWidget *v = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);

  GtkWidget *stack = gtk_stack_new();
  gtk_stack_set_transition_type(GTK_STACK(stack), GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT_RIGHT);
  gtk_stack_add_titled(GTK_STACK(stack), gtk_label_new("Game page…"), "game", "Game");
  gtk_stack_add_titled(GTK_STACK(stack), gtk_label_new("News page…"), "news", "News");
  gtk_stack_add_titled(GTK_STACK(stack), gtk_label_new("Forum page…"), "forum", "Forum");
  gtk_stack_add_titled(GTK_STACK(stack), gtk_label_new("Expansions page…"), "exp", "Expansions");

  GtkWidget *switcher = gtk_stack_switcher_new();
  gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(switcher), GTK_STACK(stack));
  gtk_box_append(GTK_BOX(v), switcher);

  GtkWidget *overlay = gtk_overlay_new();
  GtkWidget *content = gtk_box_new(GTK_ORIENTATION_VERTICAL, 8);
  gtk_box_append(GTK_BOX(content), gtk_frame_new("HERO IMAGE (placeholder)"));

  GtkWidget *news_row = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 8);
  gtk_box_append(GTK_BOX(news_row), gtk_frame_new("News 1"));
  gtk_box_append(GTK_BOX(news_row), gtk_frame_new("News 2"));
  gtk_box_append(GTK_BOX(content), news_row);

  gtk_overlay_set_child(GTK_OVERLAY(overlay), content);

  GtkWidget *action = gtk_button_new_with_label("Download / Update / Play");
  gtk_widget_add_css_class(action, "suggested-action");
  gtk_overlay_add_overlay(GTK_OVERLAY(overlay), action);
  gtk_widget_set_halign(action, GTK_ALIGN_END);
  gtk_widget_set_valign(action, GTK_ALIGN_END);
  gtk_widget_set_margin_top(action, 8);
  gtk_widget_set_margin_end(action, 8);
  gtk_widget_set_margin_bottom(action, 8);

  gtk_box_append(GTK_BOX(v), stack);
  gtk_box_append(GTK_BOX(v), overlay);
  return v;
}
