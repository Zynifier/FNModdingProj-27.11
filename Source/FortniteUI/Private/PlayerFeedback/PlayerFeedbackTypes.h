// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "PlayerFeedbackTypes.generated.h"

class UCommonTextBlock;
class UFortPlayerFeedbackModalSubscreenBase;
class UWidget;

UENUM()
enum class EFortPlayerFeedbackFlags : uint8
{
	SubscreenFlow_ForceDisplayFreeText = 0,
	SubscreenFlow_IncludeScreenshotSubscreen = 1,
	/** Flag to identify the voice report category button */
	SubscreenFlow_VoiceReportSubmit = 2,
	DoNotDisplay_SaveTheWorld = 3,
	DoNotDisplay_Athena = 4,
	DoNotDisplay_Creative = 5,
	Submit_TryDisplayBlockUser = 6,
	Submit_TryDisplayCommunityRulesURL = 7,
};

UENUM()
enum class EPlayerFeedbackSubmitState : uint8
{
	Start = 0,
	Submitting = 1,
	SubmitFailed = 2,
	SubmitSucceeded = 3,
};

UENUM()
enum class EPlayerFeedback_EpicQAState : uint8
{
	SignInPage = 0,
	SigningInFailed = 1,
	SigningIn = 2,
	SelectBugComponent = 3,
};

USTRUCT()
struct FFortFeedbackDropdownCategoryHotfix_Add
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName ParentInternalName;

	UPROPERTY()
	FName InternalName;

};

USTRUCT()
struct FFortFeedbackDropdownCategoryHotfix_Modify
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName InternalName;

	UPROPERTY()
	bool bAddFlag;

	UPROPERTY()
	EFortPlayerFeedbackFlags Flag;

};

UCLASS(Abstract)
class UFortPlayerFeedbackModalCategoryButton : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDropdownMenuStatusUpdated(bool bIsExpanded);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalCategoryButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Label;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalCategoryButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> DropdownWidget;

};

UCLASS(Abstract)
class UFortPlayerFeedbackModalPlayerButton : public UCommonButtonBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalPlayerButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalPlayerButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SecondaryPlayerName;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalPlayerButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Relationship;

};

UCLASS(Abstract)
class UFortPlayerFeedbackModalTab : public UCommonButtonBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdatedIsCurrentTab(bool bIsCurrent);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPlayerFeedbackModalSubscreenBase> AssociatedSubscreen;

protected:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortPlayerFeedbackModalTab", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> TabLabel;

};

