// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaChallengeRewardsMultiMarker.generated.h"

UCLASS(Abstract, meta=(Category="FortniteUI", DisableNativeTick))
class UAthenaChallengeRewardsMultiMarker : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaChallengeRewardsMultiMarker(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnSetMarkerActive(bool bIsActive);

	UFUNCTION(BlueprintImplementableEvent)
	void BP_OnSetSelected(bool bIsSelected);

};

