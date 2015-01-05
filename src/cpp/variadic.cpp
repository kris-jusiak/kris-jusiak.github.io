class app
{
public:
    template<typename... Args>
    explicit app(Args&&... args)
        : v{std::forward<Args>(args)...}
    { };

    or

    template<typename... Args>
    explicit app(Args&&... args) {
        std::initializer_list<int>{(v.push_back(std::forward<Args>(args)), 0)...};

    };

    or

    template<typename... Args>
    explicit app(Args&&... args) {
        int dummy[]{0, (v.push_back(std::forward<Args>(args)), 0)...};
    };

private:
    std::vector<std::shared_ptr<I>> v;
};

