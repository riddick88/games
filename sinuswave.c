# include <stdio.h>
# include <math.h>

int main(int argc, char const *argv[])
{
    // -b+1 converts 0 to 1 and vice versa
    for (double x = 0, b = 0; x < 40; x += 0.25, b = -b+1) {
        for (int i = 0; i < (int)(26 + 25 * sin(x)); i++)
            putchar(' ');

        if (!b) {
            puts("Creative");
        } else {
            puts("Computing");
        }
    }
    return 0;
}