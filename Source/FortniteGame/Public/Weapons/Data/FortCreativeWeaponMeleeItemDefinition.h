// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/FortCreativeItemTemplateProvider.h"
#include "Valkyrie/FortExposedAssetProviderInterface.h"
#include "Weapons/Data/FortWeaponMeleeItemDefinition.h"
#include "FortCreativeWeaponMeleeItemDefinition.generated.h"

class UFortCreativeItemTemplate;
class UPlaylistUserOptions;

UCLASS(BlueprintType)
class UFortCreativeWeaponMeleeItemDefinition : public UFortWeaponMeleeItemDefinition, public IFortCreativeItemTemplateProvider, public IFortExposedAssetProvider
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Customization")
	TObjectPtr<UPlaylistUserOptions> ItemOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Customization")
	TSubclassOf<UFortCreativeItemTemplate> ItemTemplateClass;

};

