/*==================================================================================================
*   Project             : Platform Types for STM32F765 (Cortex-M7)
*   File Name           : Platform_Types.h
*   AUTOSAR Version     : R22-11
*   Description         : AUTOSAR platform-dependent type definitions and symbols
*==================================================================================================*/

#ifndef PLATFORM_TYPES_H
#define PLATFORM_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

/* ===== Autosar vendor/version IDs (opcional; ajusta si usas Dem/Det) =========================== */
#define PLATFORM_VENDOR_ID                      (0u)
#define PLATFORM_AR_RELEASE_MAJOR_VERSION       (4u)
#define PLATFORM_AR_RELEASE_MINOR_VERSION       (9u)   /* Classic line >=4.3; doc set R22-11 */
#define PLATFORM_AR_RELEASE_REVISION_VERSION    (0u)
#define PLATFORM_SW_MAJOR_VERSION               (1u)
#define PLATFORM_SW_MINOR_VERSION               (0u)
#define PLATFORM_SW_PATCH_VERSION               (0u)

/* ===== CPU characteristics (AUTOSAR 8.3) ====================================================== */
/* CPU type */
#define CPU_TYPE_8      8
#define CPU_TYPE_16     16
#define CPU_TYPE_32     32
#define CPU_TYPE_64     64
#define CPU_TYPE        CPU_TYPE_32   /* Cortex-M7 is a 32-bit core */

/* Bit order within a register (LSB first on ARM) */
#define MSB_FIRST       0
#define LSB_FIRST       1
#define CPU_BIT_ORDER   LSB_FIRST

/* Byte order in memory (Little Endian on STM32F7) */
#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST  1
#define CPU_BYTE_ORDER  LOW_BYTE_FIRST

/* ===== Boolean type (R22-11: implement using C99 _Bool) ======================================= */
#ifndef __cplusplus
typedef _Bool boolean;   /* use C99 built-in type */
#else
typedef bool  boolean;   /* in C++ use built-in bool */
#endif

#ifndef TRUE
#define TRUE  ((boolean)1)
#endif

#ifndef FALSE
#define FALSE ((boolean)0)
#endif

/* ===== Integer types (AUTOSAR 8.2.x) ========================================================== */
typedef signed char        sint8;
typedef unsigned char      uint8;

typedef short              sint16;
typedef unsigned short     uint16;

typedef int                sint32;     /* on ARM EABI, int is 32-bit */
typedef unsigned int       uint32;

typedef long long          sint64;
typedef unsigned long long uint64;

/* ===== Optimized “least” types (AUTOSAR 7.4 / 8.2.10–8.2.15) ================================== */
/* Chosen to match or exceed the specified minimum widths on this 32-bit target */
typedef uint8              uint8_least;
typedef uint16             uint16_least;
typedef uint32             uint32_least;

typedef sint8              sint8_least;
typedef sint16             sint16_least;
typedef sint32             sint32_least;

/* ===== Floating-point types (AUTOSAR 8.2.16–8.2.17; IEEE-754) ================================= */
typedef float              float32;
typedef double             float64;

/* Optional limits (R22-11 introduced limit macros; define if useful for your stack) */
#define FLOAT32_MIN     1.17549435e-38f
#define FLOAT32_MAX     3.40282347e+38f
#define FLOAT32_EPSILON 1.19209290e-07f

#define FLOAT64_MIN     2.2250738585072014e-308
#define FLOAT64_MAX     1.7976931348623157e+308
#define FLOAT64_EPSILON 2.2204460492503131e-16

/* ===== Void pointer helpers (AUTOSAR 8.2.18–8.2.19) =========================================== */
typedef void*       VoidPtr;
typedef const void* ConstVoidPtr;

/* ===== Endianness helper macros (opcionales para drivers) ===================================== */
#define PLATFORM_IS_LITTLE_ENDIAN   (CPU_BYTE_ORDER == LOW_BYTE_FIRST)
#define PLATFORM_IS_BIG_ENDIAN      (CPU_BYTE_ORDER == HIGH_BYTE_FIRST)

/* ===== Qualifiers (comunes en AUTOSAR; por si tus drivers los usan) =========================== */
#ifndef AUTOMATIC
#define AUTOMATIC
#endif
#ifndef TYPEDEF
#define TYPEDEF
#endif
#ifndef NULL_PTR
#define NULL_PTR ((void*)0)
#endif

#ifdef __cplusplus
}
#endif
#endif /* PLATFORM_TYPES_H */
