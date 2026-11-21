// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "FortWeaponReticleExtensionData.generated.h"

class UUserWidget;

UCLASS(MinimalAPI)
class UFortWeaponReticleExtensionData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortWeaponReticleExtensionData")
	bool bStartHidden;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortWeaponReticleExtensionData")
	TMap<FPrimaryAssetId, TSoftClassPtr<UUserWidget>> WeaponToReticleExtensionMap;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponReticleExtensionData")
	TMap<FGameplayTag, TSoftClassPtr<UUserWidget>> TagToReticleExtensionMap;

};

