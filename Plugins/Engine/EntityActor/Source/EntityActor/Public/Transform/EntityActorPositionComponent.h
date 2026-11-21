// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "EntityCoreTransformDataComponents.h"
#include "EntityActorPositionComponent.generated.h"

class USceneComponent;

UCLASS(ClassGroup=("Entity"), meta=(DisplayName="Position Component"))
class ENTITYACTOR_API UEntityActorPositionComponent : public UEntityPositionComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRootComponentChanged(USceneComponent* InRootComponent, bool bIsRootComponent);

	UPROPERTY(EditAnywhere, Category="NoCategory", meta=(DisplayName="Position"))
	FVector ShadowVar_Location;

};

