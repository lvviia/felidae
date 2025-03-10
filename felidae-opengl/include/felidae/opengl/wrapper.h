#ifndef FELIDAE_OPENGL_WRAPPER_H
#define FELIDAE_OPENGL_WRAPPER_H

#include "felidae/common/payload.h"
#include "felidae/opengl/camera.h"
#include "felidae/windowing/core.h"

#include "felidae/opengl/context.h"

typedef struct felidae_graphics_context felidae_graphics_context_t;

felidae_payload_result felidae_check_api_extensions(void);

felidae_payload_result felidae_graphics_create_context(
    felidae_graphics_context_t **ctx, felidae_window_t *window
);

felidae_camera_view *felidae_wrapper_get_camera_view();

void felidae_graphics_start(
    felidae_window_t *window, felidae_graphics_context_t *ctx, float delta
);

void felidae_graphics_end(
    felidae_window_t *window, felidae_graphics_context_t *ctx, float delta
);

felidae_payload_result felidae_graphics_init(
    felidae_window_t *window, felidae_graphics_context_t *ctx
);

void felidae_graphics_cleanup(
    felidae_window_t *window, felidae_graphics_context_t *ctx
);

// Wrappers

void DrawBackground(
    unsigned int red, unsigned int green, unsigned int blue, float alpha
);

#endif
