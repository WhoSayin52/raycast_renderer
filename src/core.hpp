#ifndef CORE_HPP
#define CORE_HPP

#include <cstdint>

#include <cstddef>
#include <cstdint>
#include <cstdbool>


using int32 = int32_t;
using int64 = int64_t;

using uint32 = uint32_t;
using uint64 = uint64_t;

using wchar = wchar_t;

using bool32 = int32;

constexpr uint64 kilobytes(uint64 bytes) { return bytes * 1024LL; }
constexpr uint64 megabytes(uint64 bytes) { return kilobytes(bytes) * 1024LL; }
constexpr uint64 gigabytes(uint64 bytes) { return megabytes(bytes) * 1024LL; }
constexpr uint64 terabytes(uint64 bytes) { return gigabytes(bytes) * 1024LL; }

#if !defined(NDEBUG)
#define ASSERT(x)               \
        if(!(x)){               \
                *(int*)0 = 0;   \
        }
#else
#define ASSERT(x)
#endif // !defined(NDEBUG)

#endif // CORE_HPP
