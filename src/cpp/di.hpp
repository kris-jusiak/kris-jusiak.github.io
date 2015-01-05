#ifndef DI_HPP
#define DI_HPP

#include <type_traits>
#include <utility>

#include <boost/mpl/has_xxx.hpp>
#include <boost/mpl/aux_/yes_no.hpp>

#define CTOR(T, ...)                \
    static void ctor(__VA_ARGS__);  \
    T(__VA_ARGS__)

namespace {

template<typename TArg>
class make_plain
{
    BOOST_MPL_HAS_XXX_TRAIT_DEF(element_type)

    template<typename T>
    struct remove_accessors
        : std::remove_cv<
            typename std::remove_pointer<
                typename std::remove_reference<T>::type
            >::type
        >
    { };

    template<typename T, typename = void>
    struct deref_element_type
    {
        typedef T type;
    };

    template<typename T>
    struct deref_element_type<
        T
      , typename std::enable_if<
            has_element_type<T>::value
        >::type
    >
    {
        typedef typename T::element_type type;
    };

public:
    typedef typename deref_element_type<
        typename remove_accessors<
            typename deref_element_type<
                typename remove_accessors<TArg>::type
            >::type
        >::type
    >::type type;
};

template<typename T>
class scope
{
public:
    template<typename... Args>
    scope(Args&&... args) {
        ptr_ = new T(std::forward<Args>(args)...);
    }

    ~scope() {
    }

    operator T() const {
        return *ptr_;
    }

    template<typename I>
    operator std::shared_ptr<I>() const {
        return std::shared_ptr<I>(ptr_);
    }

    template<typename I>
    operator std::unique_ptr<I>() const {
        return std::unique_ptr<I>(ptr_);
    }

private:
    T* ptr_;
};

template<typename... TDeps>
class di
{
    template<typename T>
    class has_ctor
    {
        template<typename C> static boost::mpl::aux::yes_tag test(decltype(&C::ctor));
        template<typename>   static boost::mpl::aux::no_tag  test(...);

    public:
        static const bool value = sizeof(test<T>(0)) == sizeof(boost::mpl::aux::yes_tag);
    };

    template<typename T>
    using plain = typename make_plain<T>::type;

    template<
        typename T
      , typename Ctor = plain<T>
    >
    using ctor = decltype(Ctor::ctor);

    template<typename T>
    class create_impl { };

    template<typename... TArgs>
    class create_impl<void(TArgs...)>
    {
        template<typename T, bool V = true>
        using enable_if_ctor =
            typename std::enable_if<
                has_ctor<plain<T>>::value == V
              , scope<T>
            >::type;

        template<typename T>
        using disable_if_ctor = enable_if_ctor<T, false>;

    public:
        template<typename T>
        static scope<plain<T>> execute() {
            return scope<plain<T>>(execute_impl<TArgs>()...);
        }

    private:
        template<typename T>
        static enable_if_ctor<T> execute_impl() {
            return create_impl<ctor<T>>::template execute<T>();
        }

        template<typename T>
        static disable_if_ctor<T> execute_impl() {
            return scope<T>();
        }
    };

public:
    template<typename T>
    scope<T> create() const {
        return create_impl<ctor<T>>::template execute<T>();
    }
};

} // namespace

#endif

