// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortNamedWeightRow.generated.h"

USTRUCT()
struct FFortNamedWeightRow : public FTableRowBase
{
	GENERATED_BODY()

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="FortNamedWeightRow")
	FString NamedWeightString;
#endif

	UPROPERTY(EditDefaultsOnly, Category="FortNamedWeightRow", meta=(DataTableImportOptional))
	TMap<FString, float> NamedWeightMap;

};

