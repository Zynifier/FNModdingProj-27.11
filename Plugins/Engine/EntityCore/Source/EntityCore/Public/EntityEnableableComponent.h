// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EntityComponent.h"
#include "EntityEnableableComponent.generated.h"

UCLASS(Abstract, meta=(DisplayName="Enableable Component"))
class ENTITYCORE_API UEntityEnableableComponent : public UEntityComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnRep_Enabled();

	UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_Enabled, Category="NoCategory")
	uint8 IsEnabled : 1;

	UPROPERTY(Transient)
	uint8 LastIsEnabled : 1;

};

