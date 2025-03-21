#include "Items/Item.h"
#include "Slash/DebugMacros.h"
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
}

float AItem::TrasformedSin()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCos()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	
	FVector Location = GetActorLocation();
	FVector ForwardVector = GetActorForwardVector() * 100;
	FVector End = Location + ForwardVector;
	DRAW_SPHERE_SingleFrame(Location);
	DRAW_VECTOR_SingleFrame(Location, End);
}