// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "CustomFeedMessageContext.generated.h"

class AFortPlayerStateAthena;

USTRUCT()
struct FCustomFeedMessageContext
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TWeakObjectPtr<AFortPlayerStateAthena> OwningPlayerState;

	UPROPERTY()
	FVector OriginLocation;

};

