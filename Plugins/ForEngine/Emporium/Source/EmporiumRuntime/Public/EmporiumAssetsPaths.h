// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EmporiumAssetsPaths.generated.h"

class UMaterialInstanceConstant;
class UStaticMesh;

UCLASS(Config=Editor, DefaultConfig)
class EMPORIUMRUNTIME_API UEmporiumAssetsPaths : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Opaque;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Opaque_Clearcoat;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Opaque_Sheen;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Opaque_Unlit;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Translucent;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Translucent_Clearcoat;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Transmission;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Opaque_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Opaque_Clearcoat_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Opaque_Sheen_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Opaque_Unlit_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Translucent_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Translucent_Clearcoat_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Transmission_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Opaque;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Opaque_Clearcoat;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Opaque_Sheen;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Translucent;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Translucent_Clearcoat;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Transmission;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Opaque_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Opaque_Clearcoat_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Opaque_Sheen_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Translucent_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Translucent_Clearcoat_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Transmission_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> SG_MI_Foliage_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UMaterialInstanceConstant> MR_MI_Foliage_TS;

	UPROPERTY(Config)
	TSoftObjectPtr<UStaticMesh> PlaceholderSphere;

};

