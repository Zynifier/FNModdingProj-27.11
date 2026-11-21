// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "VictoryCrownPlaylistData.generated.h"

USTRUCT(BlueprintType)
struct FVictoryCrownPlaylistData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="VictoryCrownPlaylistData")
	int32 MaxRankingForCrownAward;

};

