// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortCreativeChannelBrowser.generated.h"

class AActor;

UENUM(BlueprintType)
enum class EShowChannelDetails : uint8
{
	FromMinigameSettings = 0,
	ForceShow = 1,
	ForceHide = 2,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativeChannelBrowser : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	static TMap<AActor*, FText> GetSortedDeviceMap(const TMap<AActor*, FText>& InDeviceMap);

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	void RequestCloseUI();

	UFUNCTION(BlueprintPure)
	bool ShouldShowChannelDetails();

};

