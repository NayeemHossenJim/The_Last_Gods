#include "Items/Item.h"
#include "Slash/DebugMacros.h"
AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	FVector Location = GetActorLocation();
	FVector ForwardVector = GetActorForwardVector() * 100;
	FVector End = Location + ForwardVector;
	DRAW_SPHERE(Location);
	DRAW_VECTOR(Location, End);
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}