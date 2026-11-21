// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Schema/MeshCosmeticsLayoutSchema.h"
#include "MeshCosmeticsVarianceCommonTypes.generated.h"

class UAthenaCosmeticItemDefinition;
class UCustomizableObject;
class UCustomizableSkeletalComponent;
class UMeshCosmeticsLayoutSchema;
class UObject;

USTRUCT()
struct FSkeletalComponentData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UMeshCosmeticsLayoutSchema> LayoutSchema;

	UPROPERTY()
	FCosmeticSlotSelector Slot;

	UPROPERTY()
	TObjectPtr<UCustomizableObject> CustomizableObject;

};

USTRUCT()
struct FMeshCosmeticsPassDataCommon
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TMap<FCosmeticSlotSelector, FCosmeticsLayoutSlot> AllSlotDataConfigs;

	UPROPERTY()
	TMap<FCosmeticSlotSelector, TObjectPtr<UMeshCosmeticsLayoutSchema>> ProvidedSlotsToSchemaData;

	UPROPERTY()
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> MeshCosmeticsItemDefs;

	UPROPERTY()
	TArray<TObjectPtr<UObject>> KeepLoadedObjects;

	UPROPERTY()
	TMap<TObjectPtr<UCustomizableSkeletalComponent>, FSkeletalComponentData> SkeletalComponentData;

};

