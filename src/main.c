//
// gp-c-daemon-template
// Copyright © 2024, Greg PFISTER. MIT License.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

enum gp_flag_e {
    FLAG_VERBOSE = 0b00000001
};

typedef enum gp_flag_e gp_flat_t;

enum gp_operation_e {
    OPERATION_ADD = 1,
    OPERATION_SUBSTRACT
};

typedef enum gp_operation_e gp_operation_t;

void print_info()
{
    printf("template | Kickstart a C daemon project\n");
    printf("Copyright (c) 2024, Greg PFISTER. MIT License\n");
}

void print_help()
{
    print_info();
    printf("\n");
    printf("Usage:\n");
    printf("    template [OPTIONS] -a <VALUE_TO_ADD>      [OPTIONS] <VALUE>\n");
    printf("    template [OPTIONS] -s <VALUE_TO_SUBTRACT> [OPTIONS] <VALUE>\n");
    printf("    template -h\n");
    printf("\n");
    printf("With:\n");
    printf("    - VALUE: an integer\n");
    printf("    - VALUE_TO_ADD: an integer\n");
    printf("    - VALUE_TO_SUBTRACT: an integer\n");
    printf("\n");
    printf("Options:\n");
    printf("    -a <VALUE_TO_ADD>: add VALUE_TO_ADD to VALUE\n");
    printf("    -s <VALUE_TO_SUBTRACT>: subtract VALUE_TO_SUBTRACT from VALUE\n");
    printf("    -v: display more information (verbose)\n");
    printf("    -h: print this help\n");
}

void print_missing_operation()
{
    printf("Either -a or -s option must be used\n");
    printf("\n");
    printf("For more detail, use:\n");
    printf("    template -h\n");
}

int main(const int arg_count, char* arg_value[])
{
    gp_flat_t flag = 0;
    gp_operation_t operation = 0;

    int opt;
    char* end_ptr;
    long long int value_to_add = 0;
    long long int value_to_subtract = 0;
    long long int value = (long long int)strtoll(arg_value[arg_count - 1], &end_ptr, 10);

    while ((opt = getopt(arg_count, arg_value, "a:s:hv")) != -1) {
        switch (opt) {
        case 'h':
            print_help();
            return 0;
        case 'a':
            operation = OPERATION_ADD;
            value_to_add = (long long int)strtoll(optarg, &end_ptr, 10);
            break;
        case 's':
            operation = OPERATION_SUBSTRACT;
            value_to_subtract = (long long int)strtoll(optarg, &end_ptr, 10);
            break;
        case 'v':
            flag |= FLAG_VERBOSE;
            break;
        default:
            printf("Unknown option: -%c\n", opt);
            return -1;
        }
    }

    long long int result;
    switch (operation) {
    case OPERATION_ADD:
        result = gp_add(value_to_add, value);
        if ((flag & FLAG_VERBOSE) == FLAG_VERBOSE) {
            printf("value       : %lld\n", value);
            printf("value to add: %lld\n", value_to_add);
            printf("Result      : %lld\n", result);
        } else {
            printf("%lld\n", result);
        }
        break;
    case OPERATION_SUBSTRACT:
        result = gp_subtract(value_to_subtract, value);
        if ((flag & FLAG_VERBOSE) == FLAG_VERBOSE) {
            printf("value            : %lld\n", value);
            printf("value to subtract: %lld\n", value_to_subtract);
            printf("Result           : %lld\n", result);
        } else {
            printf("%lld\n", result);
        }
        break;
    default:
        print_missing_operation();
        return -1;
        break;
    }

    return 0;
}