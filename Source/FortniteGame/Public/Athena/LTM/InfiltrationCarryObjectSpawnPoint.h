// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ScalableFloat.h"
#include "Building/BuildingGameplayActor.h"
#include "InfiltrationCarryObjectSpawnPoint.generated.h"

class AActor;
class AFortWaterBodyActor;
class UFortWaterInteractionComponent;
class USceneComponent;
enum class ESpawnPointState : uint8;

UENUM(BlueprintType)
enum class ESpawnPointState : uint8
{
	Inactive = 0,
	Active_CarryObjectInRange = 1,
	Active_CarryObjectOutOfRange = 2,
	IntelCaptured = 3,
	IntelDownloaded = 4,
};

UCLASS(HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class AInfiltrationCarryObjectSpawnPoint : public ABuildingGameplayActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	AActor* GetIntelActor() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ClientOnActive_CarryObjectInRange();

	UFUNCTION(BlueprintImplementableEvent)
	void ClientOnActive_CarryObjectOutOfRange();

	UFUNCTION(BlueprintImplementableEvent)
	void ClientOnIntelCaptured();

	UFUNCTION(BlueprintImplementableEvent)
	void ClientOnIntelDownloaded();

	UFUNCTION()
	void OnEnterWater(AFortWaterBodyActor* WaterBody, UFortWaterInteractionComponent* WaterInteractionComponent, bool bIsFirstBody);

	UFUNCTION()
	void OnHeldObjectDestroy();

	UFUNCTION()
	void OnHeldObjectDropped();

	UFUNCTION()
	void OnHeldObjectPickedUp();

	UFUNCTION()
	void OnHeldObjectPlaced();

	UFUNCTION()
	void OnHeldObjectThrown();

	UFUNCTION()
	void OnHeldObjectThrownLanded();

	UFUNCTION()
	void OnRep_CurrentState(ESpawnPointState OldState);

	UFUNCTION(BlueprintImplementableEvent)
	void ServerOnActive_CarryObjectInRange();

	UFUNCTION(BlueprintImplementableEvent)
	void ServerOnActive_CarryObjectOutOfRange();

	UFUNCTION(BlueprintImplementableEvent)
	void ServerOnIntelCaptured();

	UFUNCTION(BlueprintImplementableEvent)
	void ServerOnIntelDownloaded();

	UPROPERTY(ReplicatedUsing=OnRep_CurrentState)
	ESpawnPointState CurrentState;

	UPROPERTY(EditAnywhere, Category="InfiltrationCarryObjectSpawnPoint")
	FScalableFloat IsSpawnPointEnabledFloat;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> CachedSceneComponent;

	UPROPERTY(Transient, Replicated)
	TObjectPtr<AActor> CachedIntelActor;

	UPROPERTY(EditAnywhere, Category="InfiltrationCarryObjectSpawnPoint")
	TSubclassOf<AActor> IntelClassToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gameplay Tags")
	FGameplayTagContainer GameplayTags;

};

