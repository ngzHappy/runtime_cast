#pragma once

#include "sstd_get_type_info_from_type_index.hpp"

namespace sstd {

    extern void * _0_runtime_dynamic_cast(
        void * argInput/*dynamic_cast<void *>*/,
        const std::type_info * argInputType/*type_id(remove_cvr)*/,
        const std::type_info * argOutputType/*type_id(remove_cvr)*/);

    template<typename T>
    inline T * runtime_dynamic_cast(void * argData,
        const std::type_info * argType) {
        using T_ = std::remove_cv_t< std::remove_reference_t<T> >;
        static_assert (false == std::is_array_v<T_>, "");
        static_assert (true == std::is_class_v<T_>, "");
        const static auto * varTarget = &typeid(T_);
        return reinterpret_cast<T_ *>(_0_runtime_dynamic_cast(argData, argType, varTarget));
    }

    template<typename T>
    inline T * runtime_dynamic_cast(void * argData,
        const std::type_index & argType) {
        return runtime_dynamic_cast<T>(argData, get_type_info_from_type_index(argType));
    }

}/****/








