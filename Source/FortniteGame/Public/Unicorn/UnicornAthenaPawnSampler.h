// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UnicornAthenaPawnSampler.generated.h"

class AFortPawn;

UCLASS(Config=Game)
class UUnicornAthenaPawnSampler : public UActorComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void HandlePawnDBNOChanged(AFortPawn* FortPawn, bool bInIsDBNO);

	UPROPERTY(Config)
	bool bShouldListenOutToDBNOEvent;

};

