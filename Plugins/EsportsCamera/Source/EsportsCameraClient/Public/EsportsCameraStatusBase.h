// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "EsportsCameraStatusBase.generated.h"

class AEsportsCameraClient;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UEsportsCameraStatusBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void FollowedPlayerChanged(AEsportsCameraClient* InEsportsCameraClient);

};

