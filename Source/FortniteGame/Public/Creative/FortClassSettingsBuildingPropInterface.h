// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortClassSettingsBuildingPropInterface.generated.h"

class UFortWorldItemDefinition;

UINTERFACE(BlueprintType, Blueprintable)
class UFortClassSettingsBuildingPropInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortClassSettingsBuildingPropInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	TArray<UFortWorldItemDefinition*> GetCreativeClassInventory();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	FText GetCreativeClassName();

};

