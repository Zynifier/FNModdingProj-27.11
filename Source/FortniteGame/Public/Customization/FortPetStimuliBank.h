// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "FortPetStimuliBank.generated.h"

USTRUCT()
struct FPetResponseFromQuestSystem
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="PetResponseFromQuestSystem")
	FDataTableRowHandle ObjectiveStatHandle;

	UPROPERTY(EditAnywhere, Category="PetResponseFromQuestSystem")
	FGameplayTag ResponseTag;

	UPROPERTY(EditAnywhere, Category="PetResponseFromQuestSystem")
	float ResponseDuration;

};

UCLASS()
class UFortPetStimuliBank : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortPetStimuliBank")
	TArray<FPetResponseFromQuestSystem> QuestTriggers;

};

