// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Building/BuildingProp.h"
#include "BuildingProp_ConversationCompatible.generated.h"

class UAthenaSpecialActorComponent;
class UWidget;

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class ABuildingProp_ConversationCompatible : public ABuildingProp
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="SpecialActor", meta=(AllowPrivateAccess="true"))
	FScalableFloat UseSpecialActorComponent;

	UPROPERTY(EditAnywhere, Category="SpecialActor", meta=(AllowPrivateAccess="true"))
	TSubclassOf<UAthenaSpecialActorComponent> SpecialActorComponentClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UWidget> CustomInteractionWidget;

};

