#include "gateway.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *read_report(void *context, enum report_id report)
{
    unsigned *calls = context;
    ++*calls;
    return report == REPORT_A ? "Synthetic Report A" : NULL;
}

int main(void)
{
    const struct fixture records = fixture_create();
    unsigned calls = 0;
    const struct gateway gateway = {&records, read_report, &calls};
    const struct request request = {"synthetic-test-token", READ_REPORT, REPORT_A};
    const char *result = gateway_read(&gateway, &request, 1);
    if (result == NULL || strcmp(result, "Synthetic Report A") != 0 || calls != 1) {
        return EXIT_FAILURE;
    }
    return puts("PASS: Report A returned, reader called once") < 0
        ? EXIT_FAILURE : EXIT_SUCCESS;
}
