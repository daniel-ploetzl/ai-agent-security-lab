# AI Agent Security Lab

This lab studies how to enforce permissions when an AI agent uses tools on someone’s behalf. The current example gives a registered AI agent permission to read one report.

The broader security question is what the AI agent can do with the information it receives. If an internal report tells the AI agent to forward a confidential figure, can that untrusted instruction influence its next tool request? Who checks whether the report owner authorised the transfer?

## 🔐 Current experiment

The report owner has granted the agent permission to read Report A. A local gateway checks the agent registration, bearer token and grant before calling the report reader.

| Request | Evidence |
| --- | --- |
| Read Report A | Verified. The gateway returns Report A and calls the reader once. |
| Read Report B with the same token | Next test. The gateway should deny the request and the reader call count should stay at one. |

A scripted caller represents the AI agent. The experiment uses synthetic records in a single process. Instructions embedded in reports and outbound transfers are future scenarios.

## 🧪 Run the tests

From the project root, run the following with GNU Make and a C compiler supporting C11.

```sh
make test
```

[Gateway implementation](src/gateway.c) · [Report access test](tests/test_gateway.c)
