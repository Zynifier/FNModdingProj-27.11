// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "AthenaSkydivingInformation.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaSkydivingInformation : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnEnterGlider();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExitSkydive();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewAltitude(float NewAltitude);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewCurrentAltitude(float NewCurrentAltitude);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewDuration(float NewDuration);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewGroundAltitude(float NewGroundAltitude);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewHorizontalSpeed(float NewHorizontalSpeed);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewNormalizedGroundAltitude(float NormalizedGroundAltitude);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewNormalizedOpeningAltitude(float NormalizedOpeningAltitude);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewNormalizedPlayerAltitude(float NormalizedPlayerAltitude);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewRating(float NewRating);

	UFUNCTION(BlueprintImplementableEvent)
	void OnNewVerticalSpeed(float NewVerticalSpeed);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStartSkydive();

};

