#include "stranger_things.hh"

int main() {
    for (auto &fun : upside_down::Ctx::battles()) {
        fun();
    }
}