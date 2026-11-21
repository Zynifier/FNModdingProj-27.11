// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/LocalPlayerSubsystem.h"
#include "ItemTagSubsystem.generated.h"

class UAthenaCosmeticItemDefinition;

USTRUCT()
struct FTagItemList
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UAthenaCosmeticItemDefinition>> ItemList;

};

UCLASS(MinimalAPI)
class UItemTagSubsystem : public ULocalPlayerSubsystem
{
	GENERATED_BODY()

};

