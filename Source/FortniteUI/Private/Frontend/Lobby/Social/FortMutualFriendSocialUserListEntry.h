// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSocialListUserEntryBase.h"
#include "FortMutualFriendSocialUserListEntry.generated.h"

class UBorder;
class UFortPlayerAvatar;
class UFortSocialAvatarIcon;
class URebootRallyIcon;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMutualFriendSocialUserListEntry : public UFortSocialListUserEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnNewAvatarsEnabledChanged(bool bUsingNewAvatars);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMutualFriendSocialUserListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Avatar_MemberIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortMutualFriendSocialUserListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortPlayerAvatar> PlayerAvatar;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<URebootRallyIcon> WBP_RebootRallyIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Border_Background;

};

