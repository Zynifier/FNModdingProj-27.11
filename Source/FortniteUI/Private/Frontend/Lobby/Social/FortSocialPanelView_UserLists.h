// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "Styling/SlateColor.h"
#include "Types/SlateEnums.h"
#include "CommonButtonLegacy.h"
#include "SocialUserListEntry.h"
#include "FortSocialPanelView_UserLists.generated.h"

class UCommonButtonGroupLegacy;
class UCommonButtonLegacy;
class UCommonRichTextBlock;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UEditableText;
class UFortCTAButton;
class UFortFriendSearchButton;
class UFortJoinVoiceChannelButton;
class UFortLocalUserEntry;
class UFortMainMenuButton;
class UFortSocialTab;
class UFortSocialUserTreeView;
class UFortVoiceSettingsDisplay;
class UImage;
class UTexture2D;
class UVerticalBox;
class UVoiceRepModal;
class UWidget;
enum class ESocialCommsPermission : uint8;

UENUM()
enum class EListHeaderType : uint8
{
	TeamMember = 0,
	PartyMember = 1,
	JoinableParty = 2,
	PlatformOnlineFriend = 3,
	McpOnlineFriend = 4,
	OfflineFriend = 5,
	Blocked = 6,
	FriendInvite = 7,
	SuggestedFriend = 8,
	RecentPlayer = 9,
	SearchResults = 10,
	JoinRequests = 11,
	LfgFilter = 12,
	LfgPlayers = 13,
	LfgInvites = 14,
	RebootPlayers = 15,
	GameVoice = 16,
	PartyVoice = 17,
	PlatformVoice = 18,
	AwayFriend = 19,
	Hidden = 20,
	Invalid = 21,
};

USTRUCT()
struct FFortUserListHeaderInfo
{
	GENERATED_BODY()

};

UCLASS(Abstract, Config=Game, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortFriendSearchButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected="TRUE"))
	void SetKeyboardFocusOnAddFriendText();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortFriendSearchButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UEditableText> EditableText_AddFriend;

private:
	UFUNCTION()
	void HandleAddFriendTextChanged(const FText& Text);

	UFUNCTION()
	void HandleAddFriendTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_SocialBanTimerText;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ClearQuery;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_SubmitQuery;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_SocialBan;

	UPROPERTY(Config)
	uint8 MaxFriendSearchNameLength;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortJoinVoiceChannelButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialPanelView_UserLists : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleNextTabAction_STW(bool& bPassThrough);

	UFUNCTION()
	void HandlePrevTabAction_STW(bool& bPassThrough);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetVoiceChannelButtonText(const FText& ButtonText);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateAudioModerationAcceptPanelText(const FText& Title, const FText& Description);

private:
	UFUNCTION()
	void FocusSearchResultsAfterQueryEnd(UWidget* ActiveWidget, int32 ActiveWidgetIndex);

	UPROPERTY(Transient)
	TObjectPtr<UCommonButtonGroupLegacy> ButtonGroup_SocialTabs;

	UPROPERTY(EditAnywhere, Category="FortSocialPanelView_UserLists", meta=(MultiLine="true"))
	FText PartyVoiceMessage_PSN;

	UPROPERTY(EditAnywhere, Category="FortSocialPanelView_UserLists", meta=(MultiLine="true"))
	FText PlatformPartyChatMessageHeader_PSN;

	UPROPERTY(EditAnywhere, Category="FortSocialPanelView_UserLists", meta=(MultiLine="true"))
	FText LeavePlatformPartyInstructions_PSN;

	UPROPERTY(EditAnywhere, Category="FortSocialPanelView_UserLists", meta=(MultiLine="true"))
	FText PartyVoiceMessage_XBL;

	UPROPERTY(EditAnywhere, Category="FortSocialPanelView_UserLists", meta=(MultiLine="true"))
	FText PlatformPartyChatMessageHeader_XBL;

	UPROPERTY(EditAnywhere, Category="FortSocialPanelView_UserLists", meta=(MultiLine="true"))
	FText LeavePlatformPartyInstructions_XBL;

	UPROPERTY(Transient)
	TArray<FFortUserListHeaderInfo> ListHeaderInfos;

	UPROPERTY(EditAnywhere, Category="FortSocialPanelView_UserLists", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle NextTabInputAction;

	UPROPERTY(EditAnywhere, Category="FortSocialPanelView_UserLists", meta=(RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle PreviousTabInputAction;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortLocalUserEntry> UserEntry_LocalPlayer;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortFriendSearchButton> Button_FriendSearch;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_UserLists;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialTab> SocialTab_AddFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialTab> SocialTab_Friends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialTab> SocialTab_VoiceChat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialUserTreeView> UserTree_FriendsLists;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialUserTreeView> UserTree_VoiceChat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVoiceSettingsDisplay> VoiceChannelSettings;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialUserTreeView> UserTree_AddFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_AddWeGameFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_VoiceChatState;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_VoicePlatformPartyWithSwitchButton;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_VoicePlatformPartyInstructions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_VoiceAcceptAudioMod;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_VoiceChatAcceptAudioMod;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortCTAButton> Button_VoiceChatLearnMoreAudioMod;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortJoinVoiceChannelButton> Button_JoinVoiceChat;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialPanelView_UserLists", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_LeavePlatformVoiceChat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_EnableVoiceChat;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PartyVoiceMessage;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_SocialBanDescription;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_SocialBanRemainingTime_VoiceTab;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_PlatformPartyChatMessageHeader;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_LeavePlatformPartyInstructions;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> Switcher_AddFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortSocialUserTreeView> UserTree_SearchResults;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SearchingForUsers;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_SearchFailed;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialTab : public UCommonButtonLegacy
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortSocialTab")
	TObjectPtr<UTexture2D> TabIcon;

	UPROPERTY(EditAnywhere, Category="FortSocialTab")
	FText TabName;

	UPROPERTY(EditAnywhere, Category="FortSocialTab")
	FSlateColor InviteTintColor;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_TabIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_TabName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Number;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Bang;

};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortVoiceChannelHeaderButton : public USocialListEntryBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanJoinChannel() const;

protected:
	UFUNCTION(BlueprintCallable)
	void HandleActionButtonClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void HandleHeaderClicked();

	UFUNCTION(BlueprintCallable)
	void HandleReportButtonClicked();

	UFUNCTION(BlueprintPure)
	bool IsActiveChannel() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateOptionsVisuals(ESocialCommsPermission VoicePermission, bool bVoiceReportingIsAvailable, bool bIsRecording, bool bCanJoinOrLeave, bool bMightBeAbleToReport);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateVisuals(bool bIsActiveAndListening, bool bIsActiveOrAvailable, bool bIsAvailableAndNotActive, bool bIsListening, bool bShowingRestriction);

	UFUNCTION(BlueprintImplementableEvent)
	void SetChannelRecordingState(bool bIsRecording);

	UFUNCTION(BlueprintImplementableEvent)
	void SetExpansionState(const bool bIsExpanded);

	UFUNCTION(BlueprintCallable)
	void ShowVoiceRepModal();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVoiceChannelHeaderButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_ChannelTitle;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVoiceChannelHeaderButton", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_ChannelTitle_Hover;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVoiceChannelHeaderButton", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChannelInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortVoiceChannelHeaderButton", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_ChannelInfo_Hover;

private:
	UPROPERTY(EditAnywhere, Category="FortVoiceChannelHeaderButton", meta=(AllowPrivateAccess))
	TSubclassOf<UVoiceRepModal> VoiceRepReportModalClass;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortVoiceChannelHeaderButton", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortMainMenuButton> JoinLeaveButton;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortVoiceChannelHeaderButton", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortMainMenuButton> ReportButton;

};

