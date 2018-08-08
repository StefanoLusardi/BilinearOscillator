#pragma once

#ifdef BILINEAROSCILLATORCORE_EXPORTS
	#define CORE_API __declspec(dllexport)
#else
	#define CORE_API __declspec(dllimport)
#endif