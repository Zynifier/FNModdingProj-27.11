// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/GameFrameworkComponent.h"
#include "FortActorComponent_FortInteractExtension.generated.h"

class AActor;

UCLASS(Config=Game, MinimalAPI, BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class UFortActorComponent_FortInteractExtension : public UGameFrameworkComponent
{
	GENERATED_BODY()

public:
	FORTNITEGAME_API UFortActorComponent_FortInteractExtension(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY(Replicated)
	TArray<TWeakObjectPtr<AActor>> AllowedActorsForInteraction;

};

