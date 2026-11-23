# AI agent security lab

This C11 lab studies how to enforce permissions when an AI agent uses tools on someone’s behalf. The current example gives a registered AI agent permission to read one report. The broader security question is what the AI agent can do with the information it receives, especially when untrusted content influences its next tool request.

## Why reading and sending need separate permissions

Consider an AI agent asked to summarise an internal report. The report contains text telling the AI agent to forward a confidential figure or upload the entire report to an external server. This is **indirect prompt injection**: an instruction reaches the AI agent through data it was asked to process.

Reading the report may be authorised. Sending the contents is a separate action involving a recipient and a destination. If the AI agent has access to an unrestricted network tool, a permission check on the original read cannot prevent disclosure. A system designed to enforce this policy would also mediate outbound transfers and check whether the AI agent has permission to send the particular data to that destination. The same requirement applies to excerpts as to the full report.

## Authentication and authorisation

**Authentication** concerns evidence of the presenter’s identity. The gateway checks a fixed synthetic bearer token associated with an AI agent registration. Anyone holding a copy can present it, so this check alone cannot establish who submitted the request.

**Authorisation** determines whether a requested operation is permitted. The report owner delegates permission to read Report A. The gateway checks the registration, credential and grant against the requested action and report before invoking the reader. This grant conveys no permission to read Report B or transmit either report.

## Implementation and evidence

A deterministic caller represents the AI agent. The gateway and reader run locally in one process with synthetic records. This models access through the gateway interface. Code executing inside the same process could bypass that interface.

1. Inspect the [request interface](inc/gateway.h) and [trusted record definitions](inc/fixture.h).
2. Follow the [gateway decision](src/gateway.c) from credential validation to the protected reader.
3. Run the native tests from the project root with a C11 compiler and GNU Make.

```sh
make test
```

The [gateway test](tests/test_gateway.c) verifies that an authorised read returns Report A and invokes the reader exactly once. The suite also checks the build baseline and fixture records. The next planned test requests Report B and checks that the reader call count stays unchanged. The indirect prompt injection example illustrates the broader threat model. The current implementation has no language model, outbound transfer tool or test for data disclosure.
