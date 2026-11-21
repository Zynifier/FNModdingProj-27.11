// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AI/Navigation/FortNavModifierComponent.h"
#include "FortPhysicsObjectNavigationComponent.generated.h"

class UFortPhysicsObjectComponent;
class UPrimitiveComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Variable", "Tags", "Cooking", "Collision", "Variable", "Tags", "Cooking", "Collision", "Activation"), meta=(BlueprintSpawnableComponent))
class UFortPhysicsObjectNavigationComponent : public UFortNavModifierComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	FORTNITEAI_API virtual void OnSleepStateChanged(UPrimitiveComponent* SimulatingComponent, bool bIsAwake);

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortPhysicsObjectComponent> PhysicsObjectComponent;

};

