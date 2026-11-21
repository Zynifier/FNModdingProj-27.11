// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AthenaBattleMapClickHandler.generated.h"

class ABattleMapPawnLive;

UCLASS()
class UAthenaBattleMapClickHandler : public UUserWidget
{
	GENERATED_BODY()

public:
	UAthenaBattleMapClickHandler(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	UFUNCTION()
	void HandleToggledBattleMapLive(ABattleMapPawnLive* BattleMapPawn);

};

