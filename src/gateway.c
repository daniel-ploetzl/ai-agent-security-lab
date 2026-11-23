#include "gateway.h"

#include <string.h>

const char *gateway_read(const struct gateway *gateway,
                         const struct request *request, uint64_t now)
{
    if (gateway == NULL || gateway->records == NULL ||
        gateway->read_report == NULL || request == NULL) {
        return NULL;
    }

    const struct fixture *records = gateway->records;
    const struct token_record *token = &records->token;
    const struct grant *grant = &records->grant;
    if (!token->active || now >= token->expires_at || token->value[0] == '\0' ||
        memchr(token->value, '\0', sizeof(token->value)) == NULL ||
        strncmp(request->token, token->value, sizeof(request->token)) != 0) {
        return NULL;
    }
    if (!records->registration.active || records->registration.agent != AGENT_A ||
        token->agent != records->registration.agent || grant->agent != token->agent ||
        !grant->active || now >= grant->expires_at || grant->delegator != REPORT_OWNER ||
        grant->id != REPORT_A_READ_GRANT || token->grant != grant->id) {
        return NULL;
    }
    if (request->action != READ_REPORT || request->action != grant->action ||
        (request->report != REPORT_A && request->report != REPORT_B) ||
        request->report != grant->report) {
        return NULL;
    }
    return gateway->read_report(gateway->reader_context, request->report);
}
