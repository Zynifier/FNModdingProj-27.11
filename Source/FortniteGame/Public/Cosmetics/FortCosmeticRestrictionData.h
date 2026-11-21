// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "Cosmetics/FortCosmeticLoadout.h"
#include "FortCosmeticRestrictionData.generated.h"

UENUM()
enum class EFortCosmeticItemBlockedTextFlags : uint8
{
	None = 0,
	ItemShop = 1,
};

UENUM()
enum class EFortCosmeticRestrictionTagType : uint8
{
	/** Restriction query only checks the tags on the base item definition (no meta tags) */
	ItemTags = 0,
	/** Restriction query only checks the meta tags (not the tags on the base item definition) */
	MetaTags = 1,
	/** Restriction query checks both the tags on the base item definition and the meta tags */
	Both = 2,
};

USTRUCT()
struct FFortCosmeticRestrictionSourceQuery
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortCosmeticRestrictionSourceQuery")
	EFortCosmeticRestrictionTagType TagType;

	UPROPERTY(EditAnywhere, Category="FortCosmeticRestrictionSourceQuery")
	FGameplayTagQuery TagQuery;

};

USTRUCT()
struct FFortCosmeticRestrictionTargetQuery
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortCosmeticRestrictionTargetQuery")
	FGameplayTagQuery TagQuery;

	UPROPERTY(EditAnywhere, Category="FortCosmeticRestrictionTargetQuery")
	EAthenaCustomizationCategory ItemType;

};

USTRUCT()
struct FFortCosmeticRestrictionDefinition
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortCosmeticRestrictionDefinition")
	FFortCosmeticRestrictionSourceQuery SourceItemQuery;

	UPROPERTY(EditAnywhere, Category="FortCosmeticRestrictionDefinition")
	FFortCosmeticRestrictionTargetQuery TargetItemQuery;

	UPROPERTY(EditAnywhere, Category="FortCosmeticRestrictionDefinition")
	FText RestrictionActiveText;

	UPROPERTY(EditAnywhere, Category="FortCosmeticRestrictionDefinition")
	FText ItemBlockedText;

	UPROPERTY(EditAnywhere, Category="FortCosmeticRestrictionDefinition")
	FText ItemBlockedShopText;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortCosmeticRestrictionDefinition")
	FString RestrictionName;
#endif

};

UCLASS(MinimalAPI)
class UFortCosmeticRestrictionData : public UPrimaryDataAsset
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortCosmeticRestrictionData", meta=(TitleProperty="RestrictionName"))
	TArray<FFortCosmeticRestrictionDefinition> Restrictions;

	UPROPERTY(EditAnywhere, Category="Additional Restrictions")
	FGameplayTagQuery ProhibitedInSprayVariantsQuery;

};

