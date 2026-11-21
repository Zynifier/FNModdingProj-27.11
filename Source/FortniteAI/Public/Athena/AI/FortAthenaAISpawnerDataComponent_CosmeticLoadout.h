// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_AIBotCosmeticBase.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortAthenaAISpawnerDataComponent_CosmeticLoadout.generated.h"

class UAnimInstance;
class UCustomCharacterPart;

USTRUCT()
struct FFortAthenaAIWeightedCosmeticLoadout
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaAIWeightedCosmeticLoadout", meta=(AllowPrivateAccess="true"))
	FFortAthenaLoadout CosmeticLoadout;

	UPROPERTY(EditAnywhere, Category="FortAthenaAIWeightedCosmeticLoadout", meta=(AllowPrivateAccess="true"))
	FScalableFloat Weight;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_CosmeticLoadout : public UFortAthenaAISpawnerDataComponent_AIBotCosmeticBase
{
	GENERATED_BODY()

private:
	UPROPERTY(meta=(AllowPrivateAccess="true"))
	FFortAthenaLoadout CosmeticLoadout_DEPRECATED;

	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	TArray<FFortAthenaAIWeightedCosmeticLoadout> WeightedLoadouts;

	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	TArray<TObjectPtr<UCustomCharacterPart>> CustomCharacterParts;

	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	bool bCanShowDefaultSkin;

	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	FGameplayTag FallbackTag;

	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UAnimInstance> AnimBPOverride;

	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	int32 AnimBPOverridePriority;

};

