#include <iostream>

template<typename T>
class smart_ptr
{
public:
    smart_ptr(T* obj) // non explicit
        : obj_(obj)
    { }

    ~smart_ptr() {
        delete obj_;
    }

private:
    T* obj_;
};

template<>
class smart_ptr<void>
{
    class ideleter
    {
    public:
        virtual void delete_ptr(void*) = 0;
        virtual ~ideleter() { }
    };

    template<typename T>
    class deleter : public ideleter
    {
    public:
        virtual void delete_ptr(void* ptr) {
            delete static_cast<T*>(ptr);
        }
    };

public:
    template<typename T>
    smart_ptr(T* obj) // non explicit
        : deleter_(new deleter<T>)
        , obj_(obj)
    { }

    ~smart_ptr() {
        deleter_->delete_ptr(obj_);
        delete deleter_;
    }

private:
    ideleter* deleter_;
    void* obj_;
};

struct A
{
    A() {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }

    ~A() {
        std::clog << __PRETTY_FUNCTION__ << std::endl;
    }
};

int main()
{
    {
    smart_ptr<A> a(new A());
    //A::A()
    //A::~A()
    }

    {
    smart_ptr<void> a(new A());
    //A::A()
    //A::~A()
    }

    return 0;
}

