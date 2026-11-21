// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortCreativeItemTemplateProvider.h"
#include "Items/AthenaGadgetItemDefinition.h"
#include "Valkyrie/FortExposedAssetProviderInterface.h"
#include "FortCreativeGadgetItemDefinition.generated.h"

class UFortCreativeItemTemplate;
class UFortWorldItem;
class UPlaylistUserOptions;

UCLASS(BlueprintType)
class UFortCreativeGadgetItemDefinition : public UAthenaGadgetItemDefinition, public IFortCreativeItemTemplateProvider, public IFortExposedAssetProvider
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Customization")
	TObjectPtr<UPlaylistUserOptions> ItemOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Customization")
	TSubclassOf<UFortCreativeItemTemplate> ItemTemplateClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, NoClear, Category="Customization")
	TSubclassOf<UFortWorldItem> WorldClassOverride;

};

