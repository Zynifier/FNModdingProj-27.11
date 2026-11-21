// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortAIPawnVariant.generated.h"

class AFortAIPawn;

USTRUCT(BlueprintType)
struct FFortAIPawnVariantDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAIPawnVariantDefinition")
	TSubclassOf<AFortAIPawn> PawnClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortAIPawnStats")
	FCurveTableRowHandle VariantWeightCurve;

	UPROPERTY(Transient)
	float CurrentWeight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="RequiredTags")
	FGameplayTagQuery RequiredTagsQuery;

};

USTRUCT(BlueprintType)
struct FFortVariantSpawnPoints : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAIPawnVariant")
	int32 BudgetPoints;

};

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class UFortAIPawnVariant : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TSubclassOf<AFortAIPawn>> PawnClasses_DEPRECATED;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAIPawnVariant")
	TArray<FFortAIPawnVariantDefinition> PawnVariantDefinitions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAIPawnVariant")
	int32 MinPlayersToSpawnVariant;

private:
	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnVariant")
	FDataTableRowHandle SpawnPointValueHandle;

	UPROPERTY()
	int32 CachedSpawnPointValue;

	UPROPERTY(EditDefaultsOnly, Category="FortAIPawnVariant")
	float EncounterExpectedLifespan;

	UPROPERTY()
	int32 VersionNum;

};

