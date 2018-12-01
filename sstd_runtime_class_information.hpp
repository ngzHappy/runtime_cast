#pragma once

#include <type_traits>
#include "sstd_get_type_info_from_type_index.hpp"
#include "sstd_private_runtime_class_information_memory.hpp"

namespace sstd {

#ifndef IF_CONSTEXPR_0_
#define IF_CONSTEXPR_0_ if
#endif

    extern void * _0_runtime_dynamic_cast(
        void * argInput/*dynamic_cast<void *>*/,
        const std::type_info * argInputType/*type_id(remove_cvr)*/,
        const std::type_info * argOutputType/*type_id(remove_cvr)*/);

    extern abi_private::vector<std::type_index>
    _0_runtime_get_bases(const std::type_info * arg);

    /*运行时类型识别*/
    template<typename T>
    inline T * runtime_dynamic_cast(void * argData,
        const std::type_info * argType) {
        using T_ = typename std::remove_cv<typename std::remove_reference<T>::type >::type ;
        IF_CONSTEXPR_0_(true == std::is_class<T_>::value ) {
            const static auto * varTarget = &typeid(T_);
            return reinterpret_cast<T_ *>(_0_runtime_dynamic_cast(argData, argType, varTarget));
        } else {
            return nullptr;
        }
    }

    /*运行时类型识别*/
    template<typename T>
    inline T * runtime_dynamic_cast(void * argData,
        const std::type_index & argType) {
        return runtime_dynamic_cast<T>(argData, get_type_info_from_type_index(argType));
    }

    /*运行时获得所有基类*/
    inline abi_private::vector<std::type_index> runtime_get_bases(const std::type_info * arg){
        return _0_runtime_get_bases(arg);
    }

    /*运行时获得所有基类*/
    inline abi_private::vector<std::type_index> runtime_get_bases(const std::type_index & arg){
        return runtime_get_bases(get_type_info_from_type_index(arg));
    }

}/****/








