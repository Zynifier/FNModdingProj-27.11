// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonInputTypeEnum.h"
#include "CommonUserWidget.h"
#include "Fonts/SlateFontInfo.h"
#include "InputCoreTypes.h"
#include "Layout/Margin.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "CommonInputTypes.h"
#include "FortBrushSize.h"
#include "FortMultiSize.h"
#include "FortKeybindWidget.generated.h"

class UInputAction;
class UInputMappingContext;
class UMaterialInstanceDynamic;
enum class EFortKeybindForcedHoldStatus : uint8;

UENUM(BlueprintType)
enum class EFortKeybindForcedHoldStatus : uint8
{
	NoForcedHold = 0,
	ForcedHold = 1,
	NeverShowHold = 2,
};

USTRUCT()
struct FMeasuredText
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortKeybindWidget : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Keybind Widget")
	EFortBrushSize::Type GetBrushSize() const;

	UFUNCTION()
	bool IsBoundKeyValid() const;

	UFUNCTION(BlueprintPure, Category="Keybind Widget")
	bool IsHoldKeybind() const;

	UFUNCTION(BlueprintCallable, Category="Keybind Widget")
	void SetAxisScale(const float NewValue);

	UFUNCTION(BlueprintCallable, Category="Keybind Widget")
	void SetBoundAction(FName NewBoundAction);

	UFUNCTION(BlueprintCallable, Category="Keybind Widget")
	void SetBoundInputAction(UInputAction* NewAction);

	UFUNCTION(BlueprintCallable, Category="Keybind Widget")
	void SetBoundKey(FKey NewBoundAction);

	UFUNCTION(BlueprintCallable, Category="Keybind Widget")
	void SetBrushSize(EFortBrushSize::Type InBrushSize);

	UFUNCTION(BlueprintCallable, Category="Keybind Widget", meta=(DeprecatedFunction, DeprecationMessage="Use SetForcedHoldKeybindStatus instead"))
	void SetForcedHoldKeybind(bool InForcedHoldKeybind);

	UFUNCTION(BlueprintCallable, Category="Keybind Widget")
	void SetForcedHoldKeybindStatus(EFortKeybindForcedHoldStatus InForcedHoldKeybindStatus);

	UFUNCTION(BlueprintCallable, Category="Keybind Widget")
	void SetInputContextOverride(UInputMappingContext* NewContextOverride);

	UFUNCTION(BlueprintCallable, Category="Keybind Widget")
	void SetPresetNameOverride(const FName NewValue);

	UFUNCTION(BlueprintCallable, Category="Keybind Widget")
	void SetShowProgressCountDown(bool bShow);

	UFUNCTION()
	void StartHoldProgress(FName HoldActionName, float HoldDuration);

	UFUNCTION()
	void StopHoldProgress(FName HoldActionName, bool bCompletedSuccessfully);

	UFUNCTION(BlueprintCallable, Category="Keybind Widget")
	void UpdateKeybindWidget();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keybind Widget")
	FName BoundAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keybind Widget")
	TObjectPtr<UInputAction> BoundInputAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keybind Widget")
	TObjectPtr<UInputMappingContext> InputContextOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keybind Widget")
	TArray<FName> BoundActionFallbacks;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keybind Widget")
	float AxisScale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keybind Widget")
	FKey BoundKeyFallback;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Keybind Widget")
	ECommonInputType InputTypeOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Keybind Widget")
	ECommonGamepadType GamepadTypeOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Keybind Widget")
	FName PresetNameOverride;

	UPROPERTY()
	bool bForcedHoldKeybind_DEPRECATED;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Keybind Widget")
	EFortKeybindForcedHoldStatus ForcedHoldKeybindStatus;

protected:
	UFUNCTION(BlueprintPure, Category="Keybind Widget")
	bool GetBrushForKey(EFortBrushSize::Type InBrushSize, FSlateBrush& Brush) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Keybind Widget", meta=(ScriptName="IsHoldKeybindValue"))
	bool bIsHoldKeybind;

	UPROPERTY(Transient)
	bool bShowKeybindBorder;

	UPROPERTY(Transient)
	FVector2D FrameSize;

	UPROPERTY(BlueprintReadOnly, Category="Keybind Widget")
	bool bShowTimeCountDown;

	UPROPERTY(BlueprintReadOnly, Category="Keybind Widget")
	FKey BoundKey;

	UPROPERTY(EditDefaultsOnly, Category="Keybind Widget")
	FSlateBrush HoldProgressBrush;

	UPROPERTY(EditDefaultsOnly, Category="Keybind Widget")
	FSlateBrush KeyBindTextBorder;

	UPROPERTY(EditAnywhere, Category="Keybind Widget")
	bool bShowUnboundStatus;

	UPROPERTY(EditAnywhere, Category="Keybind Widget")
	bool bUseKeyboardTextureForKeys;

	UPROPERTY(EditDefaultsOnly, Category="Font")
	FSlateFontInfo KeyBindTextFont;

	UPROPERTY(EditDefaultsOnly, Category="Font")
	FSlateFontInfo CountdownTextFont;

	UPROPERTY(Transient)
	FMeasuredText CountdownText;

	UPROPERTY(Transient)
	FMeasuredText KeybindText;

	UPROPERTY(Transient)
	FMargin KeybindTextPadding;

	UPROPERTY(Transient)
	FVector2D KeybindFrameMinimumSize;

	UPROPERTY(EditDefaultsOnly, Category="Keybind Widget")
	FName PercentageMaterialParameterName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortKeybindWidget")
	TObjectPtr<UMaterialInstanceDynamic> ProgressPercentageMID;

	UPROPERTY(EditDefaultsOnly, Category="Keybind Widget")
	TEnumAsByte<EFortBrushSize::Type> BrushSize;

	UPROPERTY(EditDefaultsOnly, Category="Keybind Widget")
	FFortMultiSizeBrush FrameMultiBrush;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Keybind Widget|Design Time")
	FKey DesignTimeKey;
#endif

private:
	UPROPERTY(Transient)
	FSlateBrush CachedKeyBrush;

};

