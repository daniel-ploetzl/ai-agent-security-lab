#ifndef LAB_FIXTURE_H
#define LAB_FIXTURE_H

#include <stdbool.h>
#include <stdint.h>

enum agent_id { AGENT_A = 1 };
enum principal_id { REPORT_OWNER = 1 };
enum action { READ_REPORT = 1 };
enum report_id { REPORT_A = 1, REPORT_B };
enum grant_id { REPORT_A_READ_GRANT = 1 };

struct registration {
    enum agent_id agent;
    bool active;
};

struct grant {
    enum grant_id id;
    enum principal_id delegator;
    enum agent_id agent;
    enum action action;
    enum report_id report;
    bool active;
    uint64_t expires_at;
};

struct token_record {
    char value[32];
    enum agent_id agent;
    enum grant_id grant;
    bool active;
    uint64_t expires_at;
};

struct fixture {
    struct registration registration;
    struct grant grant;
    struct token_record token;
};

struct fixture fixture_create(void);

#endif
