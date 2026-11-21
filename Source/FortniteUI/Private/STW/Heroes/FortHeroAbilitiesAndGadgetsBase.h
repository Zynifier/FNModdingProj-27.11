// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Team/FortTeamMemberEntryBase.h"
#include "FortHeroAbilitiesAndGadgetsBase.generated.h"

class UFortCampaignHeroLoadoutItem;
class UFortGadgetsWidgetBase;
class UFortPerksWidget_NUI;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortHeroAbilitiesAndGadgetsBase : public UFortTeamMemberEntryBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="FortHeroAbilitiesAndGadgetsBase")
	void Refresh(UFortCampaignHeroLoadoutItem* HeroLoadout);

private:
	UPROPERTY(EditAnywhere, Category="FortHeroAbilitiesAndGadgetsBase")
	bool bHideAbilities;

	UPROPERTY(EditAnywhere, Category="FortHeroAbilitiesAndGadgetsBase")
	bool bHideGadgets;

	UPROPERTY(EditAnywhere, Category="FortHeroAbilitiesAndGadgetsBase")
	int32 AssignedMemberIndex;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortPerksWidget_NUI> HorizontalAbilitiesList;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UFortGadgetsWidgetBase> GadgetsWidget;

};

