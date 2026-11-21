// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MeshCosmeticsCustomizationTypes.generated.h"

class UDefaultImageProvider;

USTRUCT()
struct FMeshCosmeticsCustomizableObjectEntry
{
	GENERATED_BODY()

};

USTRUCT()
struct FMeshCosmeticsCustomizationCCV2Data
{
	GENERATED_BODY()

};

USTRUCT()
struct FMeshCosmeticsCustomizationPerSlotData
{
	GENERATED_BODY()

};

USTRUCT()
struct MESHCOSMETICS_API FMeshCosmeticsImageProviderWrapper
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UDefaultImageProvider> ImageProvider;

};

