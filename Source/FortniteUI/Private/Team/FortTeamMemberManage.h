// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortActivatablePanel.h"
#include "FortTeamMemberManage.generated.h"

class UCommonButtonBase;
class UCommonTextBlock;
class UCommonWidgetSwitcherLegacy;
class UFortPlayerBanner;
class UFortPlayerPowerRating;
class UFortTeamMember;
class UVerticalBox;

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortTeamMemberManage : public UFortActivatablePanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetRepresentingTeamMember(int32 LocalTeamMemberIndex);

protected:
	UFUNCTION(BlueprintCallable)
	void OnBannerEditorClosed();

	UFUNCTION(BlueprintImplementableEvent)
	void OnParticipationChanged(bool bIsParticipating);

	UFUNCTION(BlueprintImplementableEvent)
	void OpenBannerEditor();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortTeamMemberManage", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ToggleParticipation;

private:
	UPROPERTY(Transient)
	TWeakObjectPtr<UFortTeamMember> TeamMember;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerBanner> Banner_PlayerBanner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_PlayerName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonWidgetSwitcherLegacy> PowerRatingWidgetSwitcher;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerPowerRating> PowerRating_MemberPowerRating;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerPowerRating> Moonbeam_PowerRating_MemberPowerRating;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UVerticalBox> VBox_Buttons;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_EditBanner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_LeaveParty;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_MakePartyLeader;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Whisper;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Kick;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_ViewProfile;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Mute;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonBase> Button_Unmute;

};

