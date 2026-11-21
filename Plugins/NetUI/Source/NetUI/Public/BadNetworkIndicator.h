// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "BadNetworkIndicator.generated.h"

UCLASS(Config=Game, DefaultConfig, ClassGroup=("UI"), meta=(Category="Net UI", DisableNativeTick))
class NETUI_API UBadNetworkIndicator : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	float GetPacketLoss() const;

	UFUNCTION(BlueprintPure)
	float GetPing() const;

	UFUNCTION(BlueprintPure)
	bool HasBadPacketLoss() const;

	UFUNCTION(BlueprintPure)
	bool HasBadPing() const;

	UFUNCTION(BlueprintPure)
	bool HasSeverePacketLoss() const;

	UFUNCTION(BlueprintPure)
	bool HasSeverePing() const;

	UFUNCTION(BlueprintPure)
	bool ShouldDisplay() const;

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateDisplay();

	UPROPERTY(Config)
	bool bEnabled;

	UPROPERTY(Config)
	float MinimumDisplayTime;

	UPROPERTY(Config)
	float UpdateTime;

	UPROPERTY(Config)
	float InitialDelay;

};

