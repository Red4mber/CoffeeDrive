#ifdef CF_PLATFORM_WINDOWS
	#ifdef CF_BUILD_DLL
		#define COFFEE_API __declspec(dllexport)
	#else
		#define COFFEE_API __declspec(dllimport)
	#endif
#else

	#error CoffeeDrive only supports windows for the moment !

#endif

// Bitfield
// Example:
// BIT(2) = 00000100 
// BIT(4) = 00010000 
// BIT(2) | BIT(4) = 00010100
#define BIT(x) (1 << x)