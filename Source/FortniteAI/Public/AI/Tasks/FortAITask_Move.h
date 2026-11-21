// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Tasks/AITask_MoveTo.h"
#include "FortAITask_Move.generated.h"

class AActor;
class AFortPawn;

USTRUCT()
struct FFortMoveConfig
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AActor> FocusTarget;

	UPROPERTY()
	TSubclassOf<AFortPawn> PushPawnClassOnBump;

};

UCLASS(MinimalAPI)
class UFortAITask_Move : public UAITask_MoveTo
{
	GENERATED_BODY()

public:
	FORTNITEAI_API UFortAITask_Move(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UPROPERTY()
	FFortMoveConfig MoveConfig;

};

