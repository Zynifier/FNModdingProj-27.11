// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "UI/FrontEnd/FortLockerConfig.h"
#include "ViewModels/Locker/FortLockerCategoryVM.h"
#include "AthenaBuiltInEmoteLockerCategoryVM.generated.h"

UCLASS()
class UAthenaBuiltInEmoteLockerCategoryConfig : public UFortLockerCategoryConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="AthenaBuiltInEmoteLockerCategoryConfig")
	TArray<EAthenaCustomizationCategory> BuiltInEmoteCategoryPriorities;

};

UCLASS()
class UAthenaBuiltInEmoteLockerCategoryVM : public UFortLockerCategoryVM
{
	GENERATED_BODY()

};

