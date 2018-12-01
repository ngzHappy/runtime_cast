#pragma once

#include <type_traits>
#include "sstd_get_type_info_from_type_index.hpp"

namespace sstd {

#ifndef IF_CONSTEXPR_0_
#define IF_CONSTEXPR_0_ if
#endif

    extern void * _0_runtime_dynamic_cast(
        void * argInput/*dynamic_cast<void *>*/,
        const std::type_info * argInputType/*type_id(remove_cvr)*/,
        const std::type_info * argOutputType/*type_id(remove_cvr)*/);

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

    template<typename T>
    inline T * runtime_dynamic_cast(void * argData,
        const std::type_index & argType) {
        return runtime_dynamic_cast<T>(argData, get_type_info_from_type_index(argType));
    }

}/****/








