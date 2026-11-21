// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Challenges/AthenaChallengeComponentWidget.h"
#include "AthenaChallengeRewardSurvivorBadge.generated.h"

class UFortAthenaSurvivorTierBadge;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaChallengeRewardSurvivorBadge : public UAthenaChallengeComponentWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortAthenaSurvivorTierBadge> SurvivorTierBadge;

};

