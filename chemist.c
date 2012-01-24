/* Copyright (C) 2012  Jakob Kramer
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE. */

# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define RATIO (7/3.0)

int main(void) {
    int acid, guess, deads = 0;
    double water;
    srand(time(NULL));
    printf("\t\t\tChemist\n");

    while (1) {
        acid = rand() % 51;
        water = acid * RATIO;

        printf("%d liters of kryptocyanic acid.  How much water?  (-1 to "
               "quit) ", acid);

        if (scanf("%d", &guess) <= 0) {
            printf("\nAn error occured.\n");
            return EXIT_FAILURE;
        }

        else if (guess == -1)
            return EXIT_SUCCESS;

        else if (abs(water-guess) > water/20.0) {
            ++deads;
            printf("Sizzle!  You have just been desalinated into a blob of "
                   "quivering protoplasm!\n");
            if (deads == 9) {
                printf("Your 9 lives are used, but you will be long remembered "
                       "for your contributions to the field of comic book chemi"
                       "stry.\n");
                break;
            }
            printf("However, you may try again with another life.\n");
        }
        else {
            printf("Good job!  You may breathe now, but don't inhale the "
                   "fumes!\n\n");
        }
    }

    return EXIT_SUCCESS;
}
