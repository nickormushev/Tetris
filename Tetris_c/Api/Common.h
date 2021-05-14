#pragma once

#define M_PI	3.14159265358979323846
#define M_PI_2	1.57079632679489661923
#define M_2_PI	6.28318530717958647692

#ifdef APIDLL_EXPORTS
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API __declspec(dllimport)
#endif

#define EXPORT_CALL __stdcall

namespace Common
{
	typedef int ErrorId;

	enum CommonErrorId
	{
		NoError = 0,
		UnexpectedError,
	};

	extern "C"
	{
		EXPORT_API Common::ErrorId EXPORT_CALL Init();
	}
}