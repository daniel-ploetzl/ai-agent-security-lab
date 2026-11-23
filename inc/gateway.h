#ifndef LAB_GATEWAY_H
#define LAB_GATEWAY_H

#include "fixture.h"

struct request {
    char token[sizeof(((struct token_record *)0)->value)];
    enum action action;
    enum report_id report;
};

/* The host supplies the records, time and reader. Only request is caller input. */
struct gateway {
    const struct fixture *records;
    const char *(*read_report)(void *context, enum report_id report);
    void *reader_context;
};

/* Returns borrowed reader data on success or NULL on failure. */
const char *gateway_read(const struct gateway *gateway,
                         const struct request *request, uint64_t now);

#endif
