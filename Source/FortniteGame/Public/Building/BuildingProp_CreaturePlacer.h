// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp_AISpawner.h"
#include "Minigame/FortMinigameTypes.h"
#include "BuildingProp_CreaturePlacer.generated.h"

class AController;
class AFortAIPawn;
class AFortMinigame;
class UFortDifficultyOptionEncounter_SpawnGroupProgression;
class UFortDifficultyOptionEncounter_SpawnLimitPawns;
class UFortGameplayReceiverMessageComponent;
class UFortGameplayTriggerMessageComponent;
class UPhysicsAsset;
class USkeletalMeshComponent;
enum class EFortMinigameState : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnCreatureVisualsLoadComplete);

USTRUCT(BlueprintType)
struct FSpawnGroupVisuals
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnGroupVisuals")
	TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnGroupProgression> SpawnGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpawnGroupVisuals")
	TSoftClassPtr<AFortAIPawn> AIPawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpawnGroupVisuals")
	TSoftObjectPtr<UPhysicsAsset> PhysicsAsset;

};

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_CreaturePlacer : public ABuildingProp_AISpawner
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="CreaturePlacer")
	USkeletalMeshComponent* GetCreatureSkeletalMeshComponent() const;

	UFUNCTION(BlueprintNativeEvent)
	void MinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState);

	UFUNCTION(BlueprintCallable)
	void UpdateCreatureVisuals();

	UPROPERTY()
	EFortMinigameState CurrentMinigameState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="BuildingProp_CreaturePlacer")
	TArray<FSpawnGroupVisuals> SpawnGroupVisuals;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreaturePlacer")
	TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnGroupProgression> SelectedSpawnGroup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="BuildingProp_CreaturePlacer")
	TSoftClassPtr<UFortDifficultyOptionEncounter_SpawnLimitPawns> SelectedSpawnLimit;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreaturePlacer")
	bool bHideVFX;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreaturePlacer")
	bool bEnabledOnGameState;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreaturePlacer")
	bool bDestroyPreviousOnSpawn;

	UPROPERTY(BlueprintReadWrite, Transient, Category="BuildingProp_CreaturePlacer")
	EFortMinigameState GameStateEnable;

	UPROPERTY(Transient, BlueprintAssignable)
	FOnCreatureVisualsLoadComplete OnCreatureVisualsLoadComplete;

	UPROPERTY(BlueprintReadOnly, Transient, Category="BuildingProp_CreaturePlacer")
	bool bCreatureVisualsDoneLoading;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="BuildingProp_CreaturePlacer", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayReceiverMessageComponent> TurnOnReceiverComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="BuildingProp_CreaturePlacer", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayReceiverMessageComponent> TurnOffReceiverComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Export, Category="BuildingProp_CreaturePlacer", meta=(EditInline="true"))
	TObjectPtr<UFortGameplayTriggerMessageComponent> CreatureKilledTransmitComponent;

private:
	UFUNCTION(BlueprintCallable)
	void OnTurnOffReceived(AController* TriggerInstigator);

	UFUNCTION(BlueprintCallable)
	void OnTurnOnReceived(AController* TriggerInstigator);

	UPROPERTY(Config)
	bool bEnableCreativeCreatureSpawners;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, AdvancedDisplay, Export, Category="Debug", meta=(AllowPrivateAccess="true", BlueprintProtected="true", EditInline="true"))
	TObjectPtr<USkeletalMeshComponent> CreatureSkeletalMeshComponent;

};

