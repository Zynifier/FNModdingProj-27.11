// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortItemQuantityPair.h"
#include "FortItemQuantityPairUtilityLibrary.generated.h"

class UFortItemDefinition;

UCLASS()
class UFortItemQuantityPairUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	static TSoftObjectPtr<UFortItemDefinition> GetEditorOnlyItemDefinition(const FFortHiddenRewardQuantityPair& HiddenReward);

	UFUNCTION(BlueprintPure)
	static FFortHiddenRewardQuantityPair MakeFortHiddenRewardQuantityPairFromItemDefinition(const TSoftObjectPtr<UFortItemDefinition> ItemDefinitionToGrant, const int32 QuantityToGrant = 1);

	UFUNCTION(BlueprintCallable)
	static void SetEditorOnlyItemDefinition(UPARAM(ref) FFortHiddenRewardQuantityPair& HiddenReward, const TSoftObjectPtr<UFortItemDefinition> ItemDefinitionToGrant);

	UFUNCTION(BlueprintPure)
	static bool UsesEditorOnlyItemDefinition(const FFortHiddenRewardQuantityPair& HiddenReward);

};

