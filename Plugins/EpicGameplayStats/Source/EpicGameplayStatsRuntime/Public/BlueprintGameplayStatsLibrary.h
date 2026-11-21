// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "GameplayStatTag.h"
#include "BlueprintGameplayStatsLibrary.generated.h"

UCLASS(MinimalAPI)
class UBlueprintGameplayStatsLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="GameplayStats", meta=(CompactNodeTitle="==", DisplayName="Equal (GameplayStatTag)"))
	static bool EqualEqual_GameplayStatTagGameplayStatTag(FGameplayStatTag A, FGameplayStatTag B);

	UFUNCTION(BlueprintPure, Category="GameplayStats", meta=(CompactNodeTitle="!=", DisplayName="Equal (GameplayStatTag)"))
	static bool NotEqual_GameplayStatTagGameplayStatTag(FGameplayStatTag A, FGameplayStatTag B);

};

