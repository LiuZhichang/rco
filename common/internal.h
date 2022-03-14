#pragma once

#define RCO_STATIC    static
#define RCO_INLINE    inline
#define RCO_NOEXCEPT  noexcept 
#define RCO_CONSTEXPR constexpr

#define RCO_CAS

#if defined(__linux__)

	#define RCO_PLATFORM_LINUX

#elif defined(__WIN32__)

	#define RCO_PLATFORM_WIN32

#elif defined(__APPLE__)

	#define RCO_PLATFORM_APPLE

#endif
