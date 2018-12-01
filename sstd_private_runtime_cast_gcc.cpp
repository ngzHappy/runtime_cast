#if !defined(_MSC_VER)

#include <typeindex>
#include <typeinfo>

/*
https://github.com/gcc-mirror/gcc/blob/master/libstdc%2B%2B-v3/libsupc%2B%2B/dyncast.cc
*/
#include <cxxabi.h>
namespace sstd {

    inline static void * private_runtime_dynamic_cast(
        void * argInput/*dynamic_cast<void *>*/,
        const std::type_info * argInputType/*type_id(remove_cvr)*/,
        const std::type_info * argOutputType/*type_id(remove_cvr)*/) {
        using namespace abi;
        return __dynamic_cast(argInput,
            static_cast<const __class_type_info*>(argInputType),
            static_cast<const __class_type_info*>(argOutputType), -1);
    }

}/*sstd*/


#endif









