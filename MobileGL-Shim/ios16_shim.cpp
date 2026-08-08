// MobileGL iOS 16 ABI Shim
// Provides missing libc++ symbols when running on iOS 16
// Build: clang++ -std=c++17 -arch arm64 -mios-version-min=16.0 -dynamiclib -o libMobileGL_iOS16_shim.dylib ios16_shim.cpp

#include <cstddef>
#include <cstdint>

extern "C" {

// FNV-1a hash implementation for std::__1::__hash_memory
std::size_t __ZNSt3__113__hash_memoryEPKvm(const void* ptr, std::size_t len) {
    const uint8_t* data = static_cast<const uint8_t*>(ptr);
    std::size_t hash = 14695981039346656037ULL;
    for (std::size_t i = 0; i < len; ++i) {
        hash ^= static_cast<std::size_t>(data[i]);
        hash *= 1099511628211ULL;
    }
    return hash;
}

__attribute__((visibility("default")))
std::size_t _ZNSt3__113__hash_memoryEPKvm(const void* ptr, std::size_t len) {
    return __ZNSt3__113__hash_memoryEPKvm(ptr, len);
}

} // extern "C"
