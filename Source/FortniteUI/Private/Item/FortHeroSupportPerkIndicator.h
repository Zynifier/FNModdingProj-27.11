// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Item/FortIconWithLabel.h"
#include "STW/Heroes/FortHeroSpecialization.h"
#include "FortHeroSupportPerkIndicator.generated.h"

class UFortItem;
enum class EFortSupportBonusType : uint8;

UCLASS(BlueprintType)
class UFortHeroSupportPerkIndicator : public UFortIconWithLabel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Hero Support Perk Indicator")
	void SetItemToRepresent(const UFortItem* ItemToRepresent);

	UFUNCTION(BlueprintCallable, Category="Hero Support Perk Indicator")
	void SetSupportTypeToRepresent(const EFortSupportBonusType SupportTypeToRepresent);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hero Support Perk Indicator", meta=(ExposeOnSpawn))
	TWeakObjectPtr<UFortItem> ItemToRepresent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Hero Support Perk Indicator", meta=(ExposeOnSpawn))
	EFortSupportBonusType SupportTypeToRepresent;

};

