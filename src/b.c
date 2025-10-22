#include <wayland-server.h>
#include <stdio.h>

void handle_mouse_click(struct wl_display *display, struct wl_resource *pointer_resource, uint32_t button) {
    uint32_t serial = wl_display_next_serial(display);
    uint32_t time = 123456;
    printf("Sending wl_pointer.button event:\n");
    printf("  serial=%u, time=%u, button=%u\n", serial, time, button);
    wl_resource_post_event(pointer_resource,WL_POINTER_BUTTON,serial,time,button,WL_POINTER_BUTTON_STATE_PRESSED);
}

int main(void) {
    struct wl_display *display = wl_display_create();
    if (!display) {
        fprintf(stderr, "Failed to create Wayland display\n");
        return 1;
    }
    struct wl_resource *fake_pointer_resource = (struct wl_resource *)0xDEADBEEF;
    handle_mouse_click(display, fake_pointer_resource, 0x110);
    printf("Current serial = %u\n", wl_display_get_serial(display));
    wl_display_destroy(display);
    return 0;
}
