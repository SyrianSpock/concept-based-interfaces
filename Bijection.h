#include "Applyable.h"
#include "Invertable.h"

template<typename Input, typename Output>
struct Bijection : Applyable<Input, Output>, Invertable<Input, Output>
{
    template <typename T>
    Bijection(T&& impl) : Applyable<Input, Output>(impl), Invertable<Input, Output>(impl) {}
};
