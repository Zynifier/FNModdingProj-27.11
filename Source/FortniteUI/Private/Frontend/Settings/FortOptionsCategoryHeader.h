// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortOptionsCategoryHeader.generated.h"

UCLASS(BlueprintType)
class UFortOptionsCategoryHeader : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="FortOptionsCategoryHeader")
	FText DisplayText;

};

