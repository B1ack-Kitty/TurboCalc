#include <gtk/gtk.h>

GtkWidget*      window;
GtkWidget*      grid;
GtkWidget*      button;
GtkWidget*      view;
GtkTextBuffer*  buffer;
GtkTextIter     iter;
GtkTextIter     start, end;

// ASM
extern int  add_v(int a, int b);
extern int  sub_v(int a, int b);
extern int  mul_v(int a, int b);
extern int  div_v(int a, int b);

struct Calculator
{
    int     num1;
    int     num2;
    char    operator;
    int     result;
};

struct Calculator c;

// Helper Functions
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
void convert_to_str(char *str, int num)
{
    int     i;
    int     j;
    int     k;
    int     sign;
    char    temp;

    sign = num;

    i = 0;
    if (num < 0)
    {
        num = -num;
    }
    while (num > 0)
    {
        str[i] = num % 10 + '0';
        num /= 10;
        i++;
    }
    if (sign < 0)
        str[i++] = '-';

    str[i] = '\0';

    j = 0;
    k = i - 1;
    while (j < k)
    {
        temp = str[j];
        str[j] = str[k];
        str[k] = temp;
        j++;
        k--;
    }
}
char* get_buf(void)
{
    char    *line;

    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);
    line = gtk_text_iter_get_text(&start, &end);

    return line;
}
// Button Logic
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
// Operation Logic
static void button_add(void)
{
    char    *buf;

    c.operator = '+';
    buf = get_buf();
    c.num1 = convert_to_int(buf);
    gtk_text_buffer_set_text(buffer, "", -1);
}
static void button_sub(void)
{
    char    *buf;

    c.operator = '-';
    buf = get_buf();
    c.num1 = convert_to_int(buf);
    gtk_text_buffer_set_text(buffer, "", -1);
}
static void button_mul(void)
{
    char    *buf;

    c.operator = '*';
    buf = get_buf();
    c.num1 = convert_to_int(buf);
    gtk_text_buffer_set_text(buffer, "", -1);
}
static void button_div(void)
{
    char    *buf;

    c.operator = '/';
    buf = get_buf();
    c.num1 = convert_to_int(buf);
    gtk_text_buffer_set_text(buffer, "", -1);
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
    char    *buf;
    char    op;

    buf = get_buf();
    c.num2 = convert_to_int(buf);
    op = c.operator;
    switch (op)
    {
        case '+':
            c.result = add_v(c.num1, c.num2);
            break;
        case '-':
            c.result = sub_v(c.num1, c.num2);
            break;
        case '*':
            c.result = mul_v(c.num1, c.num2);
            break;
        case '/':
            c.result = div_v(c.num1, c.num2);
            break;
    }
    convert_to_str(buf, c.result);
    gtk_text_buffer_set_text(buffer, buf, -1);
}
// Main Logic
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
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 1, 1);

    button = gtk_button_new_with_label("2");
    g_signal_connect(button, "clicked", G_CALLBACK(add2_tobuf), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 1, 1, 1);

    button = gtk_button_new_with_label("3");
    g_signal_connect(button, "clicked", G_CALLBACK(add3_tobuf), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 2, 1, 1, 1);

    button = gtk_button_new_with_label("4");
    g_signal_connect(button, "clicked", G_CALLBACK(add4_tobuf), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 1, 1);

    button = gtk_button_new_with_label("5");
    g_signal_connect(button, "clicked", G_CALLBACK(add5_tobuf), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 2, 1, 1);

    button = gtk_button_new_with_label("6");
    g_signal_connect(button, "clicked", G_CALLBACK(add6_tobuf), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 2, 2, 1, 1);

    button = gtk_button_new_with_label("7");
    g_signal_connect(button, "clicked", G_CALLBACK(add7_tobuf), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 1, 1);

    button = gtk_button_new_with_label("8");
    g_signal_connect(button, "clicked", G_CALLBACK(add8_tobuf), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 3, 1, 1);

    button = gtk_button_new_with_label("9");
    g_signal_connect(button, "clicked", G_CALLBACK(add9_tobuf), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 2, 3, 1, 1);

    button = gtk_button_new_with_label("CE");
    g_signal_connect(button, "clicked", G_CALLBACK(button_clear), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 1, 1);

    button = gtk_button_new_with_label("0");
    g_signal_connect(button, "clicked", G_CALLBACK(add0_tobuf), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 1, 4, 1, 1);

    button = gtk_button_new_with_label("=");
    g_signal_connect(button, "clicked", G_CALLBACK(calculate), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 2, 4, 1, 1);

    button = gtk_button_new_with_label("+");
    g_signal_connect(button, "clicked", G_CALLBACK(button_add), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 1, 1, 1);

    button = gtk_button_new_with_label("-");
    g_signal_connect(button, "clicked", G_CALLBACK(button_sub), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 2, 1, 1);

    button = gtk_button_new_with_label("*");
    g_signal_connect(button, "clicked", G_CALLBACK(button_mul), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 3, 1, 1);

    button = gtk_button_new_with_label("/");
    g_signal_connect(button, "clicked", G_CALLBACK(button_div), NULL);
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
