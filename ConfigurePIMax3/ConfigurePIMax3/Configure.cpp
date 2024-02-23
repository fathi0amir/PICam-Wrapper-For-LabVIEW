#pragma once
#include <math.h>

_declspec(dllexport) void ARRAYfloor1D2(double* input,
    int input_length,
    int* output);

_declspec(dllexport) void ARRAYfloor1D2(double* input,
    int input_length,
    int* output)
{
    int i;

    /* Calculate the floor of the square of each value. */
    for (i = 0; i < input_length; i++)
    {
        output[i] = (int)floor(input[i] * input[i]);
    }
}