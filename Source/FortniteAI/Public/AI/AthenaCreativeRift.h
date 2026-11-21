// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingRift.h"
#include "FortEncounterSettings.h"
#include "AthenaCreativeRift.generated.h"

class AActor;
class ABuildingProp_AISpawner;
class AFortPlayerPawn;
class UFortAIManagerMinigameComponent;
class UPrimitiveComponent;
class USphereComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingActorClassData)
class AAthenaCreativeRift : public ABuildingRift
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BlueprintShowRift();

	UFUNCTION()
	void NotifyActorDespawnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USphereComponent> DespawnSphereComponent;

private:
	UPROPERTY()
	TObjectPtr<ABuildingProp_AISpawner> ParentTrap;

	UPROPERTY()
	FFortEncounterSettings OverrideEncounterSettings;

	UPROPERTY(Transient)
	bool bHasLoadedSettings;

	UPROPERTY()
	TArray<TObjectPtr<AFortPlayerPawn>> DespawnPlayerOverlaps;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortAIManagerMinigameComponent> CachedAIMinigamecomponent;

};

