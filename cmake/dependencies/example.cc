#include "aa.hh"
#include <cstdlib>
#include <cstdio>

#define assert_eq(exp, real) do { \
    if ((exp) != (real)) { \
        fprintf(stderr, "Expected <%d> to be <%d>\n", (real), (exp)); \
        exit(123); \
    } \
    } while (0)

int main() {
    assert_eq(5, foo(3, 2));
    return 0;
}
