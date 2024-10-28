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
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>

#include <cmocka.h>

static void test_add(void **state)
{
    assert_int_equal(gp_add(2, 1), 3);
}

static void test_subtract(void **state)
{
    assert_int_equal(gp_subtract(2, 1), -1);
}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_add),
        cmocka_unit_test(test_subtract),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}