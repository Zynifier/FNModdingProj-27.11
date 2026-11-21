// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/Widgets/FortSettingDetailExtension.h"
#include "KoalaSettingDetailExtension.generated.h"

UCLASS(Abstract, meta=(Category="Settings", DisableNativeTick))
class UKoalaSettingDetailExtension : public UFortSettingDetailExtension
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnAvailabilityChanged(bool bAvailable);

	UFUNCTION(BlueprintImplementableEvent)
	void OnConnectionChanged(bool bConnected);

};

