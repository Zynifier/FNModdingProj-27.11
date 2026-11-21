// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "AthenaSeasonTitleEntry.generated.h"

UENUM(BlueprintType)
enum class ESeasonTitleDisplayType : uint8
{
	ChapterAndSeason = 0,
	OnlySeason = 1,
	OnlyChapter = 2,
};

USTRUCT(BlueprintType)
struct FAthenaSeasonTitleEntry : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Season")
	FText DisplayChapterText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Season")
	FText DisplaySeasonText;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Season")
	ESeasonTitleDisplayType DisplayType;

};

