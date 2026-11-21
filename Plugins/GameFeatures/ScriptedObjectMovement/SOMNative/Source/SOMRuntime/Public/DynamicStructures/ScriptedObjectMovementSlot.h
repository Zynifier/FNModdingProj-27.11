// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/DataAsset.h"
#include "ScriptedObjectMovementSlot.generated.h"

class AFortScriptedObjectMovement_MovableObjectBase;
class UFortScriptedObjectMovement_SlotDefinition;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Activation", "Components|Activation", "Trigger"), meta=(BlueprintSpawnableComponent))
class UFortScriptedObjectMovement_Slot : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortScriptedObjectMovement_Slot")
	TObjectPtr<UFortScriptedObjectMovement_SlotDefinition> SlotDefinition;

	UPROPERTY(EditInstanceOnly, Category="FortScriptedObjectMovement_Slot")
	int32 ObjectRemoveOrder;

	UPROPERTY(Transient)
	TObjectPtr<AFortScriptedObjectMovement_MovableObjectBase> SlottedObject;

};

UCLASS(BlueprintType, Blueprintable)
class UFortScriptedObjectMovement_SlotDefinition : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="FortScriptedObjectMovement_SlotDefinition")
	TSubclassOf<AFortScriptedObjectMovement_MovableObjectBase> ScriptedObjectClass;

	UPROPERTY(EditDefaultsOnly, Category="FortScriptedObjectMovement_SlotDefinition")
	float ObjectScale;

};

