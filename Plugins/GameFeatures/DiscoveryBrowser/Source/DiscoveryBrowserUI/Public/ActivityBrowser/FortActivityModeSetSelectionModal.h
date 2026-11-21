// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DiscoveryShared/FortActivityModeSetSelectionModalBase.h"
#include "FortActivityModeSetSelectionModal.generated.h"

class UCommonButtonBase;
class UCommonTextBlock;
class UFortActivityHabaneroButton;
class UFortActivityModeSetSelection;
class UFortActivityPrivacyButton;
class UFortActivitySquadFillButton;
class UFortGameActivity;
class UTexture;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortActivityModeSetSelectionModal : public UFortActivityModeSetSelectionModalBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool IsCreativeModeSetActivity() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnActivityChanged(const UFortGameActivity* GameActivity, const FString& StartingSelectedMnemonic);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewImageChanged(const bool bIsLoading, const UTexture* Texture);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSubModeSelected();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSubModeSelectionChanged();

	UFUNCTION(BlueprintCallable)
	void SaveSelectionAndClose();

	UFUNCTION(BlueprintImplementableEvent)
	void SetHabaneroValues(bool bHabaneroEnabled, bool bHabaneroExists);

	UFUNCTION(BlueprintImplementableEvent)
	void SetIsRankedSwitchAvailable(const bool bIsRankedSwitchAvailable);

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityModeSetSelectionModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActivityName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_BackBoard;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityModeSetSelectionModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityModeSetSelection> List_SubModeList;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityModeSetSelectionModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivitySquadFillButton> Button_ActivitySquadFill;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityModeSetSelectionModal", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortActivityPrivacyButton> Button_ActivityPrivacy;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortActivityModeSetSelectionModal", meta=(AllowPrivateAccess="TRUE", BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortActivityHabaneroButton> Button_Activity_Habanero;

};

