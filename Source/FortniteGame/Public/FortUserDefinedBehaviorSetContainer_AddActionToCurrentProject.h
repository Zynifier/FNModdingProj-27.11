// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUserDefinedBehaviorSetContainerInterface.h"
#include "FortUserDefinedBehaviorSetContainer_AddActionToCurrentProject.generated.h"

class UGameFeatureAction;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(DisplayName="Behavior Set - Add Action to Current GFD"))
class UFortUserDefinedBehaviorSetContainer_AddActionToCurrentProject : public UFortUserDefinedBehaviorSetContainer
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Actions")
	TArray<TObjectPtr<UGameFeatureAction>> Actions;

};

