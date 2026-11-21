// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "SocialUserListEntry.h"
#include "FortJoinablePartyListEntry.generated.h"

class UCommonActivatableWidgetSwitcher;
class UCommonRichTextBlock;
class UFortJoinablePartyPortraitsDisplay;
class URebootRallyIcon;
class USidebarSocialTagListBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortJoinablePartyListEntry : public USocialListInteractableEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void ForcePartyItemUpdate();

	UFUNCTION(BlueprintImplementableEvent)
	void OnInviteStatusUpdated(bool bIsInvited);

	UFUNCTION(BlueprintImplementableEvent)
	void OnPartyPresenceTextUpdated();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortJoinablePartyListEntry")
	FColor InviteTextColor;

	UPROPERTY(EditAnywhere, Category="FortJoinablePartyListEntry")
	FColor DimmerInviteColor;

	UPROPERTY(EditAnywhere, Category="FortJoinablePartyListEntry")
	FColor DimmerDefaultColor;

	UPROPERTY(EditAnywhere, Category="FortJoinablePartyListEntry")
	uint32 SecondNameFontSize;

	UPROPERTY(EditAnywhere, Category="FortJoinablePartyListEntry")
	uint8 MaxNamesToDisplay;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortJoinablePartyListEntry")
	FColor SidebarPartyPresenceTextColorDefault;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortJoinablePartyListEntry")
	FColor SidebarJoinablePartyTextColorDefault;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortJoinablePartyListEntry")
	FColor SidebarFriendNameTextColorDefault;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortJoinablePartyListEntry")
	FColor SidebarOtherMembersTextColorDefault;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortJoinablePartyListEntry")
	FColor SidebarPartyPresenceTextColorHover;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortJoinablePartyListEntry")
	FColor SidebarJoinablePartyTextColorHover;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortJoinablePartyListEntry")
	FColor SidebarFriendNameTextColorHover;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortJoinablePartyListEntry")
	FColor SidebarOtherMembersTextColorHover;

	UPROPERTY(EditAnywhere, Category="FortJoinablePartyListEntry")
	uint32 SidebarOtherMembersFontSize;

	UPROPERTY(EditAnywhere, Category="FortJoinablePartyListEntry")
	int32 DisplayNameMaxChars;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyListEntry", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_DisplayNames;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_PartyPresence;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_JoinableParty;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortJoinablePartyPortraitsDisplay> PartyPortraitsDisplay;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<URebootRallyIcon> WBP_RebootRallyIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_DisplayNames_Hover;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_PartyPresence_Hover;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_JoinableParty_Hover;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortJoinablePartyListEntry", meta=(AllowPrivateAccess, BindWidgetOptional, EditInline="true"))
	TObjectPtr<USidebarSocialTagListBase> SocialTagList;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortJoinablePartyListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_PartyPresenceText;

};

