test: m_printf.c test.c
	$(CC) $(CFLAGS) -o $@ $< test.c

clean:
	rm test
