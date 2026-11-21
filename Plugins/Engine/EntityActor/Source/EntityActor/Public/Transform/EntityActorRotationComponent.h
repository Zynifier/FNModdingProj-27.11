// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "EntityCoreTransformDataComponents.h"
#include "EntityActorRotationComponent.generated.h"

class USceneComponent;

UCLASS(ClassGroup=("Entity"), meta=(DisplayName="Rotation Component"))
class ENTITYACTOR_API UEntityActorRotationComponent : public UEntityRotationComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRootComponentChanged(USceneComponent* InRootComponent, bool bIsRootComponent);

	UPROPERTY(EditAnywhere, Category="NoCategory", meta=(DisplayName="Rotation"))
	FRotator ShadowVar_Rotation;

};

