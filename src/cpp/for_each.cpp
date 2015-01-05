#include <cassert>
#include <boost/utility/enable_if.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/pop_front.hpp>
#include <boost/mpl/front.hpp>
#include <boost/mpl/empty.hpp>
#include <boost/mpl/int.hpp>

namespace mpl = boost::mpl;

namespace {

template<typename Seq, typename F>
inline static void for_each(F, typename boost::enable_if<mpl::empty<Seq>>::type* = 0) { }

template<typename Seq, typename F>
inline static void for_each(F p_f, typename boost::disable_if<mpl::empty<Seq>>::type* = 0) {
    p_f.template operator()<typename mpl::front<Seq>::type>();
    for_each<typename mpl::pop_front<Seq>::type>(p_f);
}

} // namespace

class accumulate
{
public:
    explicit accumulate(int& result)
        : result(result)
    { }

    template<typename T>
    void operator()() {
        result += T::value;
    }

private:
    int& result;
};

int main() {
    int result = 0;
    for_each<mpl::vector<mpl::int_<40>, mpl::int_<2>>>(accumulate(result));
    assert(42 == result);

    return 0;
}

