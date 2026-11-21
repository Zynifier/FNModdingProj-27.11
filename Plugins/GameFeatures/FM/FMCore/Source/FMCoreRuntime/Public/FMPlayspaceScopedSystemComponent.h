// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FMPlayspaceScopedSystemComponent.generated.h"

UCLASS(BlueprintType, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class UFMPlayspaceScopedSystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAddedToPlayspaceSystemManager, bool, Success);

protected:
	UPROPERTY(BlueprintAssignable)
	FOnAddedToPlayspaceSystemManager OnAddedToPlayspaceSystemManager;

};

