// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CharacterDefinition/NPCCharacterType.h"
#include "NPCCharacterType_Custom.generated.h"

class UFortAIPawnCustomizationDefinition;
class UFortAthenaAISpawnerData;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisplayName="NPC Character Type Custom"))
class UNPCCharacterType_Custom : public UNPCCharacterType
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Name", meta=(AllowPrivateAccess="true"))
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, Category="Internal")
	TSoftObjectPtr<UFortAIPawnCustomizationDefinition> DefaultCosmetics;

	UPROPERTY(EditDefaultsOnly, Category="Internal")
	TSoftClassPtr<UFortAthenaAISpawnerData> AISpawnerData;

	UPROPERTY(EditDefaultsOnly, Category="Internal")
	TSoftClassPtr<UFortAthenaAISpawnerData> PlayerSpawnerData;

};

