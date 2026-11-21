// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CreativeMoveToolStateComponent.generated.h"

UCLASS(MinimalAPI)
class UCreativeMoveToolStateComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Replicated)
	bool bPreview;

};

