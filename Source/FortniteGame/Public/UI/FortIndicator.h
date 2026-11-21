// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortIndicator.generated.h"

class AActor;

UCLASS(Abstract, MinimalAPI)
class UFortIndicator : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FVector RelativeLocation;

	UPROPERTY(Transient)
	float MaxDistance;

	UPROPERTY(Transient)
	bool bMoveWithPawnState;

	UPROPERTY(Transient)
	FName AttachedSocketName;

protected:
	UFUNCTION()
	FORTNITEGAME_API void OnParentActorEndPlay(AActor* Actor, EEndPlayReason::Type EndPlayReason);

};

