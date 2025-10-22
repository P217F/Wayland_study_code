/*
Init wl_display and running
*/
#include <stdio.h>
#include <wayland-server.h>

int main() {
    struct wl_display *display = wl_display_create();
    if (!display) {
        fprintf(stderr, "Error: cannot create wayland server\n");
        return 1;
    }
    fprintf(stdout, "Running wayland server atomic\n");
    wl_display_run(display);
    wl_display_destroy(display);

    // Exit program
    return 0;
}