// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Math/Color.h"
#include "FortHomebaseTypes.generated.h"

class UTexture2D;

USTRUCT()
struct FHomebaseBannerCategoryData : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerCategoryData")
	FText CategoryDisplayName;

	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerCategoryData")
	int32 SortPriority;

};

USTRUCT(BlueprintType)
struct FHomebaseBannerColor
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerColor")
	FLinearColor PrimaryColor;

	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerColor")
	FLinearColor SecondaryColor;

};

USTRUCT()
struct FHomebaseBannerColorData : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerColorData")
	FName ColorKeyName;

	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerColorData")
	FName CategoryRowName;

	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerColorData")
	int32 SubCategoryGroup;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerColorData")
	uint8 bGrantByDefault : 1;
#endif

};

USTRUCT()
struct FHomebaseBannerIconData : public FTableRowBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerIconData")
	TSoftObjectPtr<UTexture2D> SmallImage;

	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerIconData")
	TSoftObjectPtr<UTexture2D> LargeImage;

	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerIconData")
	FName CategoryRowName;

	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerIconData")
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerIconData")
	FText DisplayDescription;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerIconData")
	uint8 bGrantByDefault : 1;
#endif

	UPROPERTY(EditDefaultsOnly, Category="HomebaseBannerIconData")
	uint8 bFullUsageRights : 1;

};

