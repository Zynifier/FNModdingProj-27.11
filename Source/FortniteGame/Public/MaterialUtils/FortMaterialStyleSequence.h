// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MaterialUtils/FortMaterialStyle.h"
#include "FortMaterialStyleSequence.generated.h"

class UFortMaterialStyle;

USTRUCT(BlueprintType)
struct FStyleSequenceElement
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="StyleSequenceElement")
	float CustomDurationOverride;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Instanced, Category="StyleSequenceElement")
	TObjectPtr<UFortMaterialStyle> Style;

};

UCLASS(BlueprintType, Blueprintable)
class UFortMaterialStyleSequence : public UFortMaterialStyle
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMaterialStyleSequence")
	TArray<FStyleSequenceElement> StyleSequence;

};

