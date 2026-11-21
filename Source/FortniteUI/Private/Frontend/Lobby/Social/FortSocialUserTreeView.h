// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialUserTreeView.h"
#include "FortSocialUserTreeView.generated.h"

class UCommonUserWidget;
class UFortJoinablePartyListEntry;
class UFortLFGFilterCheckboxEntryWidget;
class UFortLeavePartyListEntry;
class UFortMissedInvitesListEntry;
class UFortMultiFriendActionListEntry;
class UFortPartyMemberListEntry;
class UFortReferFriendListEntry;
class UFortSidebarLfgState2ListEntry;
class UFortSocialListUserEntryBase;
class UFortSocialUserEntryWidget;
class UFortTeamMemberListEntry;
class UFortUserSearchResultListEntry;
class UFortVoiceChatMemberListEntry;
class USidebarLFGToggleListEntryWidget;
class USocialListEntryBase;
class USocialListInteractableEntryBase;
class USocialUserListHeaderEntry;

UCLASS(meta=(EntryClass="SocialUserListHeaderEntry"))
class UFortSocialUserTreeView : public USocialUserTreeView
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortPartyMemberListEntry> PartyMemberEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortTeamMemberListEntry> TeamMemberEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortVoiceChatMemberListEntry> VoiceChatMemberEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortJoinablePartyListEntry> JoinablePartyEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortJoinablePartyListEntry> JoinablePartyEntryWidgetClass_2;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortMissedInvitesListEntry> MissedInviteEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortReferFriendListEntry> ReferFriendEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortUserSearchResultListEntry> UserSearchResultEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortLeavePartyListEntry> LeavePartyEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<USocialListInteractableEntryBase> ShuffleLfgEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortSocialListUserEntryBase> SuggestedFriendEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortSocialListUserEntryBase> JoinRequestEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UCommonUserWidget> VoiceChannelHeaderEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UCommonUserWidget> VoiceChannelHeaderOptionEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortSocialListUserEntryBase> RecentPlayerEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<USocialListEntryBase> TagsNoFriendsEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<USidebarLFGToggleListEntryWidget> LfgToggleEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortLFGFilterCheckboxEntryWidget> LfgTagCheckboxEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<USocialListInteractableEntryBase> LfgFilterButtonEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortSocialListUserEntryBase> LfgInviteEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortSidebarLfgState2ListEntry> LfgState2EntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortMultiFriendActionListEntry> MultiFriendActionEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<USocialUserListHeaderEntry> LfgFilterHeaderEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<USocialUserListHeaderEntry> RebootPlayersHeaderEntryWidgetClass;

	UPROPERTY(EditAnywhere, Category="UserEntries")
	TSubclassOf<UFortSocialUserEntryWidget> ViewModelDrivenEntryWidgetClass;

};

