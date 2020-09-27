#include <iostream>
#include <memory>
struct A{
    A(){
        a = std::unique_ptr<int>(new int);
    }
    std::unique_ptr<int> a;
    std::unique_ptr<int> make_a_unique()
    {
        return std::unique_ptr<int>();
    }
};
struct B {
    B() {
        std::cout << "default constructor\n";
    }
    B( const B& other)
    {
        std::cout << "copy constructor\n";
    }

    B& operator=(const B& other)
    {
        std::cout << "Copy assignment\n";
        return *this;
    }
};
B make_B()
{
    std::cout << "make_B one\n";
    return B();
}

/*
 *
 *
 *  string a = "Tam";
 *  a = lvalue;
 *  move sematic:
 *      + temporary object.
 *      + rvalue, lvalue.
 *
 *
 *  int x ;
 *  x = 10;
 *
 *  x -> lvalue;
 *  int x;
 *  int& getX() {
 *
 *      return x;
 *  }
 *
 *  getX is lvalue;
 *
 *  getX() = 4;
 *
 *  string getName()
 *  {
 *      return "tam";
 *  }
 *
 *  string a = getName();
 *
 *  getName is rvalue.
 *
 *
 */
template <typename ... T>
void f (T... t)
{
}
namespace {
    void myprintf(const char *s) {
        std::cout << "callhere";
        while (s && *s) {
            if (*s == '%' && *++s != '%')   // make sure that there wasn't meant to be more arguments
                // %% represents plain % in a format string
                throw std::runtime_error("invalid format: missing arguments");
            std::cout << "call base function";
            std::cout << *s++;
        }
    }

}

template<typename T, typename... Args>      // note the "..."
void myprintf(const char* s, T value, Args... args)   // note the "..."
{
    while (s && *s) {
        if (*s=='%' && *++s!='%') { // a format specifier (ignore which one it is)
            //std::cout << value;     // use first non-format argument
            myprintf(++s, args...);    // "peel off" first argument
        }
        std::cout << *s++;
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    {
        A a;
        std::unique_ptr<int> b;
        b = a.make_a_unique();
    }
    {
        B b;
        std::cout << "other one\n";
        B f;
        f = make_B();
        f = b;
    }
    {
        f();
        f(0.1);
        f(1.2343);
        f("help");
    }
    {
        const std::string pi = "pi";
        const char* m = "The value of %s is about %g (unless you live in %s).\n";
        myprintf(m,  pi, 3.14159,  "Indiana");
    }
    return 0;
}