// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CatalogDefinition.h"
#include "FortTypes.h"
#include "FortCatalogMetaAsset.generated.h"

UCLASS()
class UFortCatalogMetaAsset : public UCatalogMetaAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCatalogMetaAsset", meta=(ShowOnlyInnerProperties))
	FFortCatalogMeta MetaInfo;

};

