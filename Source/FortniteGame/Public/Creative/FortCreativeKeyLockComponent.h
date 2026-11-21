// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Misc/Guid.h"
#include "FortItemVariantHandle.h"
#include "Minigame/FortMinigameItemContainerComponent.h"
#include "FortCreativeKeyLockComponent.generated.h"

class APawn;
class UFortItemDefinition;
enum class ECreativeKeyLockState : uint8;

UENUM(BlueprintType)
enum class ECreativeKeyLockState : uint8
{
	LOCKED = 0,
	UNLOCKED = 1,
	INVALID = 2,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FKeyDefinitionUpdated, FItemVariantHandle, NewKeyDefinition);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FKeyLockStateChanged, ECreativeKeyLockState, NewState);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FKeysConsumed, int32, NumKeysConsumed);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLockEvent);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRemainingKeysChanged, int32, RemainigKeys);

USTRUCT()
struct FCreativeKeyLockItemData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly, SaveGame, Category="CreativeKeyLockItemData", meta=(AllowedClasses="/Script/FortniteGame.FortWorldItemDefinition"))
	TSoftObjectPtr<UFortItemDefinition> ItemDefinition;

	UPROPERTY(EditInstanceOnly, SaveGame, Category="CreativeKeyLockItemData")
	FGuid ItemVariantGuid;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortCreativeKeyLockComponent : public UFortMinigameItemContainerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	int32 BlueprintGetKeyAmountOnPlayer(APawn* Pawn);

	UFUNCTION(BlueprintCallable)
	bool BlueprintHasKeysToInteract(APawn* Pawn);

	UFUNCTION(BlueprintPure)
	ECreativeKeyLockState GetCurrentState() const;

	UFUNCTION(BlueprintPure)
	bool IsLocked() const;

	UFUNCTION(BlueprintCallable)
	bool Lock(APawn* Pawn);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void Reset(bool DeferredReset);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetKeyItemDefinition(const FItemVariantHandle& ItemHandle);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetRequiredAllKeysAtOne(bool Required);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetRequiredKeys(int32 Amount);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetShouldConsumeKey(bool ShouldConsume);

	UFUNCTION(BlueprintCallable)
	bool Unlock(APawn* Pawn);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortCreativeKeyLockComponent")
	ECreativeKeyLockState InitialState;

	UPROPERTY(BlueprintAssignable)
	FKeyDefinitionUpdated OnKeyDefinitionUpdated;

	UPROPERTY(BlueprintAssignable)
	FLockEvent OnUnlocked;

	UPROPERTY(BlueprintAssignable)
	FLockEvent OnLocked;

	UPROPERTY(BlueprintAssignable)
	FKeyLockStateChanged OnLockStateChanged;

	UPROPERTY(BlueprintAssignable)
	FRemainingKeysChanged OnRemainingKeysUpdated;

	UPROPERTY(BlueprintAssignable)
	FKeysConsumed OnKeysConsumed;

	UPROPERTY(EditDefaultsOnly, Category="Editor")
	FText EditorDisplayName;

	UPROPERTY(EditDefaultsOnly, Category="Editor")
	FText EditorDescription;

	UPROPERTY(EditDefaultsOnly, Category="Editor")
	FGameplayTagContainer FilterTags;

	UPROPERTY(EditDefaultsOnly, Category="Editor", meta=(Categories="Creative"))
	FGameplayTagQuery RequiredFilterTagQuery;

protected:
	UFUNCTION()
	void OnRep_CurrentState();

	UFUNCTION()
	void OnRep_RemainingKeysToUnlock();

	UFUNCTION()
	void OnRep_UnlockKeyItem();

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_CurrentState, Category="FortCreativeKeyLockComponent")
	ECreativeKeyLockState CurrentState;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortCreativeKeyLockComponent")
	int32 RequiredKeysToUnlockAmount;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing=OnRep_RemainingKeysToUnlock, Category="FortCreativeKeyLockComponent")
	int32 RemainingKeysToUnlockAmount;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortCreativeKeyLockComponent")
	bool bRequireAllKeysAtOnce;

	UPROPERTY(SaveGame)
	TSoftObjectPtr<UFortItemDefinition> UnlockKeyDefinitionSoftPointer_DEPRECATED;

	UPROPERTY(EditInstanceOnly, SaveGame, ReplicatedUsing=OnRep_UnlockKeyItem, Category="FortCreativeKeyLockComponent")
	FCreativeKeyLockItemData UnlockKeyItem;

};

