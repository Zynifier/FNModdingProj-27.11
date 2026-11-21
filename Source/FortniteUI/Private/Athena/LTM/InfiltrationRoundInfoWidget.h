// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/PerkIntroScreenWidget.h"
#include "InfiltrationRoundInfoWidget.generated.h"

class AFortGameplayMutator;
class IInfiltrationRoundInfoMutatorInterface;
class USoundBase;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UInfiltrationRoundInfoWidget : public UPerkIntroScreenWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	uint8 GetAttackingTeam() const;

	UFUNCTION(BlueprintPure)
	uint8 GetDefendingTeam() const;

	UFUNCTION(BlueprintPure)
	int32 GetFirstRound() const;

	UFUNCTION(BlueprintPure)
	USoundBase* GetRoundIntroFactionSound(bool bLocalTeamIsAttackers) const;

	UFUNCTION(BlueprintPure)
	void GetRoundResultsText(FText& OutResultsText, bool bLocalTeamIsAttackers, bool bLocalTeamIsWinners) const;

	UFUNCTION(BlueprintPure)
	uint8 GetViewingTeam() const;

	UFUNCTION(BlueprintPure)
	bool HasWinningTeam() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerAttacking() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerAttackingNextRound() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerDefending() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerDefendingNextRound() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnReadyToShowIntro();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnReadyToShowStuff(int32 CurrentRound, uint8 LastRoundWinningTeam);

	UFUNCTION(BlueprintCallable)
	void SetWinningTeam(uint8 NewWinningTeam);

	UFUNCTION(BlueprintPure)
	bool ShouldModifyAttackingDefendingText(FText& OutAttackingDefendingText, bool bLocalTeamIsAttackers) const;

	UFUNCTION(BlueprintPure)
	bool ShouldPlayFactionIntro() const;

	UFUNCTION(BlueprintPure)
	bool ShouldPlayRoundEndStinger() const;

	UFUNCTION(BlueprintPure)
	bool ShouldSkipWinLossScreen() const;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationRoundInfoWidget")
	int32 CachedRoundIndex;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationRoundInfoWidget")
	uint8 WinningTeam;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationRoundInfoWidget")
	uint8 AttackingTeam;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationRoundInfoWidget")
	uint8 DefendingTeam;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationRoundInfoWidget")
	uint8 NextRoundAttackingTeam;

	UPROPERTY(BlueprintReadOnly, Category="InfiltrationRoundInfoWidget")
	uint8 NextRoundDefendingTeam;

	UPROPERTY(EditDefaultsOnly, Category="InfiltrationRoundInfoWidget")
	TSubclassOf<AFortGameplayMutator> MutatorClassToWaitFor;

	UPROPERTY()
	TScriptInterface<IInfiltrationRoundInfoMutatorInterface> CachedMutator;

};

