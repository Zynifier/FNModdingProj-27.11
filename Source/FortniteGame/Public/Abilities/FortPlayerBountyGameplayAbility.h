// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Abilities/FortTransientQuestGameplayAbility.h"
#include "Components/FortGameStateComponentAthena_Quests.h"
#include "FortUrgentQuestData.h"
#include "FortPlayerBountyGameplayAbility.generated.h"

class AFortPlayerStateAthena;
class UFortQuestItemDefinition_Athena;

UCLASS()
class UFortPlayerBountyGameplayAbility : public UFortTransientQuestGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void BountyPoached();

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void CleanupBountyHunter() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void CleanupBountyProtector() const;

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void CleanupBountyTarget() const;

	UFUNCTION(BlueprintPure)
	bool GetIsPrimaryHunter() const;

	UFUNCTION(BlueprintPure)
	const TArray<AFortPlayerStateAthena*> GetTrackedBountyHunters() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerStateAthena* GetTrackedHunterBountyTarget() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerStateAthena* GetTrackedPrimaryHunter() const;

	UFUNCTION(BlueprintPure)
	AFortPlayerStateAthena* GetTrackedProtectorBountyTarget() const;

	UFUNCTION(BlueprintCallable)
	void SpectatorCompleteUrgentQuest(const FUrgentQuestData& UrgentQuestData, const FGameplayTag& CompletedEventTag);

	UFUNCTION(BlueprintCallable)
	void SpectatorFailUrgentQuest(const FUrgentQuestData& UrgentQuestData, const FGameplayTag& FailedEventTag);

	UFUNCTION(BlueprintCallable)
	void SpectatorShowUrgentQuestMessage(const FUrgentQuestData& UrgentQuestData);

	UFUNCTION(BlueprintCallable, BlueprintPure=false)
	void StartPlayerDuel() const;

	UPROPERTY(EditAnywhere, Category="FortPlayerBountyGameplayAbility", meta=(DisplayName="Poached Bounty Quest"))
	TSoftObjectPtr<UFortQuestItemDefinition_Athena> PoachedBountyQuestPtr;

	UPROPERTY(EditAnywhere, Category="FortPlayerBountyGameplayAbility")
	FBountyQuestSettings BountyQuestSettings;

	UPROPERTY(EditAnywhere, Category="FortPlayerBountyGameplayAbility")
	FGameplayTagQuery TargetFilter;

};

