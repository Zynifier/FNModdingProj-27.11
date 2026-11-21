// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/FortItemPreviewPedestal.h"
#include "FortHeroLoadoutPedestal.generated.h"

class UFortCampaignHeroLoadoutItem;

UCLASS()
class AFortHeroLoadoutPedestal : public AFortItemPreviewPedestal
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHeroLoadoutPedestal")
	FName SlotName;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleSlotFocusInUIChanged();

	UPROPERTY(VisibleInstanceOnly, BlueprintReadOnly, Transient, Category="FortHeroLoadoutPedestal")
	TWeakObjectPtr<UFortCampaignHeroLoadoutItem> HeroLoadout;

	UPROPERTY(BlueprintReadOnly, Category="FortHeroLoadoutPedestal")
	bool bIsSlotFocusedInUI;

private:
	UFUNCTION()
	void HandleDifferentHeroLoadoutSlotFocused(const FName FocusedSlotName);

	UFUNCTION()
	void HandleDifferentLoadoutViewed(const UFortCampaignHeroLoadoutItem* PreviousLoadout, const UFortCampaignHeroLoadoutItem* CurrentLoadout);

	UFUNCTION()
	void HandleMCPProfilesInitialized();

};

