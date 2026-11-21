// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFeatureAction.h"
#include "Weapons/Data/FortItemWrapMappingData.h"
#include "FortGameFeatureAction_ItemWrapMappingData.generated.h"

class UFortItemWrapMappingData;

USTRUCT()
struct FItemWrapPreviewListModification
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ItemWrapPreviewListModification")
	int32 SlotIndex;

	UPROPERTY(EditAnywhere, Category="ItemWrapPreviewListModification")
	TArray<FItemWrapPreviewEntry> PreviewList;

};

UCLASS(MinimalAPI, meta=(DisplayName="Item Wrap Mapping Data"))
class UFortGameFeatureAction_ItemWrapMappingData : public UGameFeatureAction
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_ItemWrapMappingData", meta=(AssetBundles="Client, Server"))
	TSoftObjectPtr<UFortItemWrapMappingData> TargetItemWrapSlotMetadata;

	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_ItemWrapMappingData")
	TArray<FItemWrapPreviewListModification> PreviewListModifications;

};

