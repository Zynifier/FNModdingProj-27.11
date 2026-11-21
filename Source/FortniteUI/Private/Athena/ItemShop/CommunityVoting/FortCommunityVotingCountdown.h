// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Misc/DateTime.h"
#include "FortCommunityVotingCountdown.generated.h"

class UCommonTextBlock;

UCLASS(Abstract)
class UFortCommunityVotingCountdown : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortCommunityVotingCountdown(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintCallable, Category="DateTime Text Block")
	void SetDateTimeValue(const FDateTime& InDateTime, float InRefreshDelay = 1.000000f);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TimeRemaining;

};

