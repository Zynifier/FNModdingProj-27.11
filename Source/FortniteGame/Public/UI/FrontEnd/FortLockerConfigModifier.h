// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "FortSubGameTypes.h"
#include "FortLockerConfigModifier.generated.h"

class UFortLockerCategoryConfig;
class UFortLockerCategoryGroupConfig;

UCLASS(Abstract, MinimalAPI)
class UFortLockerConfigModifier : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortLockerConfigModifier")
	TSet<ESubGame> SubGamesToIgnore;

};

UCLASS(MinimalAPI)
class UFortLockerConfigModifier_AddCategories : public UFortLockerConfigModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortLockerConfigModifier_AddCategories")
	TMap<TObjectPtr<UFortLockerCategoryGroupConfig>, TObjectPtr<UFortLockerCategoryConfig>> CategoriesToAdd;

};

UCLASS(MinimalAPI)
class UFortLockerConfigModifier_AddCategoryGroups : public UFortLockerConfigModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortLockerConfigModifier_AddCategoryGroups")
	TArray<TObjectPtr<UFortLockerCategoryGroupConfig>> CategoryGroupsToAdd;

};

UCLASS(MinimalAPI)
class UFortLockerConfigModifier_OverrideCategories : public UFortLockerConfigModifier
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortLockerConfigModifier_OverrideCategories")
	TMap<TObjectPtr<UFortLockerCategoryConfig>, TObjectPtr<UFortLockerCategoryConfig>> CategoriesToOverride;

};

