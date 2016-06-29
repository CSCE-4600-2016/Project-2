#include <stdio.h>
#include <unistd.h>
#include <time.h>
void inc_n(int *n)
{
   /* increment n to 100 */
   while(++(*n) < 1000000000);
}

int main()
{
    clock_t start, end;
    double time_spent;
   start = clock();
    int x = 0, y = 0;
    printf("x: %d, y: %d\n", x, y);
   
    inc_n(&x);
    printf("x increment finished\n");
    end = clock(); 
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Execution Time: %f\n\n ", time_spent );
    fork();
    
    inc_n(&y);
    printf("y increment finished\n\n");
    printf("x: %d, y: %d\n", x, y);
    return 1;
}
