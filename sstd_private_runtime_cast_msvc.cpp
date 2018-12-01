#if defined(_MSC_VER)

#include "sstd_private_runtime_class_information_memory.hpp"
#include <typeindex>
#include <typeinfo>
#include <Windows.h>

/*copy from msvc 2017 */
extern "C" void * __CLRCALL_OR_CDECL __RTDynamicCast(
    void * inptr,            // Pointer to polymorphic object
    LONG VfDelta,            // Offset of vfptr in object
    void * srcVoid,          // Static type of object pointed to by inptr
    void * targetVoid,       // Desired result of cast
    BOOL isReference)        // TRUE if input is reference, FALSE if input is ptr
    noexcept(false);

namespace sstd {

    inline static void * private_runtime_dynamic_cast(
        void * argInput/*dynamic_cast<void *>*/,
        const std::type_info * argInputType/*type_id(remove_cvr)*/,
        const std::type_info * argOutputType/*type_id(remove_cvr)*/) {
        /*
        https://github.com/scottslacksmith/__RTDynamicCast/blob/master/main.cpp
        */
        return __RTDynamicCast(
            argInput, 0,
            const_cast<std::type_info *>(argInputType),
            const_cast<std::type_info *>(argOutputType),
            false);
    }

    inline static abi_private::vector<std::type_index>
        private_runtime_get_bases(const std::type_info * arg) {
        return {};
    }

}/*namespace sstd*/

#endif

