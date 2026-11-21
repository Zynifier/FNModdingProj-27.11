// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Conversation/FortConversationControllerRequirement.h"
#include "Conversation/FortThresholdTestConfig.h"
#include "FortWeaponEnums.h"
#include "FortControllerRequirement_HasWeaponTypeQuantity.generated.h"

UCLASS(AutoCollapseCategories=("Filtering"), meta=(DisplayName="Require: Has Weapon Type Quantity"))
class UFortControllerRequirement_HasWeaponTypeQuantity : public UFortControllerRequirement
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Filtering")
	FThresholdTestConfig ThresholdTestConfig;

	UPROPERTY(EditAnywhere, Category="Filtering")
	EFortWeaponType WeaponTypeFilter;

};

