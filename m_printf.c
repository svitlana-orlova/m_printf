#include "m_printf.h"

static int m_putnum(void (*fp)(int), int n)
{
    int count = 0;

    if (n < 0) {
        fp('-');
        count++;
        n = -n;
    }

    if (n / 10) {
        count += m_putnum(fp, n / 10);
    }

    fp(n % 10 + '0');
    count++;

    return count;
}

static int m_puthex(void (*fp)(int), int n)
{
    int count = 0;
    int tmp[16] = { 0 };

    while (n != 0) {
        int const rem = n % 16;

        if (rem < 10) {
            tmp[count] = rem + '0';
        } else {
            tmp[count] = rem - 10 + 'a';
        }

        count++;
        n /= 16;
    }

    for (int i = count; i >= 0; --i) {
        fp(tmp[i]);
    }

    return count;
}

int m_printf(void (*fp)(int), char const * format, ...)
{
    va_list args;
    va_start(args, format);
    char const * cp = format;
    int count = 0;

    while (*cp) {
        if (*cp == '%') {
            cp++;
            switch(*cp) {
                case 'x':
                    count +=m_puthex(fp, va_arg(args, int));
                    break;
                case 'd':
                    count += m_putnum(fp, va_arg(args, int));
                    break;
                case 'c':
                case '%':
                    fp(va_arg(args, int));
                    count++;
                    break;
                default:
                    break;
            }
        } else {
            fp(*cp);
            count++;
        }
        cp++;
    }

    va_end(args);

    return count;
}

