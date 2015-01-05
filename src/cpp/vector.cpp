#define BOOST_MPL_LIMIT_VECTOR_SIZE 70

#if (BOOST_MPL_LIMIT_VECTOR_SIZE <= 50)
    #define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
    #include <boost/mpl/vector.hpp>
#else
    #include <boost/preprocessor/iterate.hpp>
    #include <boost/mpl/vector/vector50.hpp>

    namespace boost {
    namespace mpl {
    #define BOOST_PP_ITERATION_PARAMS_1 \
        (3,(51, BOOST_MPL_LIMIT_VECTOR_SIZE, <boost/mpl/vector/aux_/numbered.hpp>))
    #include BOOST_PP_ITERATE()
    } // namespace mpl
    } // namespace boost

    #define BOOST_MPL_PREPROCESSING_MODE
    #include <boost/mpl/vector.hpp>
    #undef BOOST_MPL_PREPROCESSING_MODE
#endif

int main() {
    typedef boost::mpl::vector<
        int, int, int, int, int, int, int, int, int, int /* 10 */
      , int, int, int, int, int, int, int, int, int, int /* 20 */
    > vector_20_t;

    typedef boost::mpl::vector<
        int, int, int, int, int, int, int, int, int, int /* 10 */
      , int, int, int, int, int, int, int, int, int, int /* 20 */
      , int, int, int, int, int, int, int, int, int, int /* 30 */
      , int, int, int, int, int, int, int, int, int, int /* 40 */
      , int, int, int, int, int, int, int, int, int, int /* 50 */
      , int, int, int, int, int, int, int, int, int, int /* 60 */
      , int, int, int, int, int, int, int, int, int, int /* 70 */
    > vector_70_t;

    return 0;
}

