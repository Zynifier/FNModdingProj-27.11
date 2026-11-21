// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortFriendLinkPanel.generated.h"

class UCommonButtonLegacy;
enum class EShareButtonType : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EShareButtonType : uint8
{
	IOS = 0,
	Android = 1,
	Generic = 2,
};

UCLASS(meta=(DisableNativeTick))
class UFortFriendLinkPanel : public UFortActivatablePanel
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnCopiedToClipboard();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShareButtonTypeSet(EShareButtonType Type);

private:
	UPROPERTY(BlueprintReadWrite, Export, Category="FortFriendLinkPanel", meta=(AllowPrivateAccess="TRUE", BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ShareButton;

};

