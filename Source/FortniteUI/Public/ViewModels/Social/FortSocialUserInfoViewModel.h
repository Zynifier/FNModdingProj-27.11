// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ViewModels/Social/FortSocialUserViewModel.h"
#include "FortSocialUserInfoViewModel.generated.h"

UCLASS()
class FORTNITEUI_API UFortSocialUserInfoViewModel : public UFortSocialUserViewModel
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserInfoViewModel")
	FText LastInteractionInfo;

	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserInfoViewModel")
	FText UserRichPresenceText;

	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserInfoViewModel")
	FText MutualFriendsText;

	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserInfoViewModel")
	bool bShouldEncourageEpicFriendship;

	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserInfoViewModel")
	bool bIsRebootRallyEligible;

	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserInfoViewModel")
	bool bIsFriend;

	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserInfoViewModel")
	bool bIsSocialBanned;

	UPROPERTY(BlueprintReadOnly, Category="FortSocialUserInfoViewModel")
	bool bIsInviteSent;

};

