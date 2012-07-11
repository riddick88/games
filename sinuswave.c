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

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int main(void)
{
	bool step;
	/* 51 is the maximum amount of spaces that can be computed with
	   26 + 25 * sin(x) */
	char indent[52];
	double x;
	for (x = 0.0, step = 0; x < 40; x += 0.25, step = !step)
	{
		int spaces = 26 + 25 * sin(x);
		for (int i = 0; i < spaces; i++)
			indent[i] = ' ';
		indent[spaces] = '\0';
		fputs(indent, stdout);

		if (!step)
			puts("Sinus");
		else
			puts("Wave");
	}
}
