// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Components/RadialBoxSettings.h"
#include "FortRadialMenu.generated.h"

class UDynamicEntryBox;
class UUserWidget;

UENUM()
enum class EFortRadialControllingStick : uint8
{
	Right = 0,
	Left = 1,
};

UCLASS(MinimalAPI, meta=(DisableNativeTick))
class UFortRadialMenu : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	float GetAngleForIndex(int32 index) const;

	UFUNCTION(BlueprintPure)
	float GetDegreeIncrements() const;

	UFUNCTION(BlueprintPure)
	float GetDegreeOffset() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumEntries() const;

protected:
	UPROPERTY(EditAnywhere, Category="RadialMenu")
	TSubclassOf<UUserWidget> EntryWidgetClass;

private:
	UPROPERTY(EditAnywhere, Category="DeadZone")
	float JoystickDeadZone;

	UPROPERTY(EditAnywhere, Category="DeadZone")
	float MouseDeadZoneRadiusPercentage;

	UPROPERTY(EditAnywhere, Category="Magnitude")
	float JoystickMaximumMagnitude;

	UPROPERTY(EditAnywhere, Category="Radial EntryBox Settings")
	FRadialBoxSettings RadialBoxSettings;

	UPROPERTY(EditAnywhere, Category="Input")
	EFortRadialControllingStick ControllingStick;

	UPROPERTY(EditAnywhere, Category="Input")
	bool bAllowEmptySelection;

	UPROPERTY(EditAnywhere, Category="Input")
	bool bAllowFullMovement;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_ContextRadial;

};

