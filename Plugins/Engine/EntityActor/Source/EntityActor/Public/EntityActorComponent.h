// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityComponent.h"
#include "EntityActorComponent.generated.h"

class UActorComponent;

/** Base level class for entity components which directly wrap actor components. */
UCLASS(Abstract)
class ENTITYACTOR_API UEntityActorComponent : public UEntityComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, ReplicatedUsing=OnRep_ActorComponent, Export, Category="Component", meta=(EditInline="true"))
	TObjectPtr<UActorComponent> ActorComponent;

private:
	UFUNCTION()
	void OnRep_ActorComponent();

	UPROPERTY()
	bool bCreatedActorComponent;

};

