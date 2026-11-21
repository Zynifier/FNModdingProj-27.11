// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Math/MathFwd.h"
#include "AthenaMarkerPointer.generated.h"

class UMaterialInterface;

UCLASS()
class UAthenaMarkerPointer : public UWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetLineMeshMaterial(UMaterialInterface* Material);

	UFUNCTION(BlueprintCallable)
	void SetTargetScreenPosition(FVector2D InTargetScreenPosition);

protected:
	UPROPERTY(Transient)
	TObjectPtr<UMaterialInterface> LineMeshMaterial;

	UPROPERTY(Transient)
	FVector2D TargetScreenPosition;

};

