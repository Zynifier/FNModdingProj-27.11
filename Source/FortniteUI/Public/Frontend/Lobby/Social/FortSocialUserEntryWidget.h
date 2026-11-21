// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SocialUserListEntry.h"
#include "FortSocialUserEntryWidget.generated.h"

class UFortSocialUser;
class UMenuAnchor;
class USocialActionMenu;
class UUserWidget;
enum class EFortSocialUserEntryType : uint8;

UENUM(BlueprintType)
enum class EFortSocialUserEntryType : uint8
{
	None = 0,
	PartyMember = 1,
	TeamMember = 2,
	VoiceChatMember = 3,
	UserSearchResult = 4,
	SuggestedFriend = 5,
	JoinRequest = 6,
	RecentPlayer = 7,
	SocialUser = 8,
	FriendInvite = 9,
	JoinableParty = 10,
};

UCLASS(MinimalAPI)
class UFortSocialUserEntryWidget : public USocialListEntryBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	UFortSocialUser* GetSocialUser() const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnSetSocialUser(UFortSocialUser* InSocialUser);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnSetUserEntryType(EFortSocialUserEntryType EntryType);

	UFUNCTION(BlueprintCallable)
	void SetSocialUserFromOwningPlayer();

	UFUNCTION(BlueprintCallable)
	void SpawnSocialActionMenu(UMenuAnchor* MenuAnchor, TSubclassOf<USocialActionMenu> ActionMenuClass);

private:
	UFUNCTION()
	UUserWidget* HandleGetMenuContext();

	UFUNCTION()
	void HandleMenuOpenChanged(bool bIsMenuOpen);

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UMenuAnchor> AssignedMenuAnchor;

};

