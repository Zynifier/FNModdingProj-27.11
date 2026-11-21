// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "EntityCoreTransformDataComponents.h"
#include "EntityActorScaleComponent.generated.h"

class USceneComponent;

UCLASS(ClassGroup=("Entity"), meta=(DisplayName="Scale Component"))
class ENTITYACTOR_API UEntityActorScaleComponent : public UEntityScaleComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRootComponentChanged(USceneComponent* InRootComponent, bool bIsRootComponent);

	UPROPERTY(EditAnywhere, Category="NoCategory", meta=(DisplayName="Scale"))
	FVector ShadowVar_Scale;

};

