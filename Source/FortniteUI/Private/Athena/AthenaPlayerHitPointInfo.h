// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaPlayerHitPointInfo.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaPlayerHitPointInfo : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleEnterVehicle();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleExitVehicle();

private:
	UFUNCTION()
	void HandleTetherChanged(bool bTethered);

	UPROPERTY(EditAnywhere, Category="AthenaPlayerHitPointInfo")
	bool bUseLargeFormat;

};

