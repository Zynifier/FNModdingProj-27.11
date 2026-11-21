// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "PerPlatformProperties.h"
#include "ValkyrieAssetImportDefaults.h"
#include "ValkyrieFortniteAssetImportDefaults.generated.h"

UCLASS()
class VALKYRIEFORTNITEEDITOR_API UValkyrieFortniteImportDefaults_StaticMesh : public UValkyrieAssetImportDefaultsForClass
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="ValkyrieFortniteImportDefaults_StaticMesh")
	bool bAutoComputeLODScreenSize;

	UPROPERTY(EditAnywhere, Category="ValkyrieFortniteImportDefaults_StaticMesh")
	TArray<float> ScreenSizeForLODs;

	UPROPERTY(EditAnywhere, Category="ValkyrieFortniteImportDefaults_StaticMesh")
	int32 LODForCollision;

	UPROPERTY(EditAnywhere, Category="ValkyrieFortniteImportDefaults_StaticMesh")
	FName LODGroup;

	UPROPERTY(EditAnywhere, Category="ValkyrieFortniteImportDefaults_StaticMesh")
	FPerPlatformInt MinLOD;

};

UCLASS()
class VALKYRIEFORTNITEEDITOR_API UValkyrieFortniteImportDefaults_Texture : public UValkyrieAssetImportDefaultsForClass
{
	GENERATED_BODY()

};

