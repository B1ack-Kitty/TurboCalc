#include <gtk/gtk.h>
#include <fontconfig/fontconfig.h>


// Testing
#include <stdio.h>

// ASM
extern int  add_v(int a, int b);
extern int  sub_v(int a, int b);
extern int  mul_v(int a, int b);
extern int  div_v(int a, int b);

static void hello(void)
{
    g_print("Hello, World!\n");
}

static void activate(GtkApplication *app)
{
    GtkWidget*  window;
    GtkWidget*  button;
    GtkWidget*  button_box;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    button_box = gtk_button_box_new(GTK_ORIENTATION_HORIZONTAL);
    gtk_container_add(GTK_CONTAINER(window), button_box);

    button = gtk_button_new_with_label("Meow!");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gtk_widget_destroy), window);
    gtk_container_add(GTK_CONTAINER(button_box), button);

    gtk_widget_show_all(window);
}

// MAIN
int main(int argc, char **argv)
{
    GtkApplication *app;
    int             status;

    app = gtk_application_new("org.gtk.example", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

	return status;
}
