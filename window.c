#include <gtk/gtk.h>

static void on_activate(GApplication *app, gpointer user_data) {
  GtkWidget *window;

  window = gtk_application_window_new(GTK_APPLICATION(app));
  gtk_window_set_title(GTK_WINDOW(window), "Suduko Solver");
  gtk_window_set_default_size(GTK_WINDOW(window), 1280, 720);
  gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
  GtkApplication *app;
  int status;

  app = gtk_application_new("my.org.SudukoSolver", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);

  return status;
}
