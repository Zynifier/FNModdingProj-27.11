// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_AIPawnCosmeticBase.h"
#include "FortAthenaAISpawnerDataComponent_AIPawnCosmeticCustomization.generated.h"

class UFortAIPawnCustomizationDefinition;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_AIPawnCosmeticCustomization : public UFortAthenaAISpawnerDataComponent_AIPawnCosmeticBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	FGameplayTag FallbackTag;

	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	TObjectPtr<UFortAIPawnCustomizationDefinition> CustomizationDefinition;

	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	bool bCanUnloadCustomization;

};

