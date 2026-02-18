#include "ft_printf.h"
// int ex(int c, ...)
// {
//    va_list ar;
//    va_start(ar, c);
//    int s = 0;
//    int i = 0;
//    int x = 0;
//    while(i < c)
//    {
//         x = va_arg(ar, int);
//         s += x;
//         i++;
//    }
//    va_end(ar);
//    return s;
// }
// #include <stdio.h>
// int main()
// {

//     printf("%d\n", ex(5, 5,5,5,5,20));
//     printf("%d,%c\n", 42, 'n');

//}
#include <stdio.h>
int main()
{
    int a = 0;
    // p_control(&a);
    // printf("     ----p_cont----\n");
    // printf("%p", &a);
    // printf("     ----printf----\n");
    // x_control(a);
    // printf("     ----x_cont----\n");
    int x = ft_printf("asd -> %x\n", a);
   int y = printf("asd -> %x\n", a);
   printf("proje-> %d\n", x);
   printf("orj ->%d\n", y);
}