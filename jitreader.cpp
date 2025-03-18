#include "jitreader.h"

GDB_DECLARE_GPL_COMPATIBLE_READER;

extern "C" {

gdb_status felix86_gdb_read_debug_info(struct gdb_reader_funcs* self, struct gdb_symbol_callbacks* cb, void* memory, long memory_sz) {

    return GDB_SUCCESS;
}

gdb_status felix86_gdb_unwind_frame(struct gdb_reader_funcs* self, struct gdb_unwind_callbacks* cb) {
    return GDB_SUCCESS;
}

struct gdb_frame_id felix86_gdb_get_frame_id(struct gdb_reader_funcs* self, struct gdb_unwind_callbacks* c) {
    static gdb_frame_id boop{0xabcdef, 0};
    return boop;
}

void felix86_gdb_destroy(struct gdb_reader_funcs* self) {
    // Do nothing
}

struct gdb_reader_funcs* gdb_init_reader() {
    static struct gdb_reader_funcs funcs = {
        .reader_version = GDB_READER_INTERFACE_VERSION,
        .priv_data = nullptr,
        .read = felix86_gdb_read_debug_info,
        .unwind = felix86_gdb_unwind_frame,
        .get_frame_id = felix86_gdb_get_frame_id,
        .destroy = felix86_gdb_destroy,
    };
    return &funcs;
}
}