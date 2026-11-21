// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortWorldMultiItemXPComponent.generated.h"

class AFortPawn;
class AFortWeapon;
class UFortWorldMultiItem;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FItemSwitched);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FItemXpChanged, const float, XPDelta, const float, CurrentXPPercentage);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FPowerUpPending);

USTRUCT()
struct FMultiItemReplicationProxy
{
	GENERATED_BODY()

public:
	UPROPERTY()
	int32 SelectedItemIndex;

	UPROPERTY()
	int32 PendingPowerUpItemIndex;

	UPROPERTY()
	float ItemXPValue;

	UPROPERTY()
	float ItemXPChangeAmount;

	UPROPERTY()
	float ItemXPPercentage;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortWorldMultiItemXPComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MultiItem|Power Up")
	void FlushPendingPowerUp();

	UFUNCTION(BlueprintPure, Category="MultiItem|Power Up")
	float GetMultiItemXP() const;

	UFUNCTION(BlueprintPure, Category="MultiItem|Power Up")
	bool GetMultiItemXPPercentage(float& OutItemXPPercentage) const;

	UFUNCTION(BlueprintPure, Category="MultiItem")
	UFortWorldMultiItem* GetOwningMultiItem() const;

	UFUNCTION(BlueprintPure, Category="MultiItem")
	AFortPawn* GetOwningPawn() const;

	UFUNCTION(BlueprintPure, Category="MultiItem")
	int32 GetSelectedItemIndex() const;

	UFUNCTION(BlueprintPure, Category="MultiItem")
	AFortWeapon* GetWeaponActor() const;

	UFUNCTION(BlueprintPure, Category="MultiItem|Power Up")
	bool IsPowerUpPending() const;

	UFUNCTION(BlueprintImplementableEvent, Category="MultiItem")
	void OnItemSwitchedAwayFrom(const int32 CurrentItemIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="MultiItem")
	void OnItemSwitchedTo(const int32 CurrentItemIndex);

	UFUNCTION(BlueprintImplementableEvent, Category="MultiItem|Power Up")
	void OnItemXPChanged(const float XPChangeAmount, const float CurrentXP);

	UFUNCTION(BlueprintImplementableEvent, Category="MultiItem|Power Up")
	void OnPowerUpPending(const int32 CurrentItemIndex, const int32 PendingItemIndex);

protected:
	UPROPERTY(EditDefaultsOnly, Category="Multi-Item Replication")
	bool bReplicateOwningMultiItemToOwningClient;

private:
	UFUNCTION()
	void HandleItemSwitched(const int32 CurrentItemIndex);

	UFUNCTION()
	void HandleItemXPChanged(const float XPChangeAmount, const float CurrentXP);

	UFUNCTION()
	void HandlePowerUpPending(const int32 CurrentItemIndex, const int32 PendingItemIndex);

	UFUNCTION()
	void OnRep_OwningItemReplicationProxy(const FMultiItemReplicationProxy& OldItemReplicationProxy);

	UPROPERTY(Transient)
	TObjectPtr<AFortWeapon> OwningWeapon;

	UPROPERTY(Transient)
	TObjectPtr<AFortPawn> OwnerPawn;

	UPROPERTY(Transient)
	TObjectPtr<UFortWorldMultiItem> OwningMultiItem;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_OwningItemReplicationProxy)
	FMultiItemReplicationProxy OwningItemReplicationProxy;

};

