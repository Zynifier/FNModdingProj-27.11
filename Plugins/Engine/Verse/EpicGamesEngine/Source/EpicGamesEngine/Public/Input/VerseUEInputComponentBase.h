// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineBaseTypes.h"
#include "Input/VerseUEInputTypes.h"
#include "Player/EntityActorPlayerComponent.h"
#include "VerseUEInputComponentBase.generated.h"

class UInputComponent;

UCLASS(Abstract)
class EPICGAMESENGINE_API UVerseUEInputComponentBase : public UEntityActorPlayerComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UInputComponent> InputComponent;

private:
	UFUNCTION(Server, Reliable, WithValidation)
	void ServerTriggerAction(const FName& ActionName, EInputEvent InputEvent);

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerTriggerAxis(const FName& AxisName, float Value);

	UPROPERTY(Replicated)
	FVerseActionMappingArray ReplicatedActionMappingArray;

	UPROPERTY(Replicated)
	FVerseAxisMappingArray ReplicatedAxisMappingArray;

	UPROPERTY(Replicated)
	FVerseInputBindingArray ReplicatedInputBindingArray;

};

