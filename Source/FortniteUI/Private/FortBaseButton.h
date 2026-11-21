// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Fonts/SlateFontInfo.h"
#include "Layout/Margin.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Sound/SlateSound.h"
#include "Styling/SlateBrush.h"
#include "Types/SlateEnums.h"
#include "UObject/NoExportTypes.h"
#include "FortBangInterface.h"
#include "FortBrushSize.h"
#include "FortMultiSize.h"
#include "FortTypes.h"
#include "FortUITypes.h"
#include "FortUserWidget.h"
#include "FortBaseButton.generated.h"

class UFortBaseButton;
class UFortButtonStyle;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFortBaseButtonClicked, UFortBaseButton*, Button);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortEnabledStateChanged, UFortBaseButton*, Button, bool, Enabled);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortSelectedStateChanged, UFortBaseButton*, Button, bool, Selected);

USTRUCT(BlueprintType)
struct FFortStateStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FFortMultiSizeBrush Brush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FLinearColor PrimaryColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Properties")
	FLinearColor SecondaryColor;

};

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Fortnite UI"))
class UFortBaseButton : public UFortUserWidget, public IFortBangInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortButton")
	void ForceClick();

	UFUNCTION(BlueprintPure, Category="FortButton|Getters")
	const FMargin GetCurrentButtonPadding() const;

	UFUNCTION(BlueprintPure, Category="FortButton|Getters")
	const FMargin GetCurrentCustomPadding() const;

	UFUNCTION(BlueprintPure, Category="FortButton|Getters")
	const FSlateFontInfo GetCurrentFont() const;

	UFUNCTION(BlueprintPure, Category="FortButton|Getters")
	const FFortStateStyle GetCurrentStateStyle() const;

	UFUNCTION(BlueprintPure, Category="FortButton|Getters")
	bool GetSelected() const;

	UFUNCTION(BlueprintCallable, Category="FortButton|Getters")
	int32 GetSelectionGroupIndex();

	UFUNCTION(BlueprintPure, Category="FortButton|Getters")
	UFortButtonStyle* GetStyle() const;

	UFUNCTION(BlueprintCallable, Category="FortButton|Setters")
	void SetBangVisibility(bool bVisible);

	UFUNCTION(BlueprintCallable, Category="FortButton|Setters")
	void SetBrushSize(EFortBrushSize::Type InSize);

	UFUNCTION(BlueprintCallable, Category="FortButton|Setters")
	void SetClickable(bool InClickable);

	UFUNCTION(BlueprintCallable, Category="FortButton|Setters")
	void SetClickMethod(EButtonClickMethod::Type InClickMethod);

	UFUNCTION(BlueprintCallable, Category="FortButton|Setters")
	void SetHovered(bool InHovered);

	UFUNCTION(BlueprintCallable, Category="FortButton|Setters")
	void SetSelected(bool InSelected);

	UFUNCTION(BlueprintCallable, Category="FortButton|Setters")
	void SetSelectionGroup(FName InSelectionGroup);

	UFUNCTION(BlueprintCallable, Category="FortButton|Setters")
	void SetStyle(TSubclassOf<UFortButtonStyle> InStyle = nullptr);

	UPROPERTY(BlueprintAssignable, Category="Events")
	FFortEnabledStateChanged EnabledChanged;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FFortSelectedStateChanged SelectedChanged;

	UPROPERTY(BlueprintAssignable, Category="Events")
	FFortBaseButtonClicked ButtonClicked;

protected:
	UFUNCTION()
	void OnButtonClicked();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton|Bang", meta=(ExposeOnSpawn="TRUE"))
	EFortBangSize BangSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton|Bang", meta=(ExposeOnSpawn="TRUE"))
	FVector2D BangOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton|Bang", meta=(ExposeOnSpawn="TRUE"))
	EFortBangType BangType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton|Tutorial", meta=(ExposeOnSpawn="TRUE"))
	FName TutorialNameID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton|Tutorial", meta=(ExposeOnSpawn="TRUE"))
	EFortTutorialGlowType TutorialGlowType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton|Style", meta=(ExposeOnSpawn="TRUE"))
	TSubclassOf<UFortButtonStyle> Style;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton|Style", meta=(ExposeOnSpawn="TRUE"))
	TEnumAsByte<EFortBrushSize::Type> BrushSize;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton|Style", meta=(DisplayName="Pressed Sound Override"))
	FSlateSound PressedSlateSoundOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton|Style", meta=(DisplayName="Hovered Sound Override"))
	FSlateSound HoveredSlateSoundOverride;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton", meta=(ExposeOnSpawn="TRUE"))
	bool bSelectable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton", meta=(EditCondition="bSelectable", ExposeOnSpawn="TRUE"))
	FName SelectionGroup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton", meta=(EditCondition="bSelectable", ExposeOnSpawn="TRUE"))
	bool bToggleable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton", meta=(ExposeOnSpawn="TRUE"))
	bool bClickable;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortButton", meta=(ExposeOnSpawn="TRUE"))
	TEnumAsByte<EButtonClickMethod::Type> ClickMethod;

};

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Fortnite UI"))
class UFortButtonStyle : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortButtonStyle|Getters")
	static const FSlateBrush GetBrushBySizeFromMultiSizeBrush(const FFortMultiSizeBrush& MultiSizeBrush, EFortBrushSize::Type Size);

	UFUNCTION(BlueprintPure, Category="FortButtonStyle|Getters")
	const FMargin GetButtonPaddingBySize(EFortBrushSize::Type Size) const;

	UFUNCTION(BlueprintPure, Category="FortButtonStyle|Getters")
	const FMargin GetCustomPaddingBySize(EFortBrushSize::Type Size) const;

	UFUNCTION(BlueprintPure, Category="FortButtonStyle|Getters")
	const FSlateFontInfo GetFontBySize(EFortBrushSize::Type Size) const;

	UFUNCTION(BlueprintCallable, Category="FortButtonStyle|Getters")
	static const FSlateFontInfo GetFontBySizeFromMultiSizeFont(const FFortMultiSizeFont& MultiSizeFont, EFortBrushSize::Type Size);

	UFUNCTION(BlueprintCallable, Category="FortButtonStyle|Getters")
	static const FMargin GetMarginBySizeFromMultiSizeMargin(const FFortMultiSizeMargin& MultiSizeMargin, EFortBrushSize::Type Size);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	FFortStateStyle NormalBase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	FFortStateStyle NormalHovered;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	FFortStateStyle NormalPressed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	FFortStateStyle SelectedBase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	FFortStateStyle SelectedHovered;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	FFortStateStyle SelectedPressed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	FFortStateStyle Disabled;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	FFortMultiSizeMargin ButtonPadding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	FFortMultiSizeFont Font;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties")
	FFortMultiSizeMargin CustomPadding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties", meta=(DisplayName="Pressed Sound"))
	FSlateSound PressedSlateSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Properties", meta=(DisplayName="Hovered Sound"))
	FSlateSound HoveredSlateSound;

};

