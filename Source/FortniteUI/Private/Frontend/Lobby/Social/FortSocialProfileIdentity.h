// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Lobby/Social/FortSocialProfilePanel.h"
#include "FortSocialProfileIdentity.generated.h"

class UBorder;
class UCommonRichTextBlock;
class UFortPlayerAvatar;
class UFortSocialAvatarIcon;
class UFortVoiceChatStatusIcon;
class UOverlay;
class URebootRallyIcon;
class USocialNameTextBlock;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortSocialProfileIdentity : public UFortSocialProfileSubPanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetBattlePassVisiblity(bool bIsVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void SetFortniteCrewVisiblity(bool bIsVisible);

	UFUNCTION(BlueprintImplementableEvent)
	void SetSeasonLevel(int32 Level);

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnNewAvatarsEnabledChanged(bool bUsingNewAvatars);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialProfileIdentity", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortSocialAvatarIcon> Avatar_SocialAvatarIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialProfileIdentity", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UFortPlayerAvatar> PlayerAvatar;

private:
	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> Border_OnlineStatusIndicator;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UBorder> Border_OnlineStatusOutline;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<URebootRallyIcon> WBP_RebootRallyIcon;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialProfileIdentity", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_FortniteCrew;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSocialProfileIdentity", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UOverlay> Overlay_BattlePass;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USocialNameTextBlock> Text_SocialName;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonRichTextBlock> RichText_PlatformNames;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVoiceChatStatusIcon> VoiceIcon_Status;

};

