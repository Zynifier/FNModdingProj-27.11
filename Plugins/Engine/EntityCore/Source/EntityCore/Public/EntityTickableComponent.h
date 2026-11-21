// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "EntityEnableableComponent.h"
#include "EntityTickableComponent.generated.h"

/**
* Tick function that calls UEntityTickableComponent::Tick
* @TODO: We should replace this with one that is knowledgeable about execution and security contexts
**/
USTRUCT()
struct FEntityTickFunction : public FTickFunction
{
	GENERATED_BODY()

};

template<>
struct TStructOpsTypeTraits<FEntityTickFunction> : public TStructOpsTypeTraitsBase2<FEntityTickFunction>
{
	enum
	{
		WithCopy = false
	};
};

UCLASS()
class ENTITYCORE_API UEntityTickableComponent : public UEntityEnableableComponent
{
	GENERATED_BODY()

};

