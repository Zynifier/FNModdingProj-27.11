// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Team/FortCampaignTeamMemberItemTracker.h"
#include "FortCampaignTeamMemberBoosts.generated.h"

class UCommonButtonLegacy;
class UCommonTextBlock;
class UFortPlayerBanner;
class UImage;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCampaignTeamMemberDailyBonusXpBoost : public UFortCampaignTeamMemberItemTracker
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="TeamMemberBoosts")
	int32 GetCurrentBoostAmount() const;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostAmountChanged();

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Boost;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_BoostIcon;

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCampaignTeamMemberXpBoost : public UFortCampaignTeamMemberItemTracker
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="TeamMemberBoosts")
	int32 GetCurrentBoostAmount() const;

protected:
	UFUNCTION(BlueprintCallable, Category="TeamMemberBoosts")
	void CenterWidget();

	UFUNCTION(BlueprintPure, Category="TeamMemberBoosts")
	UCommonButtonLegacy* GetBoostActivationButton() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnBoostAmountChanged();

	UFUNCTION(BlueprintImplementableEvent)
	void OnConsumeBoostComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void OnConsumeBoostStarted();

	UFUNCTION(BlueprintCallable, Category="TeamMemberBoosts")
	void SetConsumeRequestInProgress(bool bIsRequestInProgress);

	UPROPERTY(EditDefaultsOnly, Category="TeamMemberBoosts")
	FText NoPartyMemberString;

	UPROPERTY(EditDefaultsOnly, Category="TeamMemberBoosts")
	FText LocalPlayerXpBoostConfirmationTitle;

	UPROPERTY(EditDefaultsOnly, Category="TeamMemberBoosts")
	FText LocalPlayerXpBoostConfirmationText;

	UPROPERTY(EditDefaultsOnly, Category="TeamMemberBoosts")
	FText RemotePlayerXpBoostConfirmationTitle;

	UPROPERTY(EditDefaultsOnly, Category="TeamMemberBoosts")
	FText RemotePlayerXpBoostConfirmationText;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPlayerBanner> Banner_MemberBanner;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_MemberName;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonTextBlock> Text_Boost;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> Image_BoostIcon;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UCommonButtonLegacy> Button_ActivateBoost;

};

