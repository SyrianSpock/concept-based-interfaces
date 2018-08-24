#include <memory>
#include <type_traits>
#include <utility>

template<typename Input, typename Output>
class Applyable
{
public:
    Applyable() = default;

    Applyable(const Applyable&) = delete;
    Applyable(Applyable&&) = default;

    template <typename T>
    Applyable(T&& impl) : m_impl(new model_t<typename std::decay<T>::type>(std::forward<T>(impl))) {}

    Applyable& operator=(const Applyable&) = delete;
    Applyable& operator=(Applyable&&) = default;

    template <typename T>
    Applyable& operator=(T&& impl)
    {
        m_impl.reset(new model_t<typename std::decay<T>::type>(std::forward<T>(impl)));
        return *this;
    }

    friend Output apply(const Applyable& d, Input in)
    {
        return d.m_impl->do_apply(in);
    }

private:
    struct concept_t
    {
        virtual ~concept_t() {}
        virtual Output do_apply(Input) const = 0;
    };
    template <typename T>
    struct model_t : public concept_t
    {
        model_t() = default;
        model_t(const T& v) : m_data(v) {}
        model_t(T&& v) : m_data(std::move(v)) {}

        Output do_apply(Input in) const override
        {
            return apply(m_data, in);
        }

        T m_data;
    };

    std::unique_ptr<concept_t> m_impl;
};
