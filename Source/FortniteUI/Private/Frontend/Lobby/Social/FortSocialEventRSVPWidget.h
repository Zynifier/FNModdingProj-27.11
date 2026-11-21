// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortSocialEventRSVPWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialEventRSVPWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortSocialEventRSVPWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnRefreshDisplay(const FText& EventName, const FText& Date, const FText& AdditionalEvents);

};

