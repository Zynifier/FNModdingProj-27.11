// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "PhysicsEngine/BodyInstance.h"
#include "FortPoiCollisionComponent.generated.h"

UCLASS(HideCategories=("Mobility", "VirtualTexture", "Trigger"))
class UFortPoiCollisionComponent : public UPrimitiveComponent
{
	GENERATED_BODY()

private:
	UPROPERTY()
	FBodyInstance PoiBodyInstance;

};

