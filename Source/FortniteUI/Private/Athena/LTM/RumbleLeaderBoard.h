// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "FortTypes.h"
#include "RumbleLeaderBoard.generated.h"

class USoundCue;

USTRUCT(BlueprintType)
struct FSoundThreshold
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SoundThreshold")
	TObjectPtr<USoundCue> SoundCue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SoundThreshold")
	float Threshold;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class URumbleLeaderBoard : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnThresholdPassed(const FSoundThreshold& SoundThreshold, int32 ThresholdIndex, bool bIsLocalPlayer);

	UFUNCTION(BlueprintImplementableEvent)
	void SetGoalValue(float NewValue);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateVisuals(const TArray<FFortInGameLeaderboardPlacementData>& Data);

	UPROPERTY(EditAnywhere, Category="RumbleLeaderBoard")
	TArray<FSoundThreshold> ThresholdArray;

};

