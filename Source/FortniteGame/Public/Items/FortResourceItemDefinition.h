// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingTypes.h"
#include "Creative/FortCreativeTags.h"
#include "DataAssetDirectoryPatchableAsset.h"
#include "Items/FortReplicatedStatTypes.h"
#include "Items/FortWorldItemDefinition.h"
#include "FortResourceItemDefinition.generated.h"

class UFortPersistentResourceItemDefinition;

UCLASS(MinimalAPI, BlueprintType)
class UFortResourceItemDefinition : public UFortWorldItemDefinition, public IFortCreativeTagsBearer, public IDataAssetDirectoryPatchableAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ResourceItemDefinition")
	TEnumAsByte<EFortResourceType::Type> ResourceType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Stats")
	TEnumAsByte<EFortReplicatedStat::Type> AccumulatingStatType;

private:
	UPROPERTY(EditAnywhere, AssetRegistrySearchable, Category="Creative", meta=(Patchable, ShowOnlyInnerProperties))
	FFortCreativeTagsHelper CreativeTagsHelper;

	UPROPERTY(EditAnywhere, Category="Creative", meta=(ShowOnlyInnerProperties))
	TObjectPtr<UFortPersistentResourceItemDefinition> PersistentResourceDef;

};

