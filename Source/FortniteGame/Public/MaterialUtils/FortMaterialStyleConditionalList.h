// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMaterialStyleConditionalList.generated.h"

class UFortControllerRequirement;
class UFortMaterialStyle;

UENUM()
enum class EStyleRequirementMatchPolicy : uint8
{
	RequireAll = 0,
	RequireAny = 1,
};

USTRUCT(BlueprintType)
struct FConditionalMaterialStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="ConditionalMaterialStyle")
	TObjectPtr<UFortMaterialStyle> Style;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="ConditionalMaterialStyle")
	EStyleRequirementMatchPolicy RequirementMatchPolicy;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="ConditionalMaterialStyle")
	TArray<TObjectPtr<UFortControllerRequirement>> Requirements;

};

USTRUCT(BlueprintType)
struct FPriorityOrderedConditionalStyleList
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="Styles")
	TArray<FConditionalMaterialStyle> Styles;

};

