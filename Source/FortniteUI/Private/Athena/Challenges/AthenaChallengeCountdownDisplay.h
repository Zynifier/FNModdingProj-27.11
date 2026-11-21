// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Misc/DateTime.h"
#include "Athena/Challenges/AthenaChallengeCountdownTypes.h"
#include "AthenaChallengeCountdownDisplay.generated.h"

class UCommonTextBlock;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaChallengeCountdownDisplay : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaChallengeCountdownDisplay(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnChallengeSet(const FTimerDisplayData& DisplayStyle);

private:
	UPROPERTY(Transient)
	FDateTime UnlockTime;

	UPROPERTY()
	ECountdownDisplay DisplayType;

	UPROPERTY(EditDefaultsOnly, Category="AthenaChallengeCountdownDisplay")
	FTimerDisplayData DisplayData[4];

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TimeRemaining;

};

