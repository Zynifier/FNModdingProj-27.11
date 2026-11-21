// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LiveStreamInMatchAd.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class ULiveStreamInMatchAd : public UUserWidget
{
	GENERATED_BODY()

public:
	ULiveStreamInMatchAd(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ShowAdvertisement();

};

