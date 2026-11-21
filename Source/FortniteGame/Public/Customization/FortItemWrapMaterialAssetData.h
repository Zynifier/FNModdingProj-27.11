// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetUserData.h"
#include "FortItemWrapMaterialAssetData.generated.h"

class UMaterialInstanceConstant;

UCLASS()
class UFortItemWrapMaterialAssetData : public UAssetUserData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="ItemWrap")
	TObjectPtr<UMaterialInstanceConstant> GeneratedMaterial_Vehicle_Opaque;

	UPROPERTY(VisibleAnywhere, Category="ItemWrap")
	TObjectPtr<UMaterialInstanceConstant> GeneratedMaterial_Vehicle_Masked;

	UPROPERTY(VisibleAnywhere, Category="ItemWrap")
	TObjectPtr<UMaterialInstanceConstant> GeneratedMaterial_Weapon_Opaque;

	UPROPERTY(VisibleAnywhere, Category="ItemWrap")
	TObjectPtr<UMaterialInstanceConstant> GeneratedMaterial_Character_Opaque;

};

