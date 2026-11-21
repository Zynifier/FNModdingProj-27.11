// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "UObject/NoExportTypes.h"
#include "FortTournamentManager.generated.h"

class UTexture2D;

USTRUCT(BlueprintType)
struct FFortCompetitiveIdentityInfo : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCompetitiveIdentityInfo")
	FString RegionId;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCompetitiveIdentityInfo")
	FText DisplayName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCompetitiveIdentityInfo")
	TSoftObjectPtr<UTexture2D> FlagAsset;

};

UCLASS(MinimalAPI)
class UFortTournamentManager : public UObject
{
	GENERATED_BODY()

};

