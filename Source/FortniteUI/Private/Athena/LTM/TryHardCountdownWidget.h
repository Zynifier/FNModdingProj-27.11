// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "TryHardCountdownWidget.generated.h"

class AFortPlayerStateZone;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UTryHardCountdownWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HideWidget();

	UFUNCTION(BlueprintNativeEvent, BlueprintPure)
	bool IsShowing() const;

	UFUNCTION()
	void OnHandleSpectatingChanged(AFortPlayerStateZone* SpectatingTarget);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowWidget(int32 NumRemaining);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void UpdateNumber(int32 NumRemaining);

	UPROPERTY(EditAnywhere, Category="TryHardCountdownWidget")
	int32 NumToStartShowingAt;

};

