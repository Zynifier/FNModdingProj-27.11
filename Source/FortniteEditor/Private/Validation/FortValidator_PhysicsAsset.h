// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Validation/FortEditorValidator.h"
#include "FortValidator_PhysicsAsset.generated.h"

USTRUCT()
struct FPhysicsAssetBudget
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Name;

	UPROPERTY()
	FString PathPrefix;

	UPROPERTY()
	FString PathSuffix;

	UPROPERTY()
	int32 MaxPhysicsCollisionPolyCount;

};

UCLASS(Config=Editor)
class UFortValidator_PhysicsAsset : public UFortEditorValidator
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	FPhysicsAssetBudget GlobalBudget;

	UPROPERTY(Config)
	TArray<FPhysicsAssetBudget> BudgetOverrides;

};

