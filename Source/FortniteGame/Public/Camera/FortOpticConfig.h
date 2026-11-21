// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortOpticConfig.generated.h"

class UFortWeaponOpticDefinition;

USTRUCT(BlueprintType)
struct FFortOpticConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Optic")
	TObjectPtr<UFortWeaponOpticDefinition> OpticDefinition;

	UPROPERTY(EditAnywhere, Category="Optic", meta=(EditConditionHides="OpticDefinition != nullptr"))
	FVector OpticCenter;

	UPROPERTY(EditAnywhere, Category="Optic", meta=(EditConditionHides="OpticDefinition != nullptr"))
	FVector OpticEntrance;

	UPROPERTY(EditAnywhere, Category="Optic", meta=(EditConditionHides="OpticDefinition != nullptr"))
	float OpticRadius;

};

