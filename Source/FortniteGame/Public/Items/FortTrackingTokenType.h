// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortTokenType.h"
#include "FortTrackingTokenType.generated.h"

UCLASS()
class UFortTrackingTokenType : public UFortTokenType
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortTrackingTokenType")
	int32 MaxDailyXP;

	UPROPERTY(EditDefaultsOnly, Category="FortTrackingTokenType")
	int64 TokenRedemptionThrottlingDuration;

	UPROPERTY(EditDefaultsOnly, Category="FortTrackingTokenType", meta=(ClampMin="0"))
	float MissionXPMultiplier;

	UPROPERTY(EditDefaultsOnly, Category="FortTrackingTokenType", meta=(ClampMin="0"))
	float QuestXPMultiplier;

};

