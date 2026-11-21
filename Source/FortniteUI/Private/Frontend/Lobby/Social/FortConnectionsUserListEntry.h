// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSocialListUserEntryBase.h"
#include "FortConnectionsUserListEntry.generated.h"

class UCommonRichTextBlock;
class UFortPlayerAvatar;
class UFortSocialAvatarIcon;
class URebootRallyIcon;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortConnectionsUserListEntry : public UFortSocialListUserEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnNewAvatarsEnabledChanged(bool bUsingNewAvatars);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConnectionsUserListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_MutualFriends;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConnectionsUserListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> Text_MutualFriends_Hover;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConnectionsUserListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Avatar_MemberIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortConnectionsUserListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortPlayerAvatar> PlayerAvatar;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<URebootRallyIcon> WBP_RebootRallyIcon;

};

