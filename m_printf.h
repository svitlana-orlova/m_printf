#ifndef M_PRINTF_H
#define M_PRINTF_H

#include <stdarg.h>

int m_printf(void (*fp)(int), char const * format, ...);

#endif

