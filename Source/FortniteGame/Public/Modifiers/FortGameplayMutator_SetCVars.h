// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modifiers/FortGameplayMutator.h"
#include "FortGameplayMutator_SetCVars.generated.h"

UENUM()
enum class ESetCVarType : uint8
{
	Numeric = 0,
	String = 1,
};

USTRUCT()
struct FSetCVarParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Data")
	FName CVarName;

	UPROPERTY(EditAnywhere, Category="Data")
	ESetCVarType Type;

	UPROPERTY(EditAnywhere, Category="Data")
	float NumberValue;

	UPROPERTY(EditAnywhere, Category="Data")
	FString StringValue;

};

UCLASS(HideCategories=("Tick", "Replication", "Actor", "LOD", "Cooking", "Mutator", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortGameplayMutator_SetCVars : public AFortGameplayMutator
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Data")
	TArray<FSetCVarParams> CVarsToSet;

	UPROPERTY(EditAnywhere, Category="Data")
	TArray<FSetCVarParams> CVarsToSet_ClientOnly;

	UPROPERTY(EditAnywhere, Category="Data")
	TArray<FSetCVarParams> CVarsToSet_ServerOnly;

	UPROPERTY(Transient)
	TArray<FSetCVarParams> CVarsToSetBack;

};

