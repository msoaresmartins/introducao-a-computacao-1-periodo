#include <stdio.h>

int main()
{
    float x1, x2, x3, x4;
    scanf ("%f %f %f %f", &x1, &x2, &x3, &x4);
    
    if ((x1 < x2) && (x1 < x3) && (x1 < x4))
    { printf ("O menor valor e: %f\n", x1);
    } else if ((x2 < x1) && (x2 < x3) && (x2 < x4))
      {printf ("O menor valor e: %f\n", x2);
    } else if ((x3 < x1) && (x3 < x2) && (x3 < x4))
        { printf ("O menor valor e: %f\n", x3); 
    } else { 
       printf ("O menor valor e: %f\n", x4); }

    return 0;
}