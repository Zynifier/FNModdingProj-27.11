// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/CobaltWidgetBase.h"
#include "CobaltStatusWidgetBase.generated.h"

class UCommonTextBlock;

UENUM()
namespace ECobaltStatusTeam
{
	enum Type
	{
		Ally = 0,
		Enemy = 1,
		// This should always be last.

		MAX = 255 UMETA(DisplayName="None/Invalid"),
	};
}

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UCobaltStatusWidgetBase : public UCobaltWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayCountdownSound();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayLeadChangedSound(bool bTookTheLead);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPlayScoreProgressSound(bool bIsLocalTeam);

	UFUNCTION(BlueprintImplementableEvent)
	void OnResetUI();

	UFUNCTION(BlueprintImplementableEvent)
	void OnTieBreakerChangedSound();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateTeamScore(int32 TeamIndex, int32 Score, bool bIsTeamLeading, bool bPlayAnimation);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateTieBreakerUI(bool bHasTieBreaker);

	UFUNCTION()
	void RoundAdvanced();

	UFUNCTION(BlueprintImplementableEvent)
	void ShowTimer();

	UFUNCTION()
	void UpdateScoringUI();

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateTimerVisuals(float TimeRemaining);

	UPROPERTY(Transient)
	uint8 LastViewedTeam;

	UPROPERTY(BlueprintReadOnly, Export, Category="Cobalt Round", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> RoundName;

	UPROPERTY(EditDefaultsOnly, Category="Cobalt Round")
	float CountdownSoundStartTime;

};

