// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CreativeMoveToolLightPreviewOverride.generated.h"

UINTERFACE(BlueprintType, Blueprintable)
class UCreativeMoveToolLightPreviewOverride : public UInterface
{
	GENERATED_BODY()
};

class ICreativeMoveToolLightPreviewOverride
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool ShouldOverrideMoveToolLightPreviewVisibility();

};

