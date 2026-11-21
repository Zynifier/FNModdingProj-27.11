// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Items/FortAccountItemDefinition.h"
#include "FortCampaignHeroLoadoutItemDefinition.generated.h"

class UFortHomebaseNodeItemDefinition;

USTRUCT(BlueprintType)
struct FFortCrewSlotInformation
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCrewSlotInformation")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCrewSlotInformation")
	FName SlotName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCrewSlotInformation")
	FGameplayTagContainer SlotTags;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortCrewSlotInformation", meta=(ClampMin="0.0"))
	float SlotStatContribution;

};

UCLASS(MinimalAPI, NotBlueprintable)
class UFortCampaignHeroLoadoutItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FFortCrewSlotInformation& GetCommanderSlot() const;

	UFUNCTION(BlueprintPure)
	int32 GetSlotIndexByName(const FName& SlotName) const;

	UFUNCTION(BlueprintPure)
	const TArray<FFortCrewSlotInformation>& GetSlots() const;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortCampaignHeroLoadoutItemDefinition")
	TArray<FFortCrewSlotInformation> CrewSlots;

	UPROPERTY(EditDefaultsOnly, Category="FortCampaignHeroLoadoutItemDefinition")
	FGameplayTagQuery CommanderSlotQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortCampaignHeroLoadoutItemDefinition")
	FGameplayTagQuery SupportHeroSlotQuery;

	UPROPERTY(EditDefaultsOnly, Category="FortCampaignHeroLoadoutItemDefinition")
	int32 GadgetSlotsAllowed;

	UPROPERTY(EditDefaultsOnly, Category="FortCampaignHeroLoadoutItemDefinition")
	FName SlotUnlockSquadName;

	UPROPERTY(EditDefaultsOnly, Category="FortCampaignHeroLoadoutItemDefinition")
	TSoftObjectPtr<UFortHomebaseNodeItemDefinition> TeamPerkUnlockNode;

};

