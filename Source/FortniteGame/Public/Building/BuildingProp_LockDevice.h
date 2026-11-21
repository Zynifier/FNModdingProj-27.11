// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "LockableInterface.h"
#include "BuildingProp_LockDevice.generated.h"

class AActor;
class ABuildingActor;
class AController;
class AFortMinigame;
class UBoxComponent;
enum class EFortMinigameState : uint8;
enum class ELockState : uint8;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLockStateChangeEvent, ELockState, NewLockState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLockableObjectChangeEvent, AActor*, LockableActorFound);

UCLASS(BlueprintType, Blueprintable, HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_LockDevice : public ABuildingProp
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual void Close(AController* ControllerInstigator);

	UFUNCTION(BlueprintCallable)
	void FindAndStoreAClosestLockableActor();

	UFUNCTION(BlueprintCallable)
	AActor* FindLockableActor();

	UFUNCTION()
	void HandleLockableObjectDestruction(AActor* ActorDestroyed);

	UFUNCTION(BlueprintCallable)
	void HandleMinigameEnded();

	UFUNCTION(BlueprintCallable)
	void HandleMinigameStarted();

	UFUNCTION()
	void HandleMinigameStateChanged(AFortMinigame* Minigame, EFortMinigameState NewMinigameState);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual void LockObject(AController* ControllerInstigator);

	UFUNCTION()
	void OnRep_CurrentLockState();

	UFUNCTION()
	void OnRep_LockableObject();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual void Open(AController* ControllerInstigator);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Lockable Actor Change"))
	void ReceiveOnLockableActorChange();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Lock State Change"))
	void ReceiveOnLockStateChange();

	UFUNCTION(BlueprintCallable)
	void SetHighLightToLockableActor(ABuildingActor* BuildingActor, bool bEnable);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ToggleLockedState(AController* ControllerInstigator);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ToggleOpenState(AController* ControllerInstigator);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	virtual void UnlockObject(AController* ControllerInstigator);

	UPROPERTY(BlueprintAssignable)
	FLockableObjectChangeEvent OnLockableActorChange;

	UPROPERTY(BlueprintAssignable)
	FLockStateChangeEvent OnLockStateChange;

	UPROPERTY(BlueprintReadWrite, Transient, Export, Category="BuildingProp_LockDevice", meta=(EditInline="true"))
	TArray<TObjectPtr<UBoxComponent>> InteractionCollisionComponents;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="BuildingProp_LockDevice")
	float SearchAreaSize;

	UPROPERTY(BlueprintReadOnly, Transient, ReplicatedUsing=OnRep_LockableObject, Category="BuildingProp_LockDevice")
	TObjectPtr<AActor> LockableObject;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentLockState, Category="BuildingProp_LockDevice")
	ELockState CurrentLockState;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, SaveGame, Replicated, Category="UserOptions|Basic")
	bool HideInteractionWhenLocked;

};

