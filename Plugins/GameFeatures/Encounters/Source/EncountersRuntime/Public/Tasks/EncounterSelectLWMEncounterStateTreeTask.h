// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "EncounterSelectLWMEncounterStateTreeTask.generated.h"

class AActor;
class UDataRegistry;
class UFortAthenaLivingWorldEncounter;

USTRUCT(meta=(Category="Encounter", DisplayName="Select LWM Encounter"))
struct FEncounterSelectLWMEncounterStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FEncounterSelectLWMEncounterStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	TObjectPtr<UDataRegistry> FactionRegistry;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer Capabilities;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagQuery LWMEncounterTagQuery;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

	UPROPERTY(EditAnywhere, Category="Output")
	TSoftObjectPtr<UFortAthenaLivingWorldEncounter> LWMEncounter;

};

