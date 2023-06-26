#include "main.h"
int poin_case(va_list args)
{   
    void *p = va_arg(args, void *);
    unsigned long address = (unsigned long)p;
    int count = 0, i = 0;
    char hex1[] = "0123456789abcdef";
    char num[50];

    if (p == NULL)
    {
        count += handle_default('('); count += handle_default('n');count += handle_default('i');
        count += handle_default('l'); count += handle_default(')');
        return (count);
    }
    count += handle_default('0');
    count += handle_default('x');
    if (address == 0)
    {
        count += handle_default('0');
        return (count);
    }
    if (address < 16)
    {   
        count += handle_default('0');
        if (address < 10)
            count += handle_default(address + 48);
        else
            count += handle_default(address + 87);
    }
    else
    {
        while (address > 0)
        {
            i = address % 16;
            address /= 16;
            num[count] = hex1[i];
            count++;
        }
        for (i = count - 1; i >= 2; i--)
            handle_default(num[i]);
    }
    return (count);
}
