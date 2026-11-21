// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ClientPilotComponent.h"
#include "UObject/NoExportTypes.h"
#include "FortClientPilot_Base.generated.h"

class ABuildingActor;
class ABuildingSMActor;
class AFortPawn;
class AFortPickup;
class UFortClientPilotActionBase;
class UFortClientPilotArbitraryAction;

UCLASS(Config=Game)
class UFortClientPilotActionBase : public UObject
{
	GENERATED_BODY()

};

UCLASS()
class UFortClientPilotActionConsoleCommand : public UFortClientPilotActionBase
{
	GENERATED_BODY()

};

UCLASS()
class UFortClientPilotActionInput : public UFortClientPilotActionBase
{
	GENERATED_BODY()

};

UCLASS()
class UFortClientPilotActionUIInput : public UFortClientPilotActionBase
{
	GENERATED_BODY()

};

UCLASS(Config=Game)
class UFortClientPilotArbitraryAction : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<UFortClientPilotActionBase*> ActionSteps;

};

UCLASS(Config=Game, MinimalAPI)
class UFortClientPilot_Base : public UClientPilotComponent
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TArray<UFortClientPilotArbitraryAction*> AvailableAAs;

	UPROPERTY()
	TArray<UFortClientPilotArbitraryAction*> AAQueue;

	UPROPERTY()
	TWeakObjectPtr<AFortPawn> WeakEnemyTarget;

	UPROPERTY()
	AFortPickup* PickupTarget;

	UPROPERTY()
	ABuildingActor* BuildingTarget;

	UPROPERTY()
	ABuildingSMActor* EditTarget;

};

