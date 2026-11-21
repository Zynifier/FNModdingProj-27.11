// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Quests/GameFeatures/FortGameFeatureAction_MapMarkerTagsProvider.h"
#include "FortGameFeatureAction_MapMarkerTagsProvider_PatrolPath.generated.h"

class UDataTable;

UCLASS()
class UFortGameFeatureAction_MapMarkerTagsProvider_PatrolPath : public UFortGameFeatureAction_MapMarkerTagsProvider
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditAnywhere, Category="FortGameFeatureAction_MapMarkerTagsProvider_PatrolPath", meta=(RequiredAssetDataTags="RowStructure=/Script/LagerRuntime.FortAthenaLivingWorldEvent"))
	TArray<TObjectPtr<UDataTable>> LivingWorldEventTables;
#endif

};

