// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "AthenaChallengeCountdownTypes.generated.h"

UENUM()
enum class ECountdownDisplay : uint8
{
	// When the event ends

	EventEndTime = 0,
	// when the next challenge unlocks based on the even tag

	ChallengeUnlockTime = 1,
	// when the challenge bundle unlocks

	ChallengeBundleUnlockTime = 2,
	UnlockAlreadySet = 3,
	MAX = 4,
};

USTRUCT(BlueprintType)
struct FTimerDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TimerDisplayData")
	FLinearColor BrushColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TimerDisplayData")
	FText TimeRemainingDisplayText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="TimerDisplayData")
	FLinearColor TextColor;

};

