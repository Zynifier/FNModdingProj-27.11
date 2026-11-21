// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CreativeMoveToolOverrides.generated.h"

class UMeshComponent;
class UStaticMesh;

UINTERFACE(BlueprintType, Blueprintable)
class UCreativeMoveToolOverrides : public UInterface
{
	GENERATED_BODY()
};

class ICreativeMoveToolOverrides
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	UStaticMesh* GetCollisionStaticMesh(FVector& OutOffset) const;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	TArray<UMeshComponent*> GetMeshComponents() const;

};

