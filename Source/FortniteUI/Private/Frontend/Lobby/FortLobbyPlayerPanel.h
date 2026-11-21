// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortLobbyPlayerPanel.generated.h"

class UCommonButtonBase;
class UFortPlayerBanner;
class UFortTeamMemberManage;
class UImage;
class URichTextBlock;
class UTextBlock;
enum class EFortFriendRequestStatus : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortLobbyPlayerPanel : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="TRUE"))
	void ClosePanel();

	UFUNCTION(BlueprintImplementableEvent)
	void OnFriendStatusUpdated(EFortFriendRequestStatus FriendRequestStatus);

	UPROPERTY(EditAnywhere, Category="FortLobbyPlayerPanel")
	TSubclassOf<UFortTeamMemberManage> ManageModalClass;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortLobbyPlayerPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_AddFriend;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_InviteParty;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Manage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Close;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerBanner> Banner_Player;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URichTextBlock> RichText_PlayerName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UTextBlock> Text_InviteSent;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_PlatformIcon;

};

