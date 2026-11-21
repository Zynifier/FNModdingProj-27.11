// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Online/FortRuntimeOptions.h"
#include "CreativeBetaPermissionsDataAsset.generated.h"

UCLASS()
class UCreativeBetaPermissionsDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, Category="Permissions", meta=(CallInEditor="true"))
	void UpdateGeneratedCreativeBetaPermissions();

protected:
	UPROPERTY(EditAnywhere, Category="Permissions", meta=(TitleProperty="{PrimaryAssetId}{CustomPrimaryAssetId} with tags: {PermissionTagContainer}"))
	TArray<FCreativeBetaPermissionConfig> CreativeBetaPermissions;

	UPROPERTY(VisibleAnywhere, Category="Permissions", meta=(TitleProperty="{PrimaryAssetId} with tags: {PermissionTagContainer}"))
	TArray<FCreativeBetaPermissionConfig> GeneratedCreativeBetaPermissions;

};

