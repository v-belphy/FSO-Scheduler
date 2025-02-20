
CFLAGS := --std=c2x -Wall -Wextra -Wpedantic -Werror -Wno-unused-result
SHAREDLIBS := -pthread
CC := gcc

LIBS := $(STATICLIBS) $(SHAREDLIBS)

.PHONY: clean run build

build:
	@mkdir -p dist/out
	@$(CC) $(CFLAGS) $(RELEASEFLAGS) src/main.c $(LIBS) $(INCLUDE) -o dist/out/fso-scheduler

run: build
	@./dist/out/fso-scheduler

clean:
	@rm -r dist
	@rm -r .cache

