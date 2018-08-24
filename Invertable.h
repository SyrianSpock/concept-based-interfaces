#include <memory>
#include <type_traits>
#include <utility>

/// Apply some (inverse) operation to a type B which yields a result of type A
template<typename A, typename B>
class Invertable
{
public:
    Invertable() = default;

    Invertable(const Invertable&) = delete;
    Invertable(Invertable&&) = default;

    template <typename T>
    Invertable(T&& impl) : m_impl(new model_t<typename std::decay<T>::type>(std::forward<T>(impl))) {}

    Invertable& operator=(const Invertable&) = delete;
    Invertable& operator=(Invertable&&) = default;

    template <typename T>
    Invertable& operator=(T&& impl)
    {
        m_impl.reset(new model_t<typename std::decay<T>::type>(std::forward<T>(impl)));
        return *this;
    }

    friend A invert(const Invertable& d, B in)
    {
        return d.m_impl->do_invert(in);
    }

private:
    struct concept_t
    {
        virtual ~concept_t() {}
        virtual A do_invert(B) const = 0;
    };
    template <typename T>
    struct model_t : public concept_t
    {
        model_t() = default;
        model_t(const T& v) : m_data(v) {}
        model_t(T&& v) : m_data(std::move(v)) {}

        A do_invert(B in) const override
        {
            return invert(m_data, in);
        }

        T m_data;
    };

    std::unique_ptr<concept_t> m_impl;
};
