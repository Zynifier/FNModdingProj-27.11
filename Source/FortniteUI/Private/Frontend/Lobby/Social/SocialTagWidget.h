// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Components/SlateWrapperTypes.h"
#include "FortReleaseVersion.h"
#include "SocialTagWidget.generated.h"

class UImage;
enum class ESocialTagCategory : uint8;

UENUM(BlueprintType)
enum class ESocialTagCategory : uint8
{
	GameModes = 0,
	Mood = 1,
	Utility = 2,
	Competitive = 3,
	Other = 4,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class USocialTagWidget : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetFullColor();

	UFUNCTION(BlueprintImplementableEvent)
	void SetHighlightState(bool bHighlighted);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void SetCategoryCustomizationVisibility(ESlateVisibility CategoryCustomizationVisibility);

	UFUNCTION(BlueprintImplementableEvent)
	void SetTag(const FText& InTagName, const ESocialTagCategory InTagCategory, const bool bInIsSystemTag);

	UPROPERTY(BlueprintReadOnly, Export, Category="SocialTagWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_CheckMark;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, DuplicateTransient, Category="ReleaseVersion")
	FFortReleaseVersion FortReleaseVersion;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(DisplayName="Tag Name"))
	FString TagName;
#endif

	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(DisplayName="Category"))
	ESocialTagCategory TagCategory;

	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(DisplayName="Is System Tag"))
	bool bIsSystemTag;

	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(DisplayName="Show Category Customization"))
	bool bShowCategoryCustomization;

	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(DisplayName="Is Selectable"))
	bool bIsSelectable;

	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(DisplayName="Supports Multi Selection"))
	bool bEnableMultiSelection;

	UPROPERTY(BlueprintReadWrite, Category="SocialTagWidget", meta=(AllowPrivateAccess))
	bool bShowAddingWhenSelected;

private:
	UPROPERTY(EditAnywhere, Category="Social Tags", meta=(AllowPrivateAccess, DisplayName="Checkmark Enabled"))
	bool bIsCheckmarkEnabled;

};

