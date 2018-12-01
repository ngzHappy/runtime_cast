#pragma once

#include <set>
#include <list>
#include <vector>

namespace sstd{
    namespace abi_private{
        inline namespace runtime_class_information_ns{
            template<typename T>
            using vector = std::vector<T>;
            template<typename T,typename L=std::less<void>/**/>
            using set = std::set<T,L>;
            template<typename T>
            using list = std::list<T>;
        }/*runtime_class_information_ns*/
    }/*abi_private*/
}/*sstd*/



















