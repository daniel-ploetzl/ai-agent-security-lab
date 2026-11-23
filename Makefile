CFLAGS += -std=c11 -Wall -Wextra -Werror -pedantic

test: build/test_baseline build/test_fixture build/test_gateway
	./build/test_baseline
	./build/test_fixture
	./build/test_gateway

build/test_baseline: tests/test_baseline.c Makefile
	mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $<

build/test_fixture: tests/test_fixture.c src/fixture.c inc/fixture.h Makefile
	mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) -Iinc $(LDFLAGS) -o $@ tests/test_fixture.c src/fixture.c

build/test_gateway: tests/test_gateway.c src/gateway.c inc/gateway.h src/fixture.c inc/fixture.h Makefile
	mkdir -p build
	$(CC) $(CPPFLAGS) $(CFLAGS) -Iinc $(LDFLAGS) -o $@ tests/test_gateway.c src/gateway.c src/fixture.c

.PHONY: test
