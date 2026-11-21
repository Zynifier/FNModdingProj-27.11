// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProgressiveCosmetic/FortProgressiveScreenBase.h"
#include "FortProgressiveItemScreen.generated.h"

class UBattlePassCrewPurchaseButton;
class UCommonButtonBase;
class UCommonButtonGroupBase;
class UCommonTextBlock;
class UDynamicEntryBox;
class UFortProgressiveItemDetailsWidget;
class UFortProgressiveItemStateTitleWidget;
class UFortProgressiveStageList;
class UFortSubscriptionPlatformModal;
class UWidget;

UCLASS(Abstract, MinimalAPI)
class UFortProgressiveItemScreen : public UFortProgressiveScreenBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnErrorStateTextUpdated(const FText& ErrorStateText);

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemSelected();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetIsSoloScreen(const bool bInIsSoloScreen);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateSubscriptionState(const bool bSubscribed);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortProgressiveItemScreen", meta=(EditInline="true"))
	TObjectPtr<UWidget> ContentPurchasedFocusWidget;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressiveItemScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchBack;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MoreInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassCrewPurchaseButton> Button_Subscribe;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_PreviewStyles;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressiveItemScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ExpirationFinePrint;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressiveItemScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NewStagesUnlockFinePrint;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressiveItemScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_StagesPips;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup_StagesPips;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressiveItemScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressiveItemDetailsWidget> Widget_ProgressiveItemDetails;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressiveItemScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressiveStageList> Widget_ProgressiveStageList;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressiveItemScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressiveItemStateTitleWidget> ProgressiveItemStateTitle;

	UPROPERTY(EditDefaultsOnly, Category="FortProgressiveItemScreen")
	TSoftClassPtr<UFortSubscriptionPlatformModal> MoreInfoModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortProgressiveItemScreen")
	FName SubscribedMaterialParameterName;

};

