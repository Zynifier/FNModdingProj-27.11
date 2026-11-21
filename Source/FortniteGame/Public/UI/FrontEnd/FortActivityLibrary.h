// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortActivityLibrary.generated.h"

UCLASS()
class UFortActivityBlueprintLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="FortActivityLibrary")
	static bool ShouldDisplayCreatorCodeAsDisplayName(const FString& CreatorAccountId);

};

