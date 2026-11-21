// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Layout/Margin.h"
#include "Types/SlateEnums.h"
#include "Athena/AthenaCoupledWidgetInterface.h"
#include "FortHUDElementWidget.h"
#include "FortAthenaVehicleDashboardWidget.generated.h"

class AActor;
class AFortAthenaVehicle;
class UCommonNumericTextBlock;
class UCommonTextBlock;
class UOverlay;
class UUserWidget;
enum class EUIExtensionSlot : uint8;

UENUM(BlueprintType)
enum class EFuelTankState : uint8
{
	Empty = 0,
	LowFuel = 1,
	RegularFuel = 2,
};

UCLASS(Abstract, MinimalAPI)
class UFortAthenaVehicleDashboardWidget : public UFortHUDElementWidget, public IAthenaCoupledWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void AddWidgetTagsToHideWhenVisible(FGameplayTagContainer TagToAdd);

	UFUNCTION(BlueprintPure)
	FORTNITEUI_API AFortAthenaVehicle* GetVehicle() const;

	UFUNCTION()
	FORTNITEUI_API void OnAddedFuel(float NewFuelPercent);

	UFUNCTION(BlueprintCallable)
	FORTNITEUI_API void RemoveWidgetTagsToHideWhenVisible(FGameplayTagContainer TagToRemove);

	UFUNCTION()
	FORTNITEUI_API virtual void SetupVehicleFuelWidget(AActor* NewVehicle, const bool bRequestShowWidget);

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Handle Extension Widget Created"))
	FORTNITEUI_API void BP_HandleExtensionWidgetCreated(UUserWidget* Widget, EUIExtensionSlot SlotType);

	UFUNCTION(BlueprintPure)
	FORTNITEUI_API AFortAthenaVehicle* GetCurrentVehicle() const;

	UFUNCTION(BlueprintPure)
	FORTNITEUI_API virtual float GetHUDTopSpeed() const;

	UFUNCTION()
	FORTNITEUI_API void HandleBoostFinished();

	UFUNCTION()
	FORTNITEUI_API void HandleBoostStarted();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnBoostChargeFilled();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnBoostFinished();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnBoostStarted();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnDisabledChanged(bool bDisabled);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnFuelValueChanged(float FuelPercentage, bool bIsLowOnFuel);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnLowFuel();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnOutOfFuel();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnPlayerFacingNameUpdated();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnRechargableBoostFilled();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnRPMChanged(float NormalizedRPM);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnUpdateBoostChargePercent(float BoostPercent);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnUpdateRechargeableBoostPercent(float BoostPercent);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnVehicleUpdated(AFortAthenaVehicle* NewVehicle);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void OnWidgetVisibilityChanged(bool bNewVisibility);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void SetVehicleHasInfiniteFuel(bool bInfiniteFuel);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void SetVehicleUsesRechargableBoost(bool bUsesRechargeableBoost);

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void ShowNoFuelMessage();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void UpdateSpeedometer(float NormalizedSpeed, float RawSpeed);

	UPROPERTY(Transient)
	bool bIsWidgetShowing;

	UPROPERTY(Transient)
	bool bDisplayedIsDisabled;

	UPROPERTY(Transient)
	TObjectPtr<AFortAthenaVehicle> CurrentVehicleActor;

	UPROPERTY(Transient)
	float CurrentSpeed;

	UPROPERTY(Transient)
	float TargetFuelPercent;

	UPROPERTY(Transient)
	float DisplayedFuelPercent;

	UPROPERTY(EditAnywhere, Category="FortAthenaVehicleDashboardWidget")
	float FillBlendSpeed;

private:
	UPROPERTY(EditAnywhere, Category="Settings")
	float SpeedTextMaxInterpolationRate;

	UPROPERTY(EditAnywhere, Category="Related HUD Elements")
	FGameplayTagContainer WidgetTagsToHideWhenVisible;

	UPROPERTY(EditAnywhere, Category="FortAthenaVehicleDashboardWidget")
	float HUDTopSpeed;

	UPROPERTY(EditAnywhere, Category="FortAthenaVehicleDashboardWidget")
	TEnumAsByte<EHorizontalAlignment> MobileFuelGaugeHorizontalAlignment;

	UPROPERTY(EditAnywhere, Category="FortAthenaVehicleDashboardWidget")
	TEnumAsByte<EVerticalAlignment> MobileFuelGaugeVerticalAlignment;

	UPROPERTY(EditAnywhere, Category="FortAthenaVehicleDashboardWidget")
	FMargin MobileFuelGaugePadding;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> NumericText_Speed;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_Gauge;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

};

