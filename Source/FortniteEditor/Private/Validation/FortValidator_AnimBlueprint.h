// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Validation/FortEditorValidator.h"
#include "FortValidator_AnimBlueprint.generated.h"

USTRUCT()
struct FRigidBodyNodeBudget
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
	bool bAllowSynchronousSimulation;

};

UCLASS(Config=Editor)
class UFortValidator_AnimBlueprint : public UFortEditorValidator
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	FRigidBodyNodeBudget GlobalRigidBodyNodeBudget;

	UPROPERTY(Config)
	TArray<FRigidBodyNodeBudget> RigidBodyNodeBudgets;

};

