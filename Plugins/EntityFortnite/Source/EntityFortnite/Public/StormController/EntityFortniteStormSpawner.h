// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StormController/EntityFortniteStormPhase.h"
#include "EntityFortniteStormSpawner.generated.h"

class USceneComponent;

UCLASS(Abstract, BlueprintType, Blueprintable)
class ENTITYFORTNITE_API AEntityFortniteStormSpawner : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	bool Exists() const;

	UFUNCTION(BlueprintImplementableEvent)
	void Pause();

	UFUNCTION(BlueprintImplementableEvent)
	void Start(const float StartRadius, const float BoundsRadius, const TArray<FEntityFortniteStormPhase>& Phases);

	UFUNCTION(BlueprintImplementableEvent)
	void Stop();

protected:
	UPROPERTY(VisibleAnywhere, Export, Category="EntityFortniteStormSpawner", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> SceneComponent;

};

