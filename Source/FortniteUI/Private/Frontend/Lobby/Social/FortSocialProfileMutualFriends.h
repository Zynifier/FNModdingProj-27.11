// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Frontend/Lobby/Social/FortSocialProfilePanel.h"
#include "FortSocialProfileMutualFriends.generated.h"

class UDynamicEntryBox;
class USocialUser;
class UWidget;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialProfileMutualFriends : public UFortSocialProfileSubPanel
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleOnQueryMutualFriendsComplete(const TArray<FUniqueNetIdRepl> MutualFriendIds);

	UPROPERTY(EditDefaultsOnly, Category="FortSocialProfileMutualFriends")
	int32 MaxNumberOfDisplayedMutualFriends;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_MutualFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UWidget> SizeBox_Root;

	UPROPERTY()
	TArray<TObjectPtr<USocialUser>> MutualFriendSocialUsers;

};

