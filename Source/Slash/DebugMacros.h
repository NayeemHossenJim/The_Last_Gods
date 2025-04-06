#pragma once

#define DRAW_SPHERE(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 24.f, 24, FColor::Green, true);
#define DRAW_SPHERE_COLOR(Location,Color) DrawDebugSphere(GetWorld(), Location, 8.f, 12, Color, false, 5.f);
#define DRAW_LINE(Start, End) if(GetWorld()) DrawDebugLine(GetWorld(), Start, End, FColor::Green, true,-1.f,0,1.f);
#define DRAW_POINT(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 20.f, FColor::Green, true);
#define DRAW_VECTOR(Start, End) if(GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), Start, End, FColor::Green, true, -1.f, 0, 1.f); \
		DrawDebugPoint(GetWorld(), End, 20.f, FColor::Green, true); \
	}

#define DRAW_SPHERE_SingleFrame(Location) if(GetWorld()) DrawDebugSphere(GetWorld(), Location, 24.f, 24, FColor::Green, false, -1.f);
#define DRAW_LINE_SingleFrame(Start, End) if(GetWorld()) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false,-1.f,0,1.f);
#define DRAW_POINT_SingleFrame(Location) if(GetWorld()) DrawDebugPoint(GetWorld(), Location, 20.f, FColor::Green, false, -1.f);
#define DRAW_VECTOR_SingleFrame(Start, End) if(GetWorld()) \
	{ \
		DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, -1.f, 0, 1.f); \
		DrawDebugPoint(GetWorld(), End, 20.f, FColor::Green, false, -1.f); \
	}