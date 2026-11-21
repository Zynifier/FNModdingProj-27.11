// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "PostGameSpectatedPlayerName.generated.h"

class AFortPlayerStateZone;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UPostGameSpectatedPlayerName : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnHandleSpectatingChanged(AFortPlayerStateZone* SpectatingTarget);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowWidget(const FString& PlayerName, const FString& PlayerID);

};

