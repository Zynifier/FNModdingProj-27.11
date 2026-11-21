// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MotherEvents.generated.h"

USTRUCT(BlueprintType)
struct FGravyGoblinActivatable_Event
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GravyGoblinActivatable_Event")
	bool bIsActivatable;

};

USTRUCT(BlueprintType)
struct FGravyGoblinRotatable_Event
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="GravyGoblinRotatable_Event")
	bool bIsRotatable;

};

