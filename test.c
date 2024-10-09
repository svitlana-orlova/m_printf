#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include "m_printf.h"

static char hex_buf[10];
static int hex_buf_iter;
static void put_hexbuf(int const c);

static char dec_buf[10];
static int dec_buf_iter;
static void put_decbuf(int const c);


void m_putc(int const c)
{
    write(1, &c, 1);
}

int main(void)
{

    {
        int const i = 127;
        hex_buf_iter = 0;
        assert(m_printf(put_hexbuf, "0x%x", i) == 4);
        assert(strcmp(hex_buf, "0x7f") == 0);
        m_printf(m_putc, "[OK] hex_buf test: \"%s\"\n", hex_buf);
    }

    {
        int const i = 127;
        dec_buf_iter = 0;
        assert(m_printf(put_decbuf, "0x%d", i) == 5);
        assert(strcmp(dec_buf, "0x127") == 0);
        m_printf(m_putc, "[OK] dec_buf test: \"%s\"\n", dec_buf);
    }

    return 0;
}

static void put_decbuf(int const c)
{
    dec_buf[dec_buf_iter++] = c;
}

static void put_hexbuf(int const c)
{
    hex_buf[hex_buf_iter++] = c;
}

