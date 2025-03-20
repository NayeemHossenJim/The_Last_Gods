#include "Items/Item.h"

AItem::AItem()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Item spawned"));
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, TEXT("Item spawned"));
	}
}

void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("DeltaTime : %f"),DeltaTime);
	if (GEngine)
	{
		FString Name = GetName();
		UE_LOG(LogTemp, Warning, TEXT("Name : %s"), *Name); 
		GEngine->AddOnScreenDebugMessage(1, 5.f, FColor::Red, TEXT("Item spawned"));
	}
}