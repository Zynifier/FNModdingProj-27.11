// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHolsterWeaponSourceInterface.generated.h"

UINTERFACE(MinimalAPI, BlueprintType)
class UFortHolsterWeaponSourceInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IFortHolsterWeaponSourceInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Holster")
	bool CanApplyHolster(const FName& HolsterId) const;

};

