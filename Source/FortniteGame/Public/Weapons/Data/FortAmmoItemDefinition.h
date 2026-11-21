// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Styling/SlateBrush.h"
#include "Creative/FortCreativeTags.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "FortMultiSize.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortAmmoItemDefinition.generated.h"

class UFortWorldItem;
class UPlaylistUserOptions;
class UTexture2D;

UCLASS(MinimalAPI, BlueprintType)
class UFortAmmoItemDefinition : public UFortWorldItemDefinition, public IFortCreativeTagsBearer, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Ammo Item")
	virtual TSoftObjectPtr<UTexture2D> GetHUDAmmoSmallPreviewImage() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	FSlateBrush ClipIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ammo", meta=(DisplayName="Is Consumed"))
	FScalableFloat bIsConsumed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ammo")
	bool bTriggersFeedbackLines;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Ammo")
	FScalableFloat RegenCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	FFortMultiSizeBrush AmmoIconBrush;

	UPROPERTY(EditAnywhere, Category="Display")
	uint8 bShowAmmoAsFuel : 1;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Display")
	FVector2D MobileScale;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> HUDAmmoSmallPreviewImage;

	UPROPERTY(EditDefaultsOnly, Category="Customization")
	TSubclassOf<UFortWorldItem> WorldItemClassOverride;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Customization")
	TObjectPtr<UPlaylistUserOptions> ItemOptions;

	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Creative", meta=(Patchable, ShowOnlyInnerProperties))
	FFortCreativeTagsHelper CreativeTagsHelper;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="OwnedTags")
	FGameplayTagContainer WeaponInheritedTags;

};

