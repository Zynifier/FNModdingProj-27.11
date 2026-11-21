// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortSidebarOnboardTooltipWidget.generated.h"

class UCommonButtonLegacy;

UENUM(BlueprintType)
enum class ESocialTutorialType : uint8
{
	/** Default No Type Association */
	None = 0,
	/** Marks as Panel associated with Profile Taband Tags Editor */
	TagsEditor = 1,
	/** Marks as Panel associated with Looking For Party Tab */
	LookingForParty = 2,
	/** Marks as Panel associated with "Like Island" button */
	LikeIsland = 3,
	/** Marks as Panel associated with the Reboot Rally user list */
	RebootRallyUsers = 4,
	/** Marks as Panel K3S Settings shown in the sidebar */
	KWSSidebarSupervisedSettings = 5,
	/** Marks as Panel K3S Settings shown in the sidebar voice channel panel */
	KWSVoiceChannelPanelSupervisedSettings = 6,
	/** Marks a Panel associated with Voice Reporting */
	VoiceReport = 7,
	/** Marks a Panel associated with Content Ratings */
	ContentRatingSettings = 8,
	/** Marks a Panel associated with Unlocked Content */
	ContentUnlockedSettings = 9,
	/** Marks a Panel associated with unlocking Creative Content */
	CreativeContentSettings = 10,
};

UCLASS(meta=(DisableNativeTick))
class FORTNITEUI_API UFortSidebarOnboardTooltipWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void NotifyCloseAnimationFinished();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndTooltip();

	UFUNCTION(BlueprintImplementableEvent)
	void OnShowTooltip();

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarOnboardTooltipWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Dismiss_Button;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortSidebarOnboardTooltipWidget", meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> OtherAction_Button;

	UPROPERTY(BlueprintReadOnly, Category="FortSidebarOnboardTooltipWidget")
	int32 SecondsBeforeClosing;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Onboarding")
	ESocialTutorialType SocialTutorial;

	UPROPERTY(EditAnywhere, Category="Onboarding")
	FGameplayTag OnboardingSeenId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Onboarding")
	FVector2D PositionController;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Onboarding")
	FVector2D PositionKeyboardMouse;

};

