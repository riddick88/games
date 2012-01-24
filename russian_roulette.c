/* Copyright (C) 2011, 2012  Jakob Kramer
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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_int(int min, int max) {
    return (rand() % max + min);
}

int main(void) {
    int times_triggered = 0, bullet_in;
    char choice;
    _Bool aborted = 0, died = 0;

    /* print instructions */
    puts("Welcome to a Russian Roulette game!");
    puts("Type `1` to spin chamber and pull trigger.");
    puts("Type `2` to give up.");

    srand(time(NULL)); /* initialize random seed */
    bullet_in = random_int(1, 6); /* which slot is the bullet in? */

    while (times_triggered < 6) {
        choice = getchar();
        if (choice != '\n')
            while (getchar() != '\n') {}; /* clear stdin */

        if (choice == '1') { /* `1` -> spin chamber and pull trigger */
            times_triggered++;
            if (bullet_in == random_int(1, 6)) {
                died = 1;
                break;
            }
        } else if (choice == '2') { /* `2` -> give up */
            aborted = 1;
            break;
        } else { /* neither `1`, nor `2` */
            puts("Try to hit the right keys!");
        }
    }

    if (!(died || aborted)) {
        puts("You won!  Congratulations!");
    } else if (died) {
        puts("You died.  Your relatives will be informed.");
    } else if (aborted) {
        puts("Chicken!");
    }

    return EXIT_SUCCESS;
}
