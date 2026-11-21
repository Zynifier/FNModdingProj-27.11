// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "ScriptedObjectMovementStaticPathStepData.generated.h"

class AFortScriptedObjectMovement_MovableObjectBase;

USTRUCT(BlueprintType)
struct FScriptedObjectMovement_StaticPathStepData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="ScriptedObjectMovement_StaticPathStepData")
	FTransform StartWorldTransform;

	UPROPERTY(BlueprintReadOnly, Category="ScriptedObjectMovement_StaticPathStepData")
	FTransform EndWorldTransform;

	UPROPERTY()
	int32 MasterPathStartSplinePoint;

	UPROPERTY()
	int32 SubSplineStartPoint;

	UPROPERTY()
	float MoveAtServerTimeSecs;

	UPROPERTY(Transient)
	TObjectPtr<AFortScriptedObjectMovement_MovableObjectBase> PathTraveler;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ScriptedObjectMovement_StaticPathStepData")
	FGameplayTag MoveStyleTag;

	UPROPERTY(BlueprintReadOnly, Transient, Category="ScriptedObjectMovement_StaticPathStepData")
	bool bTeleport;

	UPROPERTY(BlueprintReadOnly, Transient, NotReplicated, Category="ScriptedObjectMovement_StaticPathStepData")
	bool bIsSkipStep;

};

