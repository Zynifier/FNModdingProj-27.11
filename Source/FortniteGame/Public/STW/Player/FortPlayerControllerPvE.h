// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "Items/FortQuickBars.h"
#include "Player/FortPlayerControllerZone.h"
#include "FortPlayerControllerPvE.generated.h"

class ABuildingSMActor;
class AFortClientAnnouncement_Basic;
class AFortPlayerStatePvE;
class UFortGadgetItemDefinition;
enum class EFortIdleDetectionState : uint8;
enum class EFortQuickBars : uint8;

UENUM()
enum class EFortIdleCheckResult : uint8
{
	Invalid = 0,
	ActivityDetected = 1,
	Idle = 2,
	IdlePastMaxTime = 3,
};

UCLASS(MinimalAPI, HideCategories=("Collision", "Rendering", "Transformation"))
class AFortPlayerControllerPvE : public AFortPlayerControllerZone
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Game|Player")
	virtual void PreparePlayerForDisplay();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void RefreshHarvestingWeapon();

	UFUNCTION()
	void RequestIdleDetectionState(EFortIdleDetectionState NewIdleDetectionState, const FString& Reason);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void ResetPlayerDeathReportForForcePlayerRestart();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerTriggerSetupTeleportCameraEvent();

	UPROPERTY(EditDefaultsOnly, Category="FortPlayerControllerPvE")
	bool bForceAutoSlotWeaponsAtStart;

	UPROPERTY(Config)
	bool bRecycleBrokenWeapons;

protected:
	UFUNCTION(Client, Reliable)
	void ClientHideIdleWarning();

	UFUNCTION(Client, Reliable)
	void ClientShowIdleWarning(float TimeUntilKick);

	UFUNCTION(Client, Reliable)
	void ClientUpdateQuickBarRecordsCache(const FQuickBar& PrimaryQuickBarRecord, const FQuickBar& SecondaryQuickBarRecord);

	UFUNCTION()
	void HandleQuickBarChanged(EFortQuickBars QuickBarType, const TArray<int32>& Slots);

	UFUNCTION(Server, Reliable)
	void ServerFriendPlayerAdded(AFortPlayerStatePvE* FriendPS, bool bIsEpicFriend);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerUpdateQuickBarRecordsCache(const FQuickBar& PrimaryQuickBarRecord, const FQuickBar& SecondaryQuickBarRecord);

	UPROPERTY(Transient)
	TObjectPtr<ABuildingSMActor> AutoImproveBuildingActor;

private:
	UPROPERTY(Transient)
	FQuickBar CachedPrimaryQuickBarRecord;

	UPROPERTY(Transient)
	FQuickBar CachedSecondaryQuickBarRecord;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortGadgetItemDefinition>> HeroLoadoutGadgets;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortGadgetItemDefinition>> HeroAbilityGadgets;

	UPROPERTY(Transient)
	TObjectPtr<AFortClientAnnouncement_Basic> IdleWarningAnnouncement;

	UPROPERTY(Transient)
	FTimerHandle IdleWarningUpdateTimerHandle;

	UPROPERTY(Transient)
	float IdleKickEstimatedTime;

};

