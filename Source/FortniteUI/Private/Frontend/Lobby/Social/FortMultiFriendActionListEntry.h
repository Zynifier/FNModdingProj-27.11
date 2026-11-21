// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSocialTypes.h"
#include "SocialUserListEntry.h"
#include "FortMultiFriendActionListEntry.generated.h"

enum class EMultiFriendAction : uint8;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMultiFriendActionListEntry : public USocialListInteractableEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActionUpdated(EMultiFriendAction InAction);

private:
	UPROPERTY(BlueprintReadOnly, Category="FortMultiFriendActionListEntry", meta=(AllowPrivateAccess))
	EMultiFriendAction Action;

};

