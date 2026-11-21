// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSidebarButtons.h"
#include "FortSocialSidebarLocalUserButton.generated.h"

class UFortPlayerAvatar;
class UFortSocialAvatarIcon;
class UImage;
enum class ELocalUserOnlineStatus : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialSidebarLocalUserButton : public UFortSocialSidebarButtonBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnNewAvatarsEnabledChanged(bool bUsingNewAvatars);

	UFUNCTION(BlueprintImplementableEvent)
	void OnOnlineStatusChanged(ELocalUserOnlineStatus OnlineStatus);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialSidebarLocalUserButton", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> SocialAvatarIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialSidebarLocalUserButton", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortPlayerAvatar> PlayerAvatar;

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_Crown;

};

