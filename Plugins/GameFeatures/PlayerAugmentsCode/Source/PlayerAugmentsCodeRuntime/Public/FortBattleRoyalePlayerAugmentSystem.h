// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_PlayerAugmentPersistence.h"
#include "FortBattleRoyalePlayerAugmentSystem.generated.h"

class AController;
class AFortPlayerPawn;
class APawn;
class UFortPlayerAugmentItemDefinition;
enum class EBattleRoyaleBPAugmentLogVerbosity : uint8;
enum class EFortBRAugmentSystemCastResult : uint8;

UENUM(BlueprintType)
enum class EBattleRoyaleBPAugmentLogVerbosity : uint8
{
	Log = 0,
	Verbose = 1,
};

UENUM(BlueprintType)
enum class EFortBRAugmentSystemCastResult : uint8
{
	Valid = 0,
	Invalid = 1,
};

USTRUCT(BlueprintType)
struct FFortAugmentPassiveUnlockResult
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortAugmentPassiveUnlockResult")
	TObjectPtr<UFortPlayerAugmentItemDefinition> UnlockedAugment;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="FortAugmentPassiveUnlockResult")
	bool bAlreadyInInventory;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortBattleRoyalePlayerAugmentSystem : public UFortControllerComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBattleRoyaleMatchAugmentResetDelegate);

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void AuthoritySetServerGrantingStartedTimestamp(float ServerTimestamp);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="GetAugmentController", ExpandEnumAsExecs="OutExec"))
	void BP_GetAugmentController(EFortBRAugmentSystemCastResult& OutExec, AController*& OutController);

	UFUNCTION(BlueprintCallable, meta=(DisplayName="GetAugmentPlayerPawn", ExpandEnumAsExecs="OutExec"))
	void BP_GetAugmentPlayerPawn(EFortBRAugmentSystemCastResult& OutExec, AFortPlayerPawn*& OutFortPlayerPawn);

	UFUNCTION(BlueprintNativeEvent)
	FFortAugmentPassiveUnlockResult ChooseUnlockFromList(const TArray<FPlayerAugmentLockStatus>& LockedList);

	UFUNCTION(BlueprintPure)
	float GetServerGrantingStartedTimestamp() const;

	UFUNCTION(BlueprintCallable)
	void ResetMatchAugments();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	FFortAugmentPassiveUnlockResult TryClaimUnlock();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void TryIncrementUnlockRollCount();

	UPROPERTY(BlueprintAssignable)
	FOnBattleRoyaleMatchAugmentResetDelegate OnMatchAugmentsResetEvent;

protected:
	UFUNCTION(BlueprintCallable)
	void BlueprintAugmentLog(const FString& Message, EBattleRoyaleBPAugmentLogVerbosity Verbosity = EBattleRoyaleBPAugmentLogVerbosity::Log, bool bAutonomousProxyOnly = false);

	UFUNCTION()
	void HandlePossessedPawnChanged(APawn* OldPawn, APawn* NewPawn);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMatchAugmentsReset();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPossedPawnChanged(APawn* OldPawn, APawn* NewPawn);

	UFUNCTION(BlueprintImplementableEvent)
	void OnServerAugmentGrantTimestampReplicated(float ServerGrantStartTimestamp);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortBattleRoyalePlayerAugmentSystem")
	bool bEnableAugmentCollectionUnlocking;

	UPROPERTY(EditDefaultsOnly, Category="FortBattleRoyalePlayerAugmentSystem")
	FScalableFloat NumRollsForUnlock;

	UPROPERTY(EditDefaultsOnly, Category="FortBattleRoyalePlayerAugmentSystem")
	FScalableFloat EnableUnlocking;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortBattleRoyalePlayerAugmentSystem")
	FScalableFloat EnableBRAugmentSystem;

private:
	UFUNCTION()
	void OnRep_ServerGrantingStartedTimestamp();

	UPROPERTY(ReplicatedUsing=OnRep_ServerGrantingStartedTimestamp)
	float ServerGrantingStartedTimestamp;

};

