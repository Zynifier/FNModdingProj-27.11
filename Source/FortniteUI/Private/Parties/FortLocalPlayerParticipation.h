// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "FortLocalPlayerParticipation.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortLocalPlayerParticipation : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnLocalPlayerParticipationChanged(bool bIsParticipating);

};

