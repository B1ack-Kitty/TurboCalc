#include <gtk/gtk.h>

// Testing
#include <stdio.h>

GtkWidget*      window;
GtkWidget*      grid;
GtkWidget*      button;
GtkWidget*      view;
GtkTextBuffer*  buffer;
GtkTextIter     iter;


// ASM
extern int  add_v(int a, int b);
extern int  sub_v(int a, int b);
extern int  mul_v(int a, int b);
extern int  div_v(int a, int b);
extern int  str_len(char *str);

struct Calculator
{
    int     num1;
    int     num2;
    char    operator;
    int     result;
};

struct Calculator c;

static void hello(void)
{
    g_print("test");
}

int convert_to_int(char *str)
{
    int i;
    int num;

    i = 0;
    num = 0;
    while(str[i] != '\0')
    {
        if (str[i] >= 48 && str[i] <= 57)
        {
            num = num * 10 + (str[i] - 48);
            i++;
        }
        else
            break;
    }
    return num;
}

char* convert_to_str(int num)
{
    int     i;
    int     start, end;
    int     digit;
    int     is_negative;
    char    temp;
    char    *str;

    i = 0;
    is_negative = 0;
    str = "";

    if (num ==0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
    if (num < 0)
    {
        is_negative = 1;
        num = -num;
    }
    while (num != 0)
    {
        digit = num % 10;
        str[i++] = digit + '0';
        num = num / 10;
    }
    if (is_negative)
        str[i++] = '-';
    
    start = 0;
    end = i - 1;
    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
    return str;
}

static void add1_tobuf(void)
{
    gtk_text_buffer_get_end_iter(buffer, &iter);
    gtk_text_buffer_insert(buffer, &iter, "1", -1);
}
static void add2_tobuf(void)
{
    gtk_text_buffer_get_end_iter(buffer, &iter);
    gtk_text_buffer_insert(buffer, &iter, "2", -1);
}
static void add3_tobuf(void)
{
    gtk_text_buffer_get_end_iter(buffer, &iter);
    gtk_text_buffer_insert(buffer, &iter, "3", -1);
}
static void add4_tobuf(void)
{
    gtk_text_buffer_get_end_iter(buffer, &iter);
    gtk_text_buffer_insert(buffer, &iter, "4", -1);
}
static void add5_tobuf(void)
{
    gtk_text_buffer_get_end_iter(buffer, &iter);
    gtk_text_buffer_insert(buffer, &iter, "5", -1);
}
static void add6_tobuf(void)
{
    gtk_text_buffer_get_end_iter(buffer, &iter);
    gtk_text_buffer_insert(buffer, &iter, "6", -1);
}
static void add7_tobuf(void)
{
    gtk_text_buffer_get_end_iter(buffer, &iter);
    gtk_text_buffer_insert(buffer, &iter, "7", -1);
}
static void add8_tobuf(void)
{
    gtk_text_buffer_get_end_iter(buffer, &iter);
    gtk_text_buffer_insert(buffer, &iter, "8", -1);
}
static void add9_tobuf(void)
{
    gtk_text_buffer_get_end_iter(buffer, &iter);
    gtk_text_buffer_insert(buffer, &iter, "9", -1);
}
static void add0_tobuf(void)
{
    gtk_text_buffer_get_end_iter(buffer, &iter);
    gtk_text_buffer_insert(buffer, &iter, "0", -1);
}
static void button_clear(void)
{
    c.num1 = 0;
    c.num2 = 0;
    c.operator = '\0';
    c.result = 0;
    gtk_text_buffer_set_text(buffer, "", -1);
}

static void calculate(void)
{
    op = c.operator
    switch (op)
    {
        case '+':
            result = add_v(c.num1, c.num2);
            break;
        case '-':
            result = sub_v(c.num1, c.num2);
            break;
        case '*':
            result = mul_v(c.num1, c.num2);
            break;
        case '/':
            result = div_v(c.num1, c.num2);
            break;
    }

    gtk_text_buffer_set_text(buffer, x, -1);
}

static void activate(GtkApplication *app)
{
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
    gtk_text_view_set_top_margin(GTK_TEXT_VIEW(view), 20);
    gtk_text_buffer_set_text(buffer, "", -1);

    // Buttons
    button = gtk_button_new_with_label("1");
    g_signal_connect(button, "clicked", G_CALLBACK(add1_tobuf), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

    button = gtk_button_new_with_label("2");
    g_signal_connect(button, "clicked", G_CALLBACK(add2_tobuf), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);

    button = gtk_button_new_with_label("3");
    g_signal_connect(button, "clicked", G_CALLBACK(add3_tobuf), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 2, 1, 1, 1);

    button = gtk_button_new_with_label("4");
    g_signal_connect(button, "clicked", G_CALLBACK(add4_tobuf), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);

    button = gtk_button_new_with_label("5");
    g_signal_connect(button, "clicked", G_CALLBACK(add5_tobuf), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 1, 2, 1, 1);

    button = gtk_button_new_with_label("6");
    g_signal_connect(button, "clicked", G_CALLBACK(add6_tobuf), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);

    button = gtk_button_new_with_label("7");
    g_signal_connect(button, "clicked", G_CALLBACK(add7_tobuf), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 1, 1);

    button = gtk_button_new_with_label("8");
    g_signal_connect(button, "clicked", G_CALLBACK(add8_tobuf), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 1, 3, 1, 1);

    button = gtk_button_new_with_label("9");
    g_signal_connect(button, "clicked", G_CALLBACK(add9_tobuf), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 2, 3, 1, 1);


    button = gtk_button_new_with_label("CE");
    g_signal_connect(button, "clicked", G_CALLBACK(button_clear), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 1, 1);

    button = gtk_button_new_with_label("0");
    g_signal_connect(button, "clicked", G_CALLBACK(add0_tobuf), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 1, 4, 1, 1);

    button = gtk_button_new_with_label("=");
    g_signal_connect(button, "clicked", G_CALLBACK(calculate), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 2, 4, 1, 1);

    button = gtk_button_new_with_label("+");
    g_signal_connect(button, "clicked", G_CALLBACK(button_add), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 4, 1, 1, 1);

    button = gtk_button_new_with_label("-");
    g_signal_connect(button, "clicked", G_CALLBACK(button_sub), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 4, 2, 1, 1);

    button = gtk_button_new_with_label("*");
    g_signal_connect(button, "clicked", G_CALLBACK(button_mul), NULL);
    // Gtk attach button to grid
    gtk_grid_attach(GTK_GRID(grid), button, 4, 3, 1, 1);

    button = gtk_button_new_with_label("/");
    g_signal_connect(button, "clicked", G_CALLBACK(button_div), NULL);
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
