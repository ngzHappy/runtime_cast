#if !defined(_MSC_VER)

#include "sstd_private_runtime_class_information_memory.hpp"
#include "sstd_get_type_info_from_type_index.hpp"
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
        /*向下类型转换*/
        auto varAns = abi::__dynamic_cast(argInput,
                                          static_cast<const abi::__class_type_info*>(argInputType),
                                          static_cast<const abi::__class_type_info*>(argOutputType), -1);
        if (varAns) {
            return varAns;
        }
        /*向上类型转换*/
        varAns = argInput;
        if (argInputType->__do_upcast(
                static_cast<const abi::__class_type_info*>(argOutputType),
                &varAns)) {
            return varAns;
        }
        return nullptr;
    }

    inline static abi_private::vector<std::type_index> get_direct_bases(const std::type_index & arg){
        const auto * varTypeInfo = get_type_info_from_type_index(arg);
        {/*一个父类...*/
            const abi::__si_class_type_info *  varSingleBase =
                    dynamic_cast< const abi::__si_class_type_info * >( varTypeInfo );
            if(varSingleBase){
                return {*(varSingleBase->__base_type) };
            }
        }
        {/*多个父类...*/
            const abi::__vmi_class_type_info * varMultiBases =
                    dynamic_cast< const abi::__vmi_class_type_info * >( varTypeInfo );
            if(varMultiBases){
                abi_private::vector<std::type_index> varAns;
                const auto & varBasesCount = varMultiBases->__base_count;
                const auto * varBasesInfor = varMultiBases->__base_info;
                varAns.reserve( varBasesCount );
                for( unsigned int varIndex =0 ;varIndex <varBasesCount; ++varIndex ){
                    auto varCurrentInfor = varBasesInfor + varIndex;
                    varAns.emplace_back( *(varCurrentInfor->__base_type) );
                }
                return std::move(varAns);
            }
        }
        return {};
    }

    inline static abi_private::vector<std::type_index>
    private_runtime_get_bases(const std::type_info * arg){
        abi_private::list<std::type_index> varDolist;
        abi_private::set<std::type_index> varAnsSet;
        varDolist.emplace_back(*arg);
        while(varDolist.empty() == false ){
            std::type_index varIndex = varDolist.front();
            varDolist.pop_front();
            if(false == varAnsSet.insert(varIndex).second){
                continue;
            }
            auto varTmp = get_direct_bases(varIndex);
            for(const auto & varI : varTmp ){
                varDolist.push_back(varI);
            }
        }
        return{varAnsSet.begin(),varAnsSet.end()};
    }

}/*sstd*/


#endif









