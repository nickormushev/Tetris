#pragma once

#include "Common.h"

namespace Time
{
	typedef unsigned long long Timestamp;

	extern "C"
	{
		EXPORT_API Timestamp EXPORT_CALL GetStableTime();
		EXPORT_API Timestamp EXPORT_CALL GetUTCTime();
		EXPORT_API Timestamp EXPORT_CALL GetLocalTime();
		EXPORT_API Timestamp EXPORT_CALL GetLocalTimeOffset();
		EXPORT_API void EXPORT_CALL WaitFor(Timestamp time);
		EXPORT_API void EXPORT_CALL WaitUntilStableTime(Timestamp time);
		EXPORT_API void EXPORT_CALL WaitUntilUTCTime(Timestamp time);
		EXPORT_API void EXPORT_CALL WaitUntilLocalTime(Timestamp time);
	}
}
