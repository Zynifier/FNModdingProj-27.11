// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UpdateManager.h"
#include "FortMatchmakingWidgetBase.h"
#include "FortAthenaCreativeMatchmakingWidget.generated.h"

enum class EGameReadiness : uint8;

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortAthenaCreativeMatchmakingWidget : public UFortMatchmakingWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void DisableOwningPlayerForReadyCheckInput();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnPlaySimpleIntroOutroWithDelay(float InDelay);

	UFUNCTION(BlueprintCallable)
	void SetupOwningPlayerForReadyCheckInput();

protected:
	UFUNCTION(BlueprintPure)
	bool GetIsDestPlaylistCreativeRoyale() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HandleInGameReadinessChangedBP(EGameReadiness GameReadiness, int32 SquadMemberIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleMatchmakingPartyReadyBP();

	UFUNCTION(BlueprintImplementableEvent)
	void HandlePartyLeaderReadinessChangedBP(EGameReadiness GameReadiness, int32 SquadMemberIndex);

	UFUNCTION(BlueprintPure)
	bool HasAnyPlayerOptedOutOfCrossPlatformPlay();

	UFUNCTION(BlueprintCallable)
	void NativeOnHideWidget();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdatedSquadReadyInformationBP(int32 SquadMembers, int32 ReadySquadMembers, bool AmIReady);

	UFUNCTION(BlueprintCallable)
	void SetOwningPlayerReadyState(bool bInReadyState);

	UFUNCTION(BlueprintCallable)
	void TogglePlayerReadyState();

	UPROPERTY(BlueprintReadWrite, Category="FortAthenaCreativeMatchmakingWidget")
	uint8 bIsCreativeHUD : 1;

private:
	UFUNCTION()
	void InGameMathcmakingUpdateCheckFailed(EUpdateCompletionStatus Status);

};

