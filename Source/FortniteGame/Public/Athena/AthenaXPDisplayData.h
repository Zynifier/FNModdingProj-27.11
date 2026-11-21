// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaXPDisplayData.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FXPDisplayData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FName XPType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FText TitleText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	FText DisplayText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Display")
	TObjectPtr<UMaterialInterface> IconMaterial;

};

