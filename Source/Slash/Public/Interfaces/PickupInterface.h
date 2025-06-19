#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PickupInterface.generated.h"

UINTERFACE(MinimalAPI)
class UPickupInterface : public UInterface
{
	GENERATED_BODY()
};

class SLASH_API IPickupInterface
{
	GENERATED_BODY()

public:
	virtual void SetOverlappingItem(class AItem* Item);
	virtual void AddSouls(class ASoul* Soul);
};
