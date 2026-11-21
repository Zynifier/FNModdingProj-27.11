// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/MathFwd.h"
#include "FortCreativeBudgetLibrary.generated.h"

class AActor;
class APlayerController;

UCLASS(meta=(ScriptName="CreativeBudget"))
class UFortCreativeBudgetLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Creative|Budget")
	static bool CanPlaceClassInstances(APlayerController* Controller, const TArray<TSubclassOf<AActor>> Classes, const FVector& Location);

	UFUNCTION(BlueprintPure, Category="Creative|Budget")
	static bool CanPlaceInstanceOfClass(APlayerController* Controller, TSubclassOf<AActor> Class, const FVector& Location);

};

