#pragma once

#ifdef VLK_PLATFORM_WINDOWS
	#ifdef VLK_BUILD_DLL
		#define VLK_API __declspec(dllexport)
	#else
		#define VLK_API __declspec(dllimport)
	#endif
#else
	#error Vulkano only supports Windows
#endif