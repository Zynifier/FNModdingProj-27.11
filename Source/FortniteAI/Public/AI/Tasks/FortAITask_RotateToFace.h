// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Tasks/AITask.h"
#include "FortAITask_RotateToFace.generated.h"

class AActor;

UCLASS()
class UFortAITask_RotateToFace : public UAITask
{
	GENERATED_BODY()

public:
	UFortAITask_RotateToFace(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY()
	TObjectPtr<AActor> FocusTarget;

	UPROPERTY()
	FVector FocalPoint;

};

