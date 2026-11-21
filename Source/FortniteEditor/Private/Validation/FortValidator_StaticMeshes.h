// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Validation/FortEditorValidator.h"
#include "FortValidator_StaticMeshes.generated.h"

USTRUCT()
struct FStaticMeshBudget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString Path;

	UPROPERTY()
	uint32 MaxNonNaniteVertCount;

	UPROPERTY()
	float MaxNonNaniteRadius;

};

UCLASS(Config=Editor)
class UFortValidator_StaticMeshes : public UFortEditorValidator
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	FStaticMeshBudget GlobalBudget;

	UPROPERTY(Config)
	TArray<FStaticMeshBudget> ProjectSpecificBudgets;

};

