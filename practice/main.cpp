#include <iostream>
#include <vector>
#include <set>
using namespace std;

template<typename A, typename B>
struct stuff {
    stuff() {
        
    }
    stuff(A a_in, B b_in) {
        i = a_in;
        this->j = b_in;
    }
    A i;
    B j;
    void print() {
      std::cout << i << std::endl;
      std::cout << j << std::endl;
    }
};
class A {
public:
    virtual std::string getString() {
        return "Class A";
    }
};
class B: public A {
public:
    std::string getString() {
        return "Class B";
    }

};
class C: public B {
public:
    std::string getString() {
        return "Class C";
    }

};
class D {
public:
    std::string getString() {
        return "Class D";
    }

};

long long solve (int n, vector<int>& arr) {
    // Write your code here
    set<int> aSet;
    for(int i=0;i < arr.size(); ++i) {
        for (int j = i + 1; j < arr.size(); j++) {
            if( aSet.find(arr[i] + arr[i]) == aSet.end()) {
                aSet.insert(arr[i] + arr[j]);
            }
        }
    }
    auto max_value = max_element(aSet.begin(), aSet.end());
    int total = 0;
    for(int i : arr) {
        if (i <= *max_value ) {
            total += i;
        }
    }
    return total;
}
int main() {
    /*std::cout << "Hello, World!" << std::endl;
    A* a = new B();
    B* b = dynamic_cast<B*>(a);
    if (b == nullptr){
        std::cout<<"what the fuck it me" << std::endl;
        return 0;
    }
    std::cout << a->getString() << std::endl;
    stuff<int, int> what_the_stuff;
    what_the_stuff.i = 200;
    what_the_stuff.j = 100;
    what_the_stuff.print();*/

    int n,a;
    cin >> n;
    vector<int> arr;
    for(int i_arr = 0; i_arr < n; i_arr++){
        cin >> a;
        arr.push_back(a);
    }
    long long out_;
    out_ = solve(n,arr);
    cout << out_;
    return 0;
}

/*
 * 5
 * 10
 * 4
 * 4
 * 4
 * 5
 *
 * output:
 * 17
 *       10 4  4  4  5
 *    10    14 14 14 14
 *    4  14 8  8  8  9
 *    4  14
 *    4
 *    5
 */