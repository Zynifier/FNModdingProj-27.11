// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Frontend/Spatial/Customization/SpatialCustomizationSubscreenBase.h"
#include "SpatialCustomizationSelection.generated.h"

class UAthenaQuestProgression;
class UAthenaSpatialCustomizationCategoryEntry;
class UAthenaSpatialCustomizationChoice;
class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortColorPicker;
class UFortGameStateComponent_EventLevel;
class UWidgetAnimation;
enum class ESpatialCustomizationCategoryState : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UAthenaSpatialCustomizationSelection : public UAthenaSpatialCustomizationSubscreenBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCategoryUpdated(ESpatialCustomizationCategoryState CategoryState, FLinearColor Color, bool bUseColorPicker);

	UFUNCTION(BlueprintImplementableEvent)
	void OnChoiceCountUpdated(int32 ChoiceNum, int32 TotalCount);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFinalizeChoiceFinished(bool bSucceeded);

	UFUNCTION(BlueprintImplementableEvent)
	void OnFinalizeChoiceStarted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateFinalizedText(const FText& InFinalizedChoiceText);

private:
	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaSpatialCustomizationSelection", meta=(AllowPrivateAccess="TRUE", BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> IntroChoice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CategoryTitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationSelection", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CategoryDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SelectedChoiceName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_LockedReason;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationSelection", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaQuestProgression> QuestProgress_ChallengeProgression;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationSelection", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PurchaseBattlepass;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationSelection", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortColorPicker> ColorPicker;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationSelection", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_FinalizeChoice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PreviousCategory;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_NextCategory;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_PreviousChoice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_NextChoice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpatialCustomizationChoice> Choice_SelectedChoice;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpatialCustomizationChoice> Choice_CustomizationChoicePrevious;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpatialCustomizationChoice> Choice_CustomizationChoiceNext;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaSpatialCustomizationSelection", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UAthenaSpatialCustomizationChoice> Choice_UnlockUsed;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UAthenaSpatialCustomizationCategoryEntry>> Categories;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortGameStateComponent_EventLevel> EventGameStateComponent;

};

