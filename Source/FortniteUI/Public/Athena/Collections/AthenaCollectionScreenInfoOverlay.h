// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "AthenaCollectionScreenInfoOverlay.generated.h"

class UAthenaCollectionLeaderboard;
class UCommonButtonBase;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UFortDynamicEntryBox;
class UImage;
class UObject;
class UPanelWidget;
enum class EFortCollectedState : uint8;

UCLASS(Abstract, MinimalAPI, meta=(DisableNativeTick))
class UAthenaCollectionScreenInfoOverlay : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Collected State Set"))
	FORTNITEUI_API void BP_OnCollectedStateSet(EFortCollectedState CollectedState);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Context Tags Updated"))
	FORTNITEUI_API void BP_OnContextTagsUpdated(int32 NumContextTags);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Friend Leaderboard Activated"))
	FORTNITEUI_API void BP_OnFriendLeaderboardActivated();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Friend Leaderboard Deactivated"))
	FORTNITEUI_API void BP_OnFriendLeaderboardDeactivated();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Friend Scores Updated"))
	FORTNITEUI_API void BP_OnFriendScoresUpdated(int32 NumFriendScores);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Has Additional Info Set"))
	FORTNITEUI_API void BP_OnHasAdditionalInfoSet(bool bHasAdditionalInfo);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Hide Leaderboard"))
	FORTNITEUI_API void BP_OnHideLeaderboard();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Info Overlay Reset"))
	FORTNITEUI_API void BP_OnInfoOverlayReset();

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Item Icon Loaded"))
	FORTNITEUI_API void BP_OnItemIconLoaded(UObject* ItemIcon);

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="On Show Leaderboard"))
	FORTNITEUI_API void BP_OnShowLeaderboard();

	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Item Icon"))
	FName ParamName_ItemIcon;

	UPROPERTY(EditAnywhere, Category="Material Param Names", meta=(DisplayName="Is Discovered"))
	FName ParamName_IsDiscovered;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_AdditionalInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionScreenInfoOverlay", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ItemImage;

private:
	UPROPERTY(EditAnywhere, Category="Text")
	FText NumCollectedTextFormat;

	UPROPERTY(EditAnywhere, Category="Text")
	FText EmptyDisplayNameText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaCollectionScreenInfoOverlay", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ToggleLeaderboardRowHandle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemType;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_Description;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_AdditionalDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UPanelWidget> Panel_FriendScores;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_NumCollected;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ItemNumber;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true", EntryClass="AthenaCollectionLeaderboardEntry"))
	TObjectPtr<UFortDynamicEntryBox> EntryBox_InfoOverlay;

	UPROPERTY(BlueprintReadOnly, Export, Category="AthenaCollectionScreenInfoOverlay", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UAthenaCollectionLeaderboard> FriendLeaderboard;

};

