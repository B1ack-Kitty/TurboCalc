#include <gtk/gtk.h>

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
    GtkWidget*      window;
    GtkWidget*      grid;
    GtkWidget*      button;
    GtkWidget*      view;
    GtkTextBuffer*  buffer;

    // Window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Window");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

    // Grid
    grid = gtk_grid_new();

    gtk_container_add(GTK_CONTAINER(window), grid);

    // Align
    // y
    gtk_widget_set_halign(window, GTK_ALIGN_CENTER);
    gtk_widget_set_halign(grid, GTK_ALIGN_CENTER);
    // x
    gtk_widget_set_valign(window,GTK_ALIGN_CENTER);
    gtk_widget_set_valign(grid,GTK_ALIGN_CENTER);

    // View
    view = gtk_text_view_new();
    gtk_grid_attach(GTK_GRID(grid), view, 0, 0, 4, 1);

    // Buffer
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));

    gtk_text_buffer_set_text(buffer, "Hello!", -1);

    // Buttons
    button = gtk_button_new_with_label("1");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

    button = gtk_button_new_with_label("2");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);

    button = gtk_button_new_with_label("3");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 2, 1, 1, 1);

    button = gtk_button_new_with_label("4");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);

    button = gtk_button_new_with_label("5");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 1, 2, 1, 1);

    button = gtk_button_new_with_label("6");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);

    button = gtk_button_new_with_label("7");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 1, 1);

    button = gtk_button_new_with_label("8");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 1, 3, 1, 1);

    button = gtk_button_new_with_label("9");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 2, 3, 1, 1);


    button = gtk_button_new_with_label("CE");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 1, 1);

    button = gtk_button_new_with_label("0");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 1, 4, 1, 1);

    button = gtk_button_new_with_label("=");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 2, 4, 1, 1);

    button = gtk_button_new_with_label("+");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 4, 1, 1, 1);

    button = gtk_button_new_with_label("-");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 4, 2, 1, 1);

    button = gtk_button_new_with_label("*");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 4, 3, 1, 1);

    button = gtk_button_new_with_label("/");
    g_signal_connect(button, "clicked", G_CALLBACK(hello), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 4, 4, 1, 1);

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
