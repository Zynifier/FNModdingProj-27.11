// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ProceduralHitPoint.generated.h"

class UPrimitiveComponent;

USTRUCT(BlueprintType)
struct FProceduralHitPoint
{
	GENERATED_BODY()

public:
	/** Flag used to know if we trace was done. */
	UPROPERTY()
	bool bIsTraceDone;

	UPROPERTY(BlueprintReadOnly, Category="Procedural Hit Point")
	FVector Position;

	UPROPERTY(BlueprintReadOnly, Category="Procedural Hit Point")
	FVector Normal;

	UPROPERTY(BlueprintReadOnly, Export, Category="Procedural Hit Point")
	TWeakObjectPtr<UPrimitiveComponent> Component;

};

