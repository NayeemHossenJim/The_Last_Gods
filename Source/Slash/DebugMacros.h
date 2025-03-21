#pragma once

#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 24.f, 24, FColor::Green, true);
#define DRAW_LINE(Start, End) if(GetWorld()) DrawDebugLine(GetWorld(), Start, End, FColor::Green, true,-1.f,0,1.f);
#define DRAW_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 20.f, FColor::Green, true);
#define DRAW_VECTOR(Start, End) if(GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), Start, End, FColor::Green, true, -1.f, 0, 1.f); \
		DrawDebugPoint(GetWorld(), End, 20.f, FColor::Green, true); \
	}