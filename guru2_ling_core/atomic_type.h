#pragma once

/**
 * 
 <cstdatomic>
 atomic_bool
 atomic_char
 atomic_schar
 atomic_uchar
 atomic_int
 atomic_uint
 atomic_short
 atomic_ushort
 atomic_long
 atomic_ulong
 atomic_llong
 atomic_ullong
 atomic_char16_t
 atomic_char32_t
 atomic_wchar_t
 
 std::atomic<T> t;
 */

/**
 * 
 atomic<float> af{1.2f};
 atomic<float> af1{af}; // error
 float f = af;
 float f1{af};

 = -> .load() .store() 为原子操作
 */