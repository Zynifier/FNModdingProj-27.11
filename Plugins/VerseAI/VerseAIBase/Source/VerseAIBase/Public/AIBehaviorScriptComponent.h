// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUserOptionContainerComponent.h"
#include "AIBehaviorScriptComponent.generated.h"

class UAIBehaviorScript;

UCLASS(MinimalAPI, HideCategories=("Activation", "Collision", "Components", "ComponentTick", "ComponentReplication", "Navigation", "Tags", "Replication", "Variable"), SparseClassDataType=UserOptionDefinitionContainer, meta=(BlueprintSpawnableComponent))
class UAIBehaviorScriptComponent : public UFortUserOptionContainerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UAIBehaviorScript* GetBehaviorScript();

protected:
	UPROPERTY(EditAnywhere, SaveGame, Instanced, Category="UserOptions")
	TObjectPtr<UAIBehaviorScript> AIBehaviorScript;

};

