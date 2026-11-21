// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Items/AthenaDanceItemDefinition.h"
#include "AthenaMultiStateEmoteItemDefinition.generated.h"

class AFortPlayerPawn;
class UFortMontageItemDefinitionBase;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition", "Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UAthenaMultiStateEmoteItemDefinition : public UAthenaDanceItemDefinition
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AdvanceActiveEmoteIndex();

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void PlayActiveEmote(AFortPlayerPawn* FortPawn, bool bAdvanceActiveEmote = true);

	UFUNCTION(BlueprintCallable)
	void ResetActiveEmoteIndex();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Emote")
	TArray<TSoftObjectPtr<UFortMontageItemDefinitionBase>> EmoteStageList;

};

