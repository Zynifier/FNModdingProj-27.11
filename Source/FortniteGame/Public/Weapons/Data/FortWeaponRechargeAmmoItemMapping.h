// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UObject/PrimaryAssetId.h"
#include "FortWeaponRechargeAmmoItemMapping.generated.h"

USTRUCT()
struct FWeaponRechargeAmmoMappingData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Weapon Recharge Ammo", meta=(Categories="Weapon.RechargeAmmo"))
	FGameplayTag TagOnPlayer;

	UPROPERTY(EditAnywhere, Category="Weapon Recharge Ammo")
	TArray<FPrimaryAssetId> WeaponIds;

};

UCLASS()
class UFortWeaponRechargeAmmoItemMapping : public UDataAsset
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Mapping", meta=(TitleProperty="FactionTag"))
	TArray<FWeaponRechargeAmmoMappingData> WeaponRechargeAmmoMappingData;

};

