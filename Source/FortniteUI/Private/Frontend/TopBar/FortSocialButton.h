// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortSocialButton.generated.h"

class UCommonTextBlock;
class UImage;

UCLASS(Abstract)
class UFortSocialButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnNumFriendsTextUpdated(const int32 FriendsOnline);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_NumFriends;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_ActiveInviteBang;

};

