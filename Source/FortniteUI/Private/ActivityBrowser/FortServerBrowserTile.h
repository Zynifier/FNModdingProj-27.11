// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/IUserListEntry.h"
#include "CommonUserWidget.h"
#include "CommonButtonLegacy.h"
#include "FortServerBrowserTile.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UDynamicEntryBox;
class UImage;
class URichTextBlock;
class UVerticalBox;

UENUM()
enum class EFortServerItemIneligibleReason : uint8
{
	None = 0,
	PartyTooBig = 1,
	PartyTooSmall = 2,
	NotPartyLeader = 3,
	MatchmakingAlready = 4,
	NotSupportedByLeto = 5,
	InvalidData = 6,
};

UCLASS(Abstract, NotBlueprintable)
class UFortServerTileBase : public UCommonButtonLegacy, public IUserListEntry
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnLaunchButtonEnableChanged(bool bEnableValue);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ServerWarning;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortServerTileBase", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_Launch;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortServerInfoTileBase : public UFortServerTileBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void OnOwnerNameUpdated();

	UFUNCTION(BlueprintImplementableEvent, Category="Cosmetic")
	void RequestUpdateBackgroundImage(int32 FriendListHash);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_ServerFriendList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_OwnerName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VerticalBox_Ownership;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCreativeServerInfoTile : public UFortServerInfoTileBase
{
	GENERATED_BODY()

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FriendsPlaying;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_RemainingFriends;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortServerActionTile : public UFortServerTileBase
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortNamedServerActionTile : public UFortServerActionTile
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintPure)
	bool IsActionIslandSelectType() const;

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateButtonText();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActionTitle;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ActionDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_Background;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortPlaylistSelectionActionTile : public UFortNamedServerActionTile
{
	GENERATED_BODY()

};

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortServerInfoFriendEntry : public UCommonUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_FriendName;

};

