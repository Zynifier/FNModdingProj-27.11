// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "FortAthenaLivingWorldPrefab.h"
#include "LivingWorldEncounterPrefab.generated.h"

class AActor;
class UEncounterItem;
class UEncounterItemDefinition;
class UEncounterManagerComponent;

USTRUCT()
struct FEncounterPrefabInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	TObjectPtr<UEncounterItemDefinition> EncounterDefinition;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayTag EncounterIdentifierTag;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FScalableFloat Weight;

};

UCLASS(MinimalAPI, HideCategories=("Level", "Game|Damage"), SparseClassDataType=BuildingActorClassData)
class ALivingWorldEncounterPrefab : public AFortAthenaLivingWorldPrefab
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Encounter", meta=(DisplayName="Encounter Definitions"))
	TArray<FEncounterPrefabInfo> EncounterEntries;

	UPROPERTY(Transient)
	TObjectPtr<UEncounterItem> EncounterItem;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_EncounterDefinition)
	TWeakObjectPtr<UEncounterItemDefinition> EncounterDefinition;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> ReservoirActorOverride;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UEncounterManagerComponent> EncounterManager;

private:
	UFUNCTION()
	void OnRep_EncounterDefinition();

};

