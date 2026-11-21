// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "FortCreativeDeviceMeshSettings.generated.h"

class UMaterialInterface;
class UStaticMesh;

USTRUCT(BlueprintType)
struct FCreativeDeviceMeshSettings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeDeviceMeshSettings")
	TSoftObjectPtr<UStaticMesh> Mesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeDeviceMeshSettings")
	FVector Scale;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeDeviceMeshSettings")
	FGameplayTag StatTag;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="CreativeDeviceMeshSettings")
	TSoftObjectPtr<UMaterialInterface> Material;

};

