#pragma once

#include <typeinfo>
#include <typeindex>

inline const std::type_info * get_type_info_from_type_index(const std::type_index & arg){
    class alignas(std::type_index) TypeInfo_{
    public:
        const std::type_info * value;
    };
    static_assert ( sizeof(TypeInfo_) == sizeof(std::type_index),"" ) ;
    return reinterpret_cast<const TypeInfo_ *>(&arg)->value;
}


