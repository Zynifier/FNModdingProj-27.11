// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPath.h"
#include "GameFeatures/FortEditorOnlyGameFeatureAction.h"
#include "FortGameFeatureAction_AddCatalog.generated.h"

UCLASS(meta=(DisplayName="Add Catalog"))
class FORTNITEGAME_API UFortGameFeatureAction_AddCatalog : public UFortEditorOnlyGameFeatureAction
{
	GENERATED_BODY()

public:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureAction_AddCatalog", meta=(LongPackageName, RelativeToGameContentDir))
	FDirectoryPath FulfillmentsPath;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortGameFeatureAction_AddCatalog", meta=(AllowedClasses="/Script/GameSubCatalogEditor.CatalogDefinition"))
	FSoftObjectPath PluginCatalog;
#endif

};

