
#include "../sstd_runtime_class_information.hpp"

class A11 {
public:
    virtual ~A11() {
    }
};

class A12 {
public:
    virtual ~A12() {
    }
};

class A13 :
    public A11,
    public A12 {
public:
    virtual ~A13() {
    }
};

class A14 : public A13 {
public:
    virtual ~A14() {
    }
};

class A15 {
public:
    virtual ~A15() {
    }
};

#include <iostream>
#include <cassert>
#include <QtWidgets/QtWidgets>

int main(int argc, char ** argv) {

    {
        A14 * a14 = new A14;
        A12 * a12 = a14;
        void * va14 = dynamic_cast<void *>(a12);
        const auto ta14 = &typeid(*a12);
        assert(a14 == sstd::runtime_dynamic_cast<A14>(a12, &typeid(A12)));
        assert(a12 == sstd::runtime_dynamic_cast<A12>(va14, ta14));
        assert(a12 == sstd::runtime_dynamic_cast<A12>(va14, std::type_index(*ta14)));
    }

    {
        auto varBA14 = sstd::runtime_get_bases(&typeid(A14));
        for( const auto & varI : varBA14 ){
            std::cout << varI.name() << std::endl ;
        }
        assert(varBA14.size() == 4);
    }

    {
        auto var = sstd::runtime_get_bases( typeid(int) );
        assert(var.size() == 1);
    }

    QApplication varApp{ argc , argv };
    QWidget widget;
    widget.show();
    return varApp.exec();

}


















