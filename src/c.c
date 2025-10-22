#include <stdio.h>
#include <wayland-server.h>

int main() {
    struct wl_display *display = wl_display_create();
    if (!display) {
        fprintf(stderr, "Error: cannot init wayland server\n");
        return 1;
    }


    wl_display_set_default_max_buffer_size(display, 8*1024*1024);
    wl_display_add_socket(display,NULL);
    wl_display_run(display);
    fprintf(stdout,"Running wayland server skeleton\n");
    wl_display_destroy(display);

    return 0;
}