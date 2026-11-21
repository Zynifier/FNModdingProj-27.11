// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/Color.h"
#include "ScalableFloat.h"
#include "Athena/Markers/FortWorldMarker.h"
#include "Building/BuildingGameplayActor.h"
#include "BuildingGameplayActorSpawnChip.generated.h"

class AFortPlayerControllerAthena;
class AFortPlayerStateAthena;
class UUserWidget;

USTRUCT()
struct FRebootCardReplicatedState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float ChipExpirationServerStartTime;

	UPROPERTY()
	TObjectPtr<AFortPlayerStateAthena> PlayerState;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Game|Damage"), SparseClassDataType=BuildingGameplayActorClassData)
class ABuildingGameplayActorSpawnChip : public ABuildingGameplayActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent)
	bool CanHandleCleanupEvents() const;

	UFUNCTION(BlueprintNativeEvent, Category="Resurrection")
	void OnDestroyPickup();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category="Resurrection")
	void PickUp(AFortPlayerControllerAthena* PickingUpController);

	UPROPERTY(BlueprintReadOnly, Transient, Category="Spawn", meta=(ExposeOnSpawn="true"))
	TObjectPtr<AFortPlayerControllerAthena> OwnerPlayerController;

	UPROPERTY(Transient)
	FUniqueNetIdRepl OwnerPlayerId;

	UPROPERTY(Transient)
	TObjectPtr<AFortPlayerStateAthena> OwnerPlayerState;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection")
	FScalableFloat ChipExpirationLength;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_RebootCardReplicatedState)
	FRebootCardReplicatedState RebootCardReplicatedState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="MarkerDetails")
	FLinearColor MarkerDetailsColor;

	UPROPERTY(Transient)
	FMarkerID ResurrectionChipMarkerID;

	UPROPERTY(EditAnywhere, Category="Resurrection")
	TSubclassOf<UUserWidget> IndicatorClass;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection|Interaction")
	FText InteractSubText;

	UPROPERTY(EditDefaultsOnly, Category="Resurrection|Interaction")
	FLinearColor InteractSubTextColor;

	UPROPERTY(Transient)
	bool bAutoAcquireSpawnChip;

	UPROPERTY(Transient, Replicated)
	uint8 SquadId;

private:
	UFUNCTION()
	void OnRep_RebootCardReplicatedState();

};

