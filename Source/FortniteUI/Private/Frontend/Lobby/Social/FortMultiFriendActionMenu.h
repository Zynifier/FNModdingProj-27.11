// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSocialTypes.h"
#include "SocialInteractionMenu.h"
#include "FortMultiFriendActionMenu.generated.h"

class UCommonButtonBase;

UCLASS(Abstract, meta=(DisableNativeTick))
class UFortMultiFriendActionMenu : public USocialActionMenu
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnActionUpdated();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Confirm;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Decline;

	UPROPERTY(BlueprintReadOnly, Category="FortMultiFriendActionMenu", meta=(AllowPrivateAccess))
	EMultiFriendAction Action;

};

