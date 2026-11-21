// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMovementCancellableAbilityInterface.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class UFortMovementCancellableAbilityInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortMovementCancellableAbilityInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	float GetAbilityLeashDistance() const;

};

