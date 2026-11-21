// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Styling/SlateColor.h"
#include "Team/FortCampaignTeamMemberEntry.h"
#include "FortCampaignHUDTeamMemberInfo.generated.h"

class AFortPawn;
class UCommonNumericTextBlock;
class UCommonTextBlock;
class UFortPlayerPowerRating;
class UFortVoiceChatStatusIcon;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCampaignHUDTeamMemberInfo : public UFortCampaignTeamMemberEntry
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandleAccumulatedItemsChanged();

	UFUNCTION()
	void HandleDBNOChanged(AFortPawn* Pawn, bool bInIsDBNO);

	UFUNCTION()
	void HandlePlayerPawnChanged();

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_HeroIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerPowerRating> PowerRating_MemberRating;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonNumericTextBlock> Text_BluGloCount;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortVoiceChatStatusIcon> VoiceIcon_Status;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MemberName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_LeaderIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_PlatformIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_HealthBar;

	UPROPERTY(Export, meta=(BindWidgetOptional, EditInline="true"))
	TObjectPtr<UImage> Image_ShieldBar;

	UPROPERTY(EditAnywhere, Category="FortCampaignHUDTeamMemberInfo")
	FSlateColor Color_PlayerNameAlive;

	UPROPERTY(EditAnywhere, Category="FortCampaignHUDTeamMemberInfo")
	FSlateColor Color_PlayerNameDead;

};

