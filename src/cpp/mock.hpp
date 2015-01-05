class example
{
    typedef std::function<void(int)> func_t;

public:
    explicit example(const func_t& f);
};

//usage
class yac
{
public:
    void execute(int);
};

int main() {
    yac yac_;
    auto e = std::make_unique<example>(std::bind(&func::execute, yac_));
    e...
}

//test
namespace GT = ::testing;

class example_test : GT::Test
{
public:
    MOCK_METHOD1(void, execute(int));

    example_test()
        : sut(std::bind(&example_test::execute, this))
    { }

    example sut;
};

TEST_F(example_test, test)
{
    EXPECT_CALL(*this, execute(GT::_))...

    sut...
}

