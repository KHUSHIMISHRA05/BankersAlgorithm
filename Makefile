# ============================================
#  Makefile — Compile sabka code ek saath
# ============================================

CC     = gcc
CFLAGS = -Wall -o

all:
	$(CC) $(CFLAGS) bankers_project \
		main.c khushi.c naitik.c pragnadeep.c priya.c

run:
	./bankers_project

clean:
	rm -f bankers_project
