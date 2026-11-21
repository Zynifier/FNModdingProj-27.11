// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Player/FortCheatManager.h"
#include "FortPlayerAugmentCheatManager.generated.h"

UCLASS()
class UFortPlayerAugmentCheatManager : public UChildCheatManager
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void CollectAllPlayerAugments() const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void CollectPlayerAugment(const FString& TagMatch) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ForceSelectionAugments(const FString& AugmentNameFirst, const FString& AugmentNameSecond);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveAugment(const FString& AugmentName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveAugmentCount(const FString& AugmentName, int32 AddCount);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void GiveAugmentToBots(const FString& AugmentName);

	UFUNCTION(BlueprintCallable, Exec)
	void LogPlayerAugmentsLockStatus();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RemoveAllAugments();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RemoveAllAugmentsFromBots();

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RemoveAugment(const FString& AugmentName);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void RemoveAugmentCount(const FString& AugmentName, int32 RemoveCount);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ResetAugmentGrantingToSeed(const int32 Seed);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void ServerLogDynamicWeightsForPlayer(bool bVeryDetailedReport);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void SetPlayerAugmentRollCountSinceLastUnlock(const int32 RollCount);

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void StartAugmentGrantingFlow();

};

