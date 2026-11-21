// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortAssetDataUtilityToolBlueprintLibrary.generated.h"

class UObject;

UCLASS()
class UFortAssetDataUtilityToolBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static FText GetClassToolTipText(const UClass* ClassToGetToolTip);

};

