// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Athena/AI/FortAthenaAISpawnerDataComponent_AIBotCosmeticBase.h"
#include "FortAthenaAISpawnerDataComponent_CosmeticLibrary.generated.h"

class UFortAthenaAIBotCosmeticLibraryData;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UFortAthenaAISpawnerDataComponent_CosmeticLibrary : public UFortAthenaAISpawnerDataComponent_AIBotCosmeticBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	UFortAthenaAIBotCosmeticLibraryData* GetAICosmeticLibraryData() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	int32 GetAICosmeticLibraryDataIndex() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="Cosmetic", meta=(AllowPrivateAccess="true", AssetBundles="Server"))
	TArray<TSoftObjectPtr<UFortAthenaAIBotCosmeticLibraryData>> CosmeticLibraries;

	UPROPERTY(EditDefaultsOnly, Category="Cosmetic")
	FScalableFloat DefaultCosmeticLibraryWeight;

	UPROPERTY(EditAnywhere, Category="Cosmetic", meta=(AllowPrivateAccess="true"))
	FGameplayTag PredefinedCosmeticSetTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Emote", meta=(AllowPrivateAccess="true"))
	FScalableFloat EmotesMaxCount;

	UPROPERTY(EditAnywhere, Category="Randomness")
	FScalableFloat bUseFixedSeed;

	UPROPERTY(EditAnywhere, Category="Randomness")
	FScalableFloat FixedSeed;

};

