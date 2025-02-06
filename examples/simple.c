#include <sfgl/basic.h>
#include <sfgl/event.h>
#include <stdio.h>

void listen(struct sfgl_event *event)
{
    int width = GetWindowWidth(), height = GetWindowHeight(), x = GetWindowX(),
        y = GetWindowY();
    const char *title = GetWindowTitle();
    printf(
        "width=%d,height=%d,x=%d,y=%d,title=%s\n", width, height, x, y, title
    );
    if (event->kind == KEY_PRESS)
        printf(
            "Key pressed: code=%d,timestamp=%d\n",
            event->data.key_press.key_code, event->timestamp
        );
    fflush(stdout);
}

int main()
{
    MakeWindow(640, 480, "Hello, world!", 0);
    RevealWindow();
    while (!ShouldWindowClose()) {
        struct sfgl_event *event = PollEvent();
        if (event) {
            listen(event);
        }
    }
    SFGLFree();
    return 0;
}
