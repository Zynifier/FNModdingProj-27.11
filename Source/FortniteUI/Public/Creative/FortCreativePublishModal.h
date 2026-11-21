// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Types/SlateEnums.h"
#include "FortCreativePublishModal.generated.h"

class AFortVolume;
class UCheckBox;
class UCommonAnimatedSwitcher;
class UCommonButtonBase;
class UCommonTextBlock;
class UEditableTextBox;

UENUM(BlueprintType)
enum class ECreativePublishError : uint8
{
	None = 0,
	RateLimited = 1,
	PlotOverBudget = 2,
	LinkCodeInvalid = 3,
	SanitizationFiltered = 4,
	Other = 5,
};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortCreativePublishModal : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="Reset"))
	void BP_Reset();

	UFUNCTION(BlueprintImplementableEvent)
	void OnCodeCopied();

	UFUNCTION(BlueprintImplementableEvent)
	void OnDescriptionTextCommitted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnNameTextCommitted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPublishBegin();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPublishError(const FText& ErrorText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPublishSuccess();

	UFUNCTION(BlueprintImplementableEvent)
	void OnValidCheckComplete(bool bSuccess);

	UPROPERTY(EditAnywhere, Category="FortCreativePublishModal")
	int32 DescriptionEntryCharLimit;

	UPROPERTY(EditAnywhere, Category="FortCreativePublishModal")
	int32 NameEntryCharLimit;

	UPROPERTY(EditAnywhere, Category="FortCreativePublishModal")
	bool bFakePublishingFlow;

private:
	UFUNCTION()
	void HandleDescriptionTextChanged(const FText& Text);

	UFUNCTION()
	void HandleDescriptionTextCommitted(const FText& Text, ETextCommit::Type CommittMethod);

	UFUNCTION()
	void HandleNameTextChanged(const FText& Text);

	UFUNCTION()
	void HandleNameTextCommitted(const FText& Text, ETextCommit::Type CommittMethod);

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonAnimatedSwitcher> Switcher_Content;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_IslandCode;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ErrorInNameField;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ErrorInDescriptionField;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ErrorInRequiredTags;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ErrorInIslandBudget;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ErrorOnPublish;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CharCountTitle;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_CharCountDesc;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_IslandPublishedSuccess;

	UPROPERTY(Export, meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Submit;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_CopyCode;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCheckBox> CheckBox_ClearAllPlayersData;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePublishModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UEditableTextBox> EditText_Name;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativePublishModal", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UEditableTextBox> EditText_Description;

	UPROPERTY(EditAnywhere, Category="FortCreativePublishModal")
	int32 NumTagsRequiredToPublish;

	UPROPERTY(Transient)
	TObjectPtr<AFortVolume> VolumeToPublish;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Project Name"))
	FString DesignTime_ProjectName;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Publish Error"))
	ECreativePublishError DesignTime_PublishError;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="Design Time", meta=(DisplayName="Custom Publish Error", EditCondition="DesignTime_PublishError == ECreativePublishError::Other", EditConditionHides))
	FString DesignTime_CustomPublishError;
#endif

};

