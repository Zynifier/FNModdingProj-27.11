// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Cosmetics/Items/AthenaCosmeticItemDefinition.h"
#include "FortHomebaseBannerIconItemDefinition.generated.h"

UENUM()
enum class EBannerUsageContext : uint8
{
	// Unknown usage, default to conservative interpretation of usage rights

	Unknown = 0,
	// STW or BR banner icon in front-end

	BannerIcon = 1,
	// In-world 3D banner representation

	PhysicalBanner = 2,
	// In-world spray

	Spray = 3,
};

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Sacrifice", "Conversion", "AccountItem", "InventoryLimit", "Rating", "Level", "Tooltips", "Functionality", "FortItemDefinition"))
class UFortHomebaseBannerIconItemDefinition : public UAthenaCosmeticItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortHomebaseBannerIconItemDefinition", meta=(RowType="/Script/FortniteGame.HomebaseBannerCategoryData"))
	FDataTableRowHandle Category;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortHomebaseBannerIconItemDefinition")
	uint8 bGrantByDefault : 1;
#endif

	UPROPERTY(EditDefaultsOnly, AssetRegistrySearchable, Category="FortHomebaseBannerIconItemDefinition")
	uint8 bFullUsageRights : 1;

};

