// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/ReticleExtensions/FortWeaponReticleExtensionWidgetBase.h"
#include "FortPowerupReticleExtensionWidget.generated.h"

UENUM(BlueprintType)
enum class EPowerupHeatState : uint8
{
	Normal = 0,
	Superheated = 1,
	Overheated = 2,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortPowerupReticleExtensionWidget : public UFortWeaponReticleExtensionWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	float GetCurrentOverheatPercent() const;

	UFUNCTION(BlueprintPure)
	float GetCurrentOverheatValue() const;

	UFUNCTION(BlueprintPure)
	float GetOverheatingMaxValue() const;

	UPROPERTY(BlueprintReadWrite, Category="FortPowerupReticleExtensionWidget")
	EPowerupHeatState LastPowerupHeatState;

};

