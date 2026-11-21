// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "FortBroadcasterMapSettings.generated.h"

class UCommonUserWidget;
class UFortSpectateClickableMapIcon;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortBroadcasterMapSettings : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Map Icon Added"))
	void BP_HandleMapIconAdded(UFortSpectateClickableMapIcon* MapIcon);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortBroadcasterMapSettings", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonUserWidget> PlayerIndicatorsRotator;

};

