// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortSeasonItemDefinitionCopyUtilityLibrary.generated.h"

class UAthenaSeasonItemDefinition;
class UCatalogDefinition;

UCLASS()
class UFortSeasonItemDefinitionCopyUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static bool UpdateOfferIdsFromCatalog(UAthenaSeasonItemDefinition* SeasonDefToUpdate, const TSoftObjectPtr<UCatalogDefinition> SourceCatalogSoftPtr);

};

