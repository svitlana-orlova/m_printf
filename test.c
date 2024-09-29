#include <unistd.h>
#include "m_printf.h"

void m_putc(int const c)
{
    write(1, &c, 1);
}


int main(void)
{
    m_printf(m_putc, "0x%x\n", 127);

    return 0;
}

