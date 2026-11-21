// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortHeroNamesData.generated.h"

USTRUCT()
struct FFortHeroNamesData : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HeroNames")
	FString FirstName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HeroNames")
	FString NickName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="HeroNames")
	FString LastName;

};

