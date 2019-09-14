#include "FrameTimer.h"


FrameTimer::FrameTimer()
{
	last = std::chrono::steady_clock::now();
}

float FrameTimer::PerFrame()
{
	const auto oldtime = last;
	last = std::chrono::steady_clock::now();
	const std::chrono::duration<float> frameTime = last - oldtime;
	return frameTime.count();
}
