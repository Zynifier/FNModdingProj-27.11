// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "LedgeMeshComponent.h"
#include "PBWLedgeMeshComponent.generated.h"

UCLASS(HideCategories=("Object", "Activation", "Components|Activation", "Trigger"))
class UPBWLedgeMeshComponent : public ULedgeMeshComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="PBWLedgeMeshComponent")
	bool bIsFrontFace;

	UPROPERTY(EditDefaultsOnly, Category="PBWLedgeMeshComponent")
	FVector LocalOffset;

};

