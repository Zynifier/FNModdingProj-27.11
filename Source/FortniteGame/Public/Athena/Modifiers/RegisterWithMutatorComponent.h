// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "RegisterWithMutatorComponent.generated.h"

UCLASS(MinimalAPI, ClassGroup=("Custom"), meta=(BlueprintSpawnableComponent))
class URegisterWithMutatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void HandleAllGameplayModifiersRegistered();

protected:
	UPROPERTY(EditAnywhere, Category="RegisterWithMutatorComponent")
	FGameplayTagContainer GameplayTags;

};

UINTERFACE()
class URegisterWithMutatorComponentManager : public UInterface
{
	GENERATED_BODY()
};

class IRegisterWithMutatorComponentManager
{
	GENERATED_BODY()

};

