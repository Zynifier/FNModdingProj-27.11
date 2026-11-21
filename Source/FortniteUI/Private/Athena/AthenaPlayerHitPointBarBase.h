// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Math/Color.h"
#include "FortUIExtensionSlot.h"
#include "AthenaPlayerHitPointBarBase.generated.h"

class UAthenaPlayerViewModel;
class UUserWidget;
enum class EFortHitPointModificationReason : uint8;
enum class EUIExtensionSlot : uint8;

UENUM(BlueprintType)
enum class EHealthBarType : uint8
{
	Health = 0,
	Shield = 1,
	Overshield = 2,
	// Alpha Shield/Tactical Overshield

	Armor = 3,
	Stamina = 4,
	VehicleHealth = 5,
	SignalInStorm = 6,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaPlayerHitPointBarBase : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaPlayerHitPointBarBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION(BlueprintPure)
	float GetCurrentValuePercentage() const;

	UFUNCTION(BlueprintPure)
	float GetLastValuePercentage() const;

	UFUNCTION(BlueprintPure)
	bool IsShieldSegmented() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnDBNOStateChanged(bool IsDBNO);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDeltaChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExtensionWidgetAdded(const EUIExtensionSlot ExtensionSlot, UUserWidget* ExtensionWidget);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMaxValueChanged(float Value);

	UFUNCTION(BlueprintImplementableEvent)
	void OnValueChangedWithReason(float Value, EFortHitPointModificationReason Reason);

	UFUNCTION(BlueprintImplementableEvent)
	void SetProgressBarFillColors(FLinearColor ColorA, FLinearColor ColorB);

	UPROPERTY(Transient)
	TObjectPtr<UAthenaPlayerViewModel> PlayerVM;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerHitPointBarBase")
	EHealthBarType BarType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerHitPointBarBase")
	float ValueCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerHitPointBarBase")
	float BeginDeltaInterpDelayMin;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerHitPointBarBase")
	float BeginDeltaInterpDelayMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerHitPointBarBase")
	float ValueLast;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerHitPointBarBase")
	float ValueMax;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerHitPointBarBase")
	float LastToCurrentUpdateRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaPlayerHitPointBarBase")
	bool bShouldDisplayShieldBar;

	UPROPERTY(EditAnywhere, Category="AthenaPlayerHitPointBarBase", meta=(InlineEditConditionToggle="ExtensionSlotToUse"))
	bool bCanAddExtensionWidgets;

	UPROPERTY(EditAnywhere, Category="AthenaPlayerHitPointBarBase", meta=(EditCondition="bCanAddExtensionWidgets"))
	EUIExtensionSlot ExtensionSlotToUse;

};

