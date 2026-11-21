// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "ScriptedObjectMovementGrid.generated.h"

USTRUCT()
struct FScriptedObjectMovement_Grid
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="ScriptedObjectMovement_Grid")
	FVector CellSize;

};

UINTERFACE(BlueprintType, Blueprintable)
class UFortScriptedObjectMovement_GridProviderInterface : public UInterface
{
	GENERATED_BODY()
};

class IFortScriptedObjectMovement_GridProviderInterface
{
	GENERATED_BODY()

};

