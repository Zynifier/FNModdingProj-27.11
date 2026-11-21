// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "GameplayVolume.h"
#include "LevelSaveSpawnableInterface.h"
#include "Quests/Processors/ISpatialEventConsumerInterface.h"
#include "EncounterGameplayVolume.generated.h"

class ABuildingActor;
class AEncounterMobAnchor;
class IEncounterPointProviderInterface;
class UEncounterStateTreeComponent;

UCLASS()
class ENCOUNTERSRUNTIME_API AEncounterGameplayVolume : public AGameplayVolume, public ILevelSaveSpawnable, public ISpatialEventConsumerInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Encounter")
	bool IsDoneCleaningUp() const;

	UFUNCTION(BlueprintImplementableEvent, Category="Encounter")
	void OnCleanup();

protected:
	UPROPERTY(EditDefaultsOnly, Category="Encounter")
	bool bShouldPersist;

	UPROPERTY(VisibleAnywhere, Category="EncounterGameplayVolume")
	FGuid SavedActorGuid;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Export, Category="EncounterGameplayVolume", meta=(EditInline="true"))
	TObjectPtr<UEncounterStateTreeComponent> EncounterStateTreeComponent;

private:
	UPROPERTY(Transient)
	TArray<TScriptInterface<IEncounterPointProviderInterface>> EncounterPointProviders;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<AEncounterMobAnchor>> EncounterAnchors;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<ABuildingActor>> BuildingActors;

};

