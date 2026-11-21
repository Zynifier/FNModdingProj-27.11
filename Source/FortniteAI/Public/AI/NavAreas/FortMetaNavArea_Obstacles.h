// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "NavAreas/NavAreaMeta.h"
#include "FortMetaNavArea_Obstacles.generated.h"

UCLASS(Config=Game, MinimalAPI)
class UFortMetaNavArea_Obstacles : public UNavAreaMeta
{
	GENERATED_BODY()

public:
	UFortMetaNavArea_Obstacles(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(Config)
	int32 HealthThreshold;

};

