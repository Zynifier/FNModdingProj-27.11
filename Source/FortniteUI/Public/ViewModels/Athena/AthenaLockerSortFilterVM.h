// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortInventoryFilterEnum.h"
#include "UI/FrontEnd/FortLockerConfig.h"
#include "ViewModels/Locker/FortLockerSortFilterVM.h"
#include "AthenaLockerSortFilterVM.generated.h"

UCLASS(BlueprintType, Blueprintable)
class UAthenaLockerCategoryFilterConfig : public UFortLockerCategoryFilterConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaLockerCategoryFilterConfig")
	FName FilterId;

};

UCLASS(BlueprintType, Blueprintable)
class UAthenaLockerCategorySortConfig : public UFortLockerCategorySortConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="AthenaLockerCategorySortConfig")
	EInventoryContentSortType SortType;

};

UCLASS()
class UAthenaLockerFilterItemVM : public UFortLockerFilterItemVM
{
	GENERATED_BODY()

};

UCLASS()
class UAthenaLockerSearchTextVM : public UFortLockerSearchTextVM
{
	GENERATED_BODY()

};

UCLASS()
class UAthenaLockerSortItemVM : public UFortLockerSortItemVM
{
	GENERATED_BODY()

};

