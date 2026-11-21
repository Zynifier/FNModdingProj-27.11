// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LiveEventHUDAd.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class PICTUREINPICTUREFNEVENTS_API ULiveEventHUDAd : public UUserWidget
{
	GENERATED_BODY()

public:
	ULiveEventHUDAd(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ShowAdvertisement(bool& Result);

};

