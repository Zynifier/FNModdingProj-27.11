// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "UI/FrontEnd/FortLockerConfig.h"
#include "ViewModels/Locker/FortLockerCategoryVM.h"
#include "AthenaLockerCategoryVM.generated.h"

class UFortAccountItemDefinition;

UCLASS(MinimalAPI)
class UAthenaLockerCategoryConfig : public UFortLockerCategoryConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaLockerCategoryConfig")
	TSoftObjectPtr<UFortAccountItemDefinition> FallbackItem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaLockerCategoryConfig")
	EAthenaCustomizationCategory Category;

};

UCLASS()
class UAthenaLockerCategoryVM : public UFortLockerCategoryVM
{
	GENERATED_BODY()

};

