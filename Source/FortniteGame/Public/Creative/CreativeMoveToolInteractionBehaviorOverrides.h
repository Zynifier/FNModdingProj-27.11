// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CreativeMoveToolInteractionBehaviorOverrides.generated.h"

class UObjectInteractionBehavior;

UINTERFACE(BlueprintType, Blueprintable)
class UCreativeMoveToolInteractionBehaviorOverrides : public UInterface
{
	GENERATED_BODY()
};

class ICreativeMoveToolInteractionBehaviorOverrides
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	bool IsInteractionAllowedInCreative(UObjectInteractionBehavior* InteractionBehavior) const;

};

