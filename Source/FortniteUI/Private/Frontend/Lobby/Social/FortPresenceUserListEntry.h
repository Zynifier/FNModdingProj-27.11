// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSocialListUserEntryBase.h"
#include "FortPresenceUserListEntry.generated.h"

class UBorder;
class UCommonActivatableWidgetSwitcher;
class UFortPlayerAvatar;
class UFortSocialAvatarIcon;
class UFortSocialEventRSVPWidget;
class URebootRallyIcon;

UCLASS(Abstract)
class UFortPresenceUserListEntry : public UFortSocialListUserEntryBase
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnNewAvatarsEnabledChanged(bool bUsingNewAvatars);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPresenceUserListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Avatar_MemberIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPresenceUserListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortPlayerAvatar> PlayerAvatar;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<URebootRallyIcon> WBP_RebootRallyIcon;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialEventRSVPWidget> BuffetInfo;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortPresenceUserListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> Border_OnlineStatusIndicator;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Border_Background;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UBorder> Border_Highlight;

	UPROPERTY(BlueprintReadWrite, Export, Category="FortPresenceUserListEntry", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonActivatableWidgetSwitcher> Switcher_RichPresence;

};

