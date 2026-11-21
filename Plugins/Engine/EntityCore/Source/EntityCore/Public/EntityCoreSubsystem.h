// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "EntityCoreSubsystem.generated.h"

class UEntity;
class UEntityComponent;

// Make this a ustruct to get around no containers being allowed inside a TMap

USTRUCT()
struct FEntityComponentContainer
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<TObjectPtr<UEntityComponent>> Array;

};

UCLASS()
class ENTITYCORE_API UEntityCoreSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TMap<uint32, FEntityComponentContainer> ComponentMap;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UEntityComponent>> ComponentArray;

	// Private Use Only - no getters to a UEntity should be exposed. Almost all places that want a reference to UEntity should refer to an EntityID instead.

	UPROPERTY(Transient)
	TMap<uint32, TObjectPtr<UEntity>> Entities;

};

