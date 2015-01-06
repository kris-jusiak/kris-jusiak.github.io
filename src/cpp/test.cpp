#include "test.hpp"

test example_test = [] {
    expect(true);
};

test different_test = [] {
    expect_eq(1, 1);
};

test_skip skip_me_test = [] {
    expect_neq(1, 2);
};

test parametrized_test = [] {
    auto test = [](auto v) {
        expect(v > 0);
    };

    test(1);
    test(2);
};

