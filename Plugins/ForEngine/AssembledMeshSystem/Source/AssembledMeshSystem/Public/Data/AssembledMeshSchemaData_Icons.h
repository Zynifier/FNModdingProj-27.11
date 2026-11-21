// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Data/AssembledMeshSchemaData.h"
#include "AssembledMeshSchemaData_Icons.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FAssembledMeshSchemaData_Icons : public FAssembledMeshSchemaData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> WidePreviewImage;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> SmallPreviewImage;

	UPROPERTY(EditDefaultsOnly, Category="Display")
	TSoftObjectPtr<UTexture2D> LargePreviewImage;

};

