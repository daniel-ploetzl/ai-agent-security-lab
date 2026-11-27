#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fixture.h"

int main(void)
{
    const struct fixture f = fixture_create();
    if (!f.registration.active || f.registration.agent != AGENT_A ||
        !f.grant.active || f.grant.agent != f.registration.agent ||
        f.grant.id != REPORT_A_READ_GRANT || f.grant.delegator != REPORT_OWNER ||
        f.grant.action != READ_REPORT || f.grant.report != REPORT_A ||
        f.grant.expires_at != 200 || !f.token.active ||
        f.token.agent != f.registration.agent || f.token.grant != f.grant.id ||
        f.token.expires_at != 100 ||
        strcmp(f.token.value, "synthetic-test-token") != 0)
	{
        return EXIT_FAILURE;
    }

    return puts("PASS: synthetic fixture records") < 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
