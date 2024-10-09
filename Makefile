test: m_printf.c test.c
	$(CC) $(CFLAGS) -o $@ $< test.c

check: test
	./test

clean:
	rm test
