// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScriptedObjectMovementDynamicPathContext.generated.h"

class IFortScriptedObjectMovement_GridProviderInterface;
class UFortScriptedObjectMovement_Slot;

USTRUCT()
struct FScriptedObjectMovement_DynamicPathContext
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortScriptedObjectMovement_Slot> SourceSlot;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortScriptedObjectMovement_Slot> DestinationSlot;

	UPROPERTY(Transient)
	TScriptInterface<IFortScriptedObjectMovement_GridProviderInterface> GridProvider;

};

