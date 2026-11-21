// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Layout/Margin.h"
#include "FortCreativeCreatorAttributions.generated.h"

class UFortActivityBrowserAttributionsModal;
class UFortCreativeCreditsAttributions;
class UFortCreativeCreditsSectionTitle;
class UFortCreativeCreditsTeamTitleCard;
class UFortDynamicEntryBox;
class UFortGameActivity;
class UUserWidget;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeCreatorAttributions : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnAttributionsButtonCreated() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCreditsButtonCreated() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSectionTitleCreated(UFortCreativeCreditsSectionTitle* SectionTitle);

	UFUNCTION(BlueprintImplementableEvent)
	void OnTeamMemberTitleCardButtonCreated(UFortCreativeCreditsTeamTitleCard* TeamMemberButton) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnTitleCardButtonCreated() const;

private:
	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreatorAttributions", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<UFortDynamicEntryBox> DynamicEntryBox_CreditsContainer;

	UPROPERTY(EditAnywhere, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	FText CreatorTitle;

	UPROPERTY(EditAnywhere, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	FText AttributionsTitle;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> AttributionsTitleWidget;

	UPROPERTY(EditAnywhere, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	FText CreditsTitle;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UUserWidget> CreditsTitleWidget;

	UPROPERTY(EditAnywhere, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	FText AttributionsTextFormat;

	UPROPERTY(EditAnywhere, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	TSubclassOf<UFortCreativeCreditsTeamTitleCard> CreditsTeamTitleCardClass;

	UPROPERTY(EditAnywhere, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	TSubclassOf<UFortCreativeCreditsAttributions> CreditsCreatorAttributionsClass;

	UPROPERTY(EditAnywhere, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	TSoftClassPtr<UFortActivityBrowserAttributionsModal> CreditsAttributionsModalClass;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreatorAttributions", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UFortCreativeCreditsTeamTitleCard> Button_CreditsTeamTitleCard;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreatorAttributions", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UFortCreativeCreditsAttributions> Button_CreditsAttributions;

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCreativeCreatorAttributions", meta=(AllowPrivateAccess, EditInline="true"))
	TObjectPtr<UFortCreativeCreditsAttributions> Button_Credits;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	FMargin SectionTitlePadding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	FMargin TitleCardButtonPadding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	FMargin TeamMemberButtonPadding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	FMargin AttributionsButtonPadding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreatorAttributions", meta=(AllowPrivateAccess))
	FMargin CreditsButtonPadding;

	UPROPERTY(Transient)
	TObjectPtr<UFortGameActivity> CurrentGameActivity;

};

