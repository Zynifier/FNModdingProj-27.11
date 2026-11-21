// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ProgressiveCosmetic/FortProgressiveScreenBase.h"
#include "FortProgressiveTableOfContentsScreen.generated.h"

class UBattlePassCrewPurchaseButton;
class UCommonButtonBase;
class UCommonButtonGroupBase;
class UDynamicEntryBox;
class UFortItemDefinition;
class UFortProgressiveItemStateTitleWidget;
class UFortProgressiveSetDetailsWidget;
class UFortProgressiveSetList;
class UFortSubscriptionPlatformModal;
class UWidget;

USTRUCT()
struct FFortProgressiveSetRewardData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UFortItemDefinition> RewardToken;

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortProgressiveTableOfContentsScreen : public UFortProgressiveScreenBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Set Description Text"))
	void BP_OnSetDescriptionText(const FText& ProductDescription);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Update Banner"))
	void BP_OnUpdateBanner(const FText& BannerText, const bool bAllSetsCompleted, const bool bSubscribed);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Update Error State Text"))
	void BP_OnUpdateErrorStateText(const FText& ErrorStateText);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Update Num Tiles Available"))
	void BP_OnUpdateNumTilesAvailable(const int32 NumTiles);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Update Subscription State"))
	void BP_OnUpdateSubscriptionState(const bool bSubscribed);

	UPROPERTY(BlueprintReadWrite, Export, Category="FortProgressiveTableOfContentsScreen", meta=(EditInline="true"))
	TObjectPtr<UWidget> ContentPurchasedFocusWidget;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Back;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_TouchBack;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MoreInfo;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBattlePassCrewPurchaseButton> Button_Subscribe;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressiveSetList> Widget_SetList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressiveSetDetailsWidget> Widget_SetDetails;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortProgressiveItemStateTitleWidget> Widget_ItemStateTitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortProgressiveTableOfContentsScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_SetPagesPips;

	UPROPERTY()
	TObjectPtr<UCommonButtonGroupBase> ButtonGroup_SetPagesPips;

	UPROPERTY(EditDefaultsOnly, Category="FortProgressiveTableOfContentsScreen")
	TSoftClassPtr<UFortSubscriptionPlatformModal> MoreInfoModalClass;

	UPROPERTY(EditDefaultsOnly, Category="FortProgressiveTableOfContentsScreen")
	FName SubscribedMaterialParameterName;

};

