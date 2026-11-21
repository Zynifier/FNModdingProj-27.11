// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterDefinition/NPCCharacterType.h"
#include "NPCCharacterType_FromPreset.generated.h"

class UFortAthenaAISpawnerData;
class UPrimaryDataAsset;

USTRUCT(BlueprintType)
struct FCharacterTypePreset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Spawner Data")
	TSoftClassPtr<UFortAthenaAISpawnerData> SpawnerData;

	UPROPERTY(EditAnywhere, Category="Additional Data")
	TSoftClassPtr<UPrimaryDataAsset> AdditionalData;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, AutoExpandCategories=("Subtype"), meta=(DisplayName="NPC Character Type From Preset"))
class UNPCCharacterType_FromPreset : public UNPCCharacterType
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	TSoftClassPtr<UFortAthenaAISpawnerData> GetAIToSpawn() const;

protected:
	UFUNCTION()
	TArray<FString> GetAvailableAIs() const;

	UPROPERTY(EditAnywhere, Category="Name", meta=(AllowPrivateAccess="true"))
	FText DisplayName;

	UPROPERTY(EditAnywhere, Category="Subtype", meta=(GetOptions="GetAvailableAIs"))
	FString SelectedAI;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Subtype")
	FCharacterTypePreset SelectedPreset;

	UPROPERTY(EditDefaultsOnly, Category="EditorOnly")
	TArray<FCharacterTypePreset> Presets;

};

