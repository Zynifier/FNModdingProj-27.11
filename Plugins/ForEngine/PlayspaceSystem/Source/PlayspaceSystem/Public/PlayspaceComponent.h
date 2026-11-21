// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "PlayspaceComponent.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class PLAYSPACESYSTEM_API UPlayspaceComponent : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	UPlayspaceComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

};

