﻿#include "sstd_private_runtime_class_information_memory.hpp"
#include <type_traits>

#include "sstd_private_runtime_cast_msvc.cpp"
#include "sstd_private_runtime_cast_gcc.cpp"

namespace sstd{

    void * _0_runtime_dynamic_cast(
            void * argInput/*dynamic_cast<void *>*/,
            const std::type_info * argInputType/*type_id(remove_cvr)*/,
            const std::type_info * argOutputType/*type_id(remove_cvr)*/) {
        return private_runtime_dynamic_cast(argInput,
                                            argInputType,
                                            argOutputType);
    }

    abi_private::vector<std::type_index>
    _0_runtime_get_bases(const std::type_info * arg){
        return private_runtime_get_bases(arg);
    }

}/************************/










