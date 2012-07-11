# Games
These are my C implementations of the games which can be found in the book [Basic Computer Games](http://www.atariarchives.org/basicgames/).

## Build instructions
You can build the games without any special libraries yet.  A simple `make GAME` is sufficient, unless otherwise declared.

### sinuswave.c
*sinuswave.c* uses the math library.  Therefore you have to specify `-lm`.

    gcc -o sinuswave sinuswave.c -std=c99 -lm
