// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "EntityComponent.h"
#include "EntityActorLocalInputComponent.generated.h"

UCLASS(meta=(DisplayName="Input Component"))
class ENTITYACTOR_API UEntityActorLocalInputComponent : public UEntityComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TEnumAsByte<EAutoReceiveInput::Type> AutoReceiveControllerInput;

};

