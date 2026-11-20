#include <logic.hxx>
#include <iostream>

int main() {
    Var a("a");
    Var b("b");
    Var c("c");

    Implies bc(b, c);
    Implies abc(a, bc);

    std::cerr << modus_ponens(b, (Implies &) (*modus_ponens(a, abc)))->toString() << '\n';

    return 0;
}
