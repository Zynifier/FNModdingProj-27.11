// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "HurdleType.h"
#include "HurdleLibrary.generated.h"

class ACharacter;

UCLASS()
class VAULTINGCODERUNTIME_API UHurdleLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Hurdle")
	static bool PerformHurdleTargeting(const ACharacter* Character, FHurdleInputConfigCache& HurdleInputConfig, FHurdleTargetingData& OutTargetingData, bool bIsAutoHurdle);

};

