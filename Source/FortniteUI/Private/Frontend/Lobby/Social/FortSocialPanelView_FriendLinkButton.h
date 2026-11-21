// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonLegacy.h"
#include "FortSocialPanelView_FriendLinkButton.generated.h"

class UCommonBorder;
enum class EFriendLinkShareButtonType : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EFriendLinkShareButtonType : uint8
{
	IOS = 0,
	Android = 1,
	Generic = 2,
};

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialPanelView_FriendLinkButton : public UCommonButtonLegacy
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCopiedToClipboard();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShareButtonTypeSet(EFriendLinkShareButtonType Type);

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonBorder> Border_ScreenTarget;

};

