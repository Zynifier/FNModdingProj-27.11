// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "PlayspaceComponent_Logic.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class PLAYSPACESYSTEM_API UPlayspaceComponent_Logic : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UPlayspaceComponent_Logic(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

