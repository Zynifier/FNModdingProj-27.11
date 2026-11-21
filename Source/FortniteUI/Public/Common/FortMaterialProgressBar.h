// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "FortMaterialProgressBar.generated.h"

class UCommonBorder;
class UFortMaterialProgressBarStyle;
class UMaterialInstanceDynamic;
enum class EFortMaterialProgressBarSectionColorNumber : uint8;

UENUM(BlueprintType)
namespace EFortMaterialProgressBarSection
{
	enum Type
	{
		Primary = 0,
		Secondary = 1,
		Tertiary = 2,
		Negative = 3,
		MAX_PROGRESS_BAR_SECTIONS = 4 UMETA(Hidden),
	};
}

UENUM(BlueprintType)
enum class EFortMaterialProgressBarSectionColorNumber : uint8
{
	Color1 = 0,
	Color2 = 1,
};

UENUM(BlueprintType)
enum class EFortMaterialProgressBarSectionOverflowBehavior : uint8
{
	/** Keep entered values precisely as they are, even if they cause sections to overflow off the bar */
	PreserveValues = 0,
	/** 
	 * Modify the section percentages in reverse so that the only sections visible are those that would be in the last "whole" bar;
	 * Example:
	 * Primary Pct: 0.9
	 * Secondary Pct: 0.5
	 * results in
	 * New Primary Pct: 0
	 * Secondary Pct: 0.4
	 * 
	 * Useful for previewing level growth/roll-over, such as with previewing XP gain rolling to a new level
	 */
	ReverseCollapse = 1,
};

USTRUCT(BlueprintType)
struct FFortMaterialProgressBarSectionStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ProgressBar")
	bool bGradientBar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ProgressBar")
	FName BarParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ProgressBar")
	FName BarColorOneParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ProgressBar", meta=(EditCondition="bGradientBar"))
	FName BarColorTwoParamName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ProgressBar")
	FLinearColor BarColorOne;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ProgressBar", meta=(EditCondition="bGradientBar"))
	FLinearColor BarColorTwo;

};

USTRUCT(BlueprintType)
struct FFortMaterialProgressBarSectionInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ProgressBar")
	FFortMaterialProgressBarSectionStyle SectionStyle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ProgressBar", meta=(ClampMin="0", UIMin="0"))
	float Percent;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Fortnite UI", DisableNativeTick))
class UFortMaterialProgressBar : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="ProgressBar")
	void SetBackgroundColor(FLinearColor Color);

	UFUNCTION(BlueprintCallable, Category="ProgressBar")
	void SetProgressBarSectionColor(EFortMaterialProgressBarSection::Type BarSection, FLinearColor Color, EFortMaterialProgressBarSectionColorNumber ColorNumber = EFortMaterialProgressBarSectionColorNumber::Color1);

	UFUNCTION(BlueprintCallable, Category="ProgressBar")
	void SetProgressBarSectionPercent(EFortMaterialProgressBarSection::Type BarSection, float Percent);

	UFUNCTION(BlueprintCallable, Category="ProgressBar")
	void SetStyle(TSubclassOf<UFortMaterialProgressBarStyle> BarStyle);

protected:
	UPROPERTY(EditAnywhere, Category="ProgressBar")
	TSubclassOf<UFortMaterialProgressBarStyle> Style;

	UPROPERTY(EditAnywhere, Category="ProgressBar")
	FName BackgroundColorParamName;

	UPROPERTY(EditAnywhere, Category="ProgressBar")
	FLinearColor BackgroundColor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ProgressBar")
	EFortMaterialProgressBarSectionOverflowBehavior OverflowBehavior;

	UPROPERTY(EditAnywhere, Category="ProgressBar", meta=(ArraySizeEnum="/Script/FortniteUI.EFortMaterialProgressBarSection"))
	FFortMaterialProgressBarSectionInfo BarSectionInfo[4];

	UPROPERTY(BlueprintReadOnly, Export, Category="ProgressBar", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> ProgressBar;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> ProgressBarMID;

};

UCLASS(Abstract, BlueprintType, Blueprintable, ClassGroup=("UI"), meta=(Category="Fortnite UI"))
class UFortMaterialProgressBarStyle : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ProgressBar")
	FName BackgroundColorParamName;

	UPROPERTY(EditDefaultsOnly, Category="ProgressBar")
	FLinearColor BackgroundColor;

	UPROPERTY(EditDefaultsOnly, Category="ProgressBar", meta=(ArraySizeEnum="/Script/FortniteUI.EFortMaterialProgressBarSection"))
	FFortMaterialProgressBarSectionStyle BarSectionStyles[4];

};

