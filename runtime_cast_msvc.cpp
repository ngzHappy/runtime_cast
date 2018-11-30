#include <Windows.h>
extern "C" void * __CLRCALL_OR_CDECL __RTDynamicCast(
    void * inptr,            // Pointer to polymorphic object
    LONG VfDelta,            // Offset of vfptr in object
    void * srcVoid,          // Static type of object pointed to by inptr
    void * targetVoid,       // Desired result of cast
    BOOL isReference)        // TRUE if input is reference, FALSE if input is ptr
    noexcept(false);

void * runtime_cast(
    void * argInput/*dynamic_cast<void *>*/,
    const std::type_info * argInputType/*type_id*/,
    const std::type_info * argOutputType) {
    /*
    https://github.com/scottslacksmith/__RTDynamicCast/blob/master/main.cpp
    */
    return __RTDynamicCast(
        argInput, 0,
        const_cast<std::type_info *>(argInputType),
        const_cast<std::type_info *>(argOutputType),
        false);
}



