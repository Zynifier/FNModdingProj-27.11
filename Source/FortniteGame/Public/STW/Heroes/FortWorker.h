// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "STW/Heroes/FortCharacter.h"
#include "FortWorker.generated.h"

class UFortItemIconDefinition;
class UFortWorkerType;

UCLASS(MinimalAPI, NotBlueprintable)
class UFortWorker : public UFortCharacter
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Item", meta=(DisplayName="GetWorkerType"))
	UFortWorkerType* GetWorkerTypeBP() const;

	UPROPERTY(BlueprintReadOnly, Category="FortWorker", meta=(DisplayName="CurrentBuildingInstanceId"))
	FString slotted_building_id;

	UPROPERTY()
	int32 building_slot_used;

	UPROPERTY(BlueprintReadOnly, Category="FortWorker")
	int32 gender;

	UPROPERTY()
	FString personality;

	UPROPERTY()
	FString set_bonus;

	UPROPERTY()
	FString portrait;

	UPROPERTY(BlueprintReadOnly, Category="FortWorker")
	FGameplayTagContainer PersonalityTag;

	UPROPERTY(BlueprintReadOnly, Category="FortWorker")
	FGameplayTagContainer SetBonusTag;

private:
	UPROPERTY(VisibleAnywhere, Transient, Category="Display")
	TSoftObjectPtr<UFortItemIconDefinition> IconDefinition;

};

