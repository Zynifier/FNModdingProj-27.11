// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Materials/MaterialInstance.h"
#include "EditorOnlyBuildingInstanceMaterialParameters.generated.h"

USTRUCT()
struct FEditorOnlyBuildingInstanceMaterialParameters
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditInstanceOnly, Category="Parameters")
	TArray<FScalarParameterValue> ScalarParams;

	UPROPERTY(EditInstanceOnly, Category="Parameters")
	TArray<FVectorParameterValue> VectorParams;

	UPROPERTY(EditInstanceOnly, Category="Parameters")
	TArray<FTextureParameterValue> TextureParams;

	UPROPERTY(EditInstanceOnly, Category="Parameters")
	TArray<FRuntimeVirtualTextureParameterValue> RTVParams;

};

