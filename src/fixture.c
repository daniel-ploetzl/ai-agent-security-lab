#include "fixture.h"

struct fixture fixture_create(void)
{
    return (struct fixture){
        .registration = {.agent = AGENT_A, .active = true},
        .grant = {
            .id = REPORT_A_READ_GRANT, .delegator = REPORT_OWNER, .agent = AGENT_A,
            .action = READ_REPORT, .report = REPORT_A,
            .active = true, .expires_at = 200
        },
        .token = {
            .value = "synthetic-test-token", .agent = AGENT_A,
            .grant = REPORT_A_READ_GRANT, .active = true, .expires_at = 100
        }
    };
}
